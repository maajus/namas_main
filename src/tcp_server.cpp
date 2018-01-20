#include "tcp_server.h"
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include "Config.h"
//#include "Version.h"


#define KEEP_ALIVE_TIMEOUT 15000
//#define SSL_SERVER


static inline qint32 ArrayToInt(QByteArray source);
static inline QByteArray IntToArray(qint32 source);

Server::Server() {

    web_gui_socket_id = -1;
    this->listen(true);
}



void Server::listen(bool start){

    if(start){

        server = new MyTcpServer();
        server->setMaxPendingConnections(2);

        connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
        if (!server->listen(QHostAddress::Any, TCP_SERVER_PORT)) {
            qDebug() << "Server could not start";
        }
        //else qDebug() << "Listening...";
        //Timer is restarted if data is received. If no data for KEEP_ALIVE_TIMEOUT socket is closed
        //connect(&keep_alive_timer, SIGNAL(timeout()), this, SLOT(keep_alive_timeout()));
        //keep_alive_timer.start(KEEP_ALIVE_TIMEOUT);
    }
    else{
        server->close();
        delete server;
    }

}


void Server::restart_server(){

    this->listen(false);
    this->listen(true);

}

qint32 ArrayToInt(QByteArray source) {
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadOnly);
    data >> temp;
    return temp;
}

QByteArray IntToArray(qint32 source) //Use qint32 to ensure that the number have 4 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::WriteOnly);
    data << source;
    return temp;
}

QString Server::listen_address(){

    return server->serverAddress().toString();

}

void Server::newConnection() {


    while (server->hasPendingConnections()) {

        QSslSocket *socket = (QSslSocket *)server->nextPendingConnection();
        clientList.append(socket);

        int socket_id = clientList.indexOf(socket);
        if (socket_id < 0){
            qDebug()<<"[TCP] Socket not found";
            return;
        }

        QByteArray hello = "Namas\n";

        //local http server connection

            web_gui_socket_id = socket_id;

            writeData(hello, socket_id);


            emit connection_status(1);
            qDebug() << "[TCP] Connected: " << socket->peerAddress().toString();

        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));


        QByteArray *buffer = new QByteArray();
        qint32 *s = new qint32(0);

        buffers.insert(socket, buffer);
        sizes.insert(socket, s);

    }
}


void Server::disconnected() {

    QTcpSocket *soc = static_cast<QTcpSocket*> (sender());
    qDebug()<<"[TCP] disconnected "<< soc->peerAddress().toString();
    //remote connection

    emit connection_status(0);

    int idx = -1;
    if(clientList.count() > 0){
        idx = clientList.indexOf(soc);
        if (idx!=-1)
            clientList.removeAt(idx);
    }

    soc->deleteLater();

}

void Server::readyRead() {

    //restart timer if data available
    QSslSocket *soc = static_cast<QSslSocket*> (sender());

    if(clientList.count() <= 0)
        return;
    int socket_id = clientList.indexOf(soc);
    if (socket_id < 0){
        qDebug()<<"[TCP] Failed to read socket";
        return;
    }

    socket_alive.removeOne(socket_id);
    socket_alive.append(socket_id);

    //if(soc->peerAddress() != QHostAddress("127.0.0.1"))
    //keep_alive_timer.start(KEEP_ALIVE_TIMEOUT);

    QByteArray *buffer = buffers.value(soc);
    qint32 *s = sizes.value(soc);
    qint32 size = *s;


    while (soc->bytesAvailable() > 0) {
        buffer->append(soc->readAll());
        while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
        {
            if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it on our global variable
            {
                size = ArrayToInt(buffer->mid(0, 4));
                *s = size;
                buffer->remove(0, 4);
                //qDebug()<<"Data size :"<<size;
            }
            //qDebug()<<"Waiting Data "<<buffer->size();
            if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
            {
                QByteArray data = buffer->mid(0, size);
                buffer->remove(0, size);
                size = 0;
                *s = size;
                //qDebug()<<"Data received";


                if (this->process_received_data(&data, tcp_packet, socket_id)) {
                    //qDebug()<<"Processing tcp packet failed";
                    return;
                }

                //qDebug().noquote()<<data;
                emit dataReceived(&tcp_packet, socket_id);
            }
        }
    }

}

bool Server::writeData(QByteArray data, int socket_id, int xml_size) {

    if(clientList.count() <= 0)
        return false;

    QSslSocket *socket = (QSslSocket*) clientList.at(socket_id);


    if (socket->state() == QAbstractSocket::ConnectedState) {
       socket->write(IntToArray(data.size())); //write size of data
       if(xml_size > 0)
           socket->write(IntToArray(xml_size)); //write size of data
       else
           socket->write(IntToArray(data.size())); //write size of data

        socket->write(data); //write the data itself
        return socket->waitForBytesWritten(100);

    } else
        return false;
}

int Server::process_received_data(QByteArray *data, Tcp_packet &tcp_Packet, int socket_id) {

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomElement data1;

    //create domdocument from received data
    QDomDocument document;


    if (!document.setContent(*data, false, &errorStr, &errorLine, &errorColumn)) {
        qDebug() << QString("Process received packet XML parsing error in  L:" 
                + QString::number(errorLine) + " C:" + QString::number(errorColumn) + "\n");
        //create error packet
        this->format_and_send_packet("Rx", QString("Response"), "", "Error",
                QString("XML parsing error in  L:" + QString::number(errorLine) +
                    " C:" + QString::number(errorColumn)), socket_id);
        return 1;
    }

    //parse xml to tcp_packet structure
    QDomElement root = document.firstChildElement();
    if (root.tagName() == "TCPpacket") {
        //tcp_Packet.sender = root.firstChildElement("Sender").text();
        tcp_Packet.command = root.firstChildElement("Command").text();
        tcp_Packet.object = root.firstChildElement("Object").text();
        //tcp_Packet.status = root.firstChildElement("Status").text();
        //tcp_Packet.error = root.firstChildElement("Error").text();
        //tcp_Packet.data = root.firstChildElement("Data").text();
        data1 = root.firstChildElement("Data").firstChildElement();

        //check if data was sent
        if (!data1.isNull()) {
            QString str;
            QTextStream data_stream(&str);
            data1.save(data_stream, QDomNode::CDATASectionNode /* = 4 */);

            if (!tcp_Packet.dataE.setContent(str, false, &errorStr, &errorLine, &errorColumn)) {
                qDebug() << QString("Process received data XML parsing error in  L:" 
                        + QString::number(errorLine) + " C:" + QString::number(errorColumn) + "\n");
            }
        }
    } else {
        qDebug() << "[TCP] Unknown packet " << root.tagName();
        this->format_and_send_packet("Rx", "Response", "", "Error", "Unknown Packet", socket_id);
        return 1;
    }

    return 0;
}




int Server::process_data(Tcp_packet *tcp_Packet, int socket_id) {

    //qDebug()<<tcp_Packet->dataE.toString();

    QDomDocument dom_document;

    //add header
//    QDomNode node(dom_document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\""));
//   dom_document.insertBefore(node, dom_document.firstChild());

    QDomElement root = dom_document.createElement("TCPpacket");
    dom_document.appendChild(root);

    //add actual packet
    QDomElement element;
    QDomText text_node;

    //packet sender
    element = dom_document.createElement("Sender");
    text_node = dom_document.createTextNode(tcp_Packet->sender);
    element.appendChild(text_node);
    root.appendChild(element);

    //packet Command
    element = dom_document.createElement("Command");
    text_node = dom_document.createTextNode(tcp_Packet->command);
    element.appendChild(text_node);
    root.appendChild(element);

    //packet Object
    element = dom_document.createElement("Object");
    text_node = dom_document.createTextNode(tcp_Packet->object);
    element.appendChild(text_node);
    root.appendChild(element);

    //packet Status
    element = dom_document.createElement("Status");
    text_node = dom_document.createTextNode(tcp_Packet->status);
    element.appendChild(text_node);
    root.appendChild(element);

    //packet Error
    element = dom_document.createElement("Error");
    text_node = dom_document.createTextNode(tcp_Packet->error);
    element.appendChild(text_node);
    root.appendChild(element);


    element = dom_document.createElement("Data");
    element.appendChild(tcp_Packet->dataE);
    root.appendChild(element);


    QByteArray data = dom_document.toString().toUtf8();

    int xml_size = data.size();

    //add binnary data tail to xml if needed
    if (tcp_Packet->binary.size() > 0)
        data.append(tcp_Packet->binary);


    this->writeData(data, socket_id, xml_size);
    return 0;
}

void Server::format_and_send_packet(QString sender, QString command, QString object, QString status, QString error, int socket_id) {

    Tcp_packet * tcp_packet = new Tcp_packet;
    tcp_packet->sender = sender;
    tcp_packet->command = command;
    tcp_packet->object = object;
    tcp_packet->status = status;
    tcp_packet->error = error;
    this->process_data(tcp_packet, socket_id);
    delete tcp_packet;
}



void MyTcpServer::incomingConnection(int socketDescriptor) {

    QSslSocket *socket = new QSslSocket();
    if (socket->setSocketDescriptor(socketDescriptor)) {

        addPendingConnection(socket);
        emit newConnection();

    }
    else {
        delete socket;
    }
}

void MyTcpServer::ready()
{
    QSslSocket *socket = (QSslSocket *) sender();
    addPendingConnection(socket);
    emit newConnection();
}

