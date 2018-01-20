#ifndef SERVER_H
#define SERVER_H

#include <QtCore>
#include <QObject>
#include <QtNetwork>
#include <QtXml>
#include <QList>
#include "definitions.h"


struct Tcp_packet{
    QString sender;
    QString command;
    QString object;
    QString status;
    QString error;
    QByteArray binary;
    QDomDocument dataE;
};


class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
        void incomingConnection(int socketDescriptor);
private slots:
    void ready();
};

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server();
    bool writeData(QByteArray data, int socket_id, int xml_size=-1);
    int process_received_data(QByteArray *data, Tcp_packet &tcp_Packet, int socket_id);
    int process_data(Tcp_packet *tcp_Packet, int socket_id);
    void format_and_send_packet(QString sender, QString command, QString object, QString status, QString error, int socket_id);
    void listen(bool);
    void restart_server();
    QString listen_address();

signals:
    void dataReceived(Tcp_packet *tcp_packet, int socket_id);
    void connection_status(int); 

private slots:
    void newConnection();
    void disconnected();
    void readyRead();

private:

    MyTcpServer *server;
    QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
    QHash<QTcpSocket*, qint32*> sizes; //We need to store the size to verify if a block has received completely
    Tcp_packet tcp_packet;
    QTimer keep_alive_timer;
    QList<QTcpSocket*> clientList;
    QList<int> socket_alive;
    int web_gui_socket_id;
};

#endif // SERVER_H
