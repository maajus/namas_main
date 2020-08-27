
#include "Room.h"
#include "Config.h"
#include <QTimer>



Room::Room(ROOM_ID id){

    room_id = id;
    tcp = new TCP();
    logger = new DataLogger(room_id);
    connect(tcp, SIGNAL(dataReceived(QByteArray)), SLOT(tcp_data(QByteArray)));
    connect(tcp, SIGNAL(connected(int)), SLOT(set_connection_status(int)));
    //connection_status = Status::DISCONNECTED;
    this->ip = this->read_ip();
    this->connect2module();
    reconnect_timer = new QTimer();
    reconnect_timer->setSingleShot(true);
    connect(reconnect_timer, SIGNAL(timeout()), this, SLOT(connect2module()));

}


void Room::connect2module(){

    tcp->set_ip(ip);
    tcp->connect2room();

}

QString Room::read_ip(){

    switch (room_id){
    case BATHROOM:
        return IP_VONIA;
        break;
    case CORRIDOR:
        return IP_KORIDORIUS;
        break;
    case BEDROOM:
        return IP_MIEGAMASIS;
        break;
    case WORKROOM:
        return IP_VAIKUKAMBARYS;
        break;
    case LIVING_ROOM:
        return IP_SVETAINE;
        break;
    }
    return "";

}



void Room::sendData(QString data){

    if(connection_status != Status::FAILED)
    tcp->sendData(data.toLocal8Bit());
}

//void Room::sendData(QByteArray data){

    //if(connection_status != Status::FAILED)
    //tcp->sendData(data);

/*}*/

void Room::update_info(){
    this->sendData("A");
}

void Room::tcp_data(QByteArray data){

    //if(room_id==LIVING_ROOM)
        //qDebug()<<QString(data);
    switch(data.at(0)){
        case 'A':
        {
                QStringList info = QString(data.mid(1,data.length())).split("_");
                if(info.size()<=1) return;
                status.T = (int)info[0].toFloat();
                //if((status.T > 0) && (status.T < 100))
                    status.temp = (info[0]/* + "°C"*/);

                status.H = (int)info[1].toFloat();
                //if((status.H > 0) && (status.H < 100))
                    status.humi = (info[1]/* + "%"*/);

                //qDebug()<<status.T<<status.H;

                status.L[0] = info[2].toInt();
                status.L[1] = info[3].toInt();
                status.L[2] = info[4].toInt();
                status.L[3] = info[5].toInt();
                status.connected = connection_status;
                logger->data(status);

                emit room_status_received(status);
                break;
        }
        case 'S':
        {
                QStringList info = QString(data.mid(1,data.length())).split("_");
                if(info.size()<=1) return;
                status.T = (int)info[0].toFloat();
                status.H = (int)info[1].toFloat();
                status.temp = (info[0]/* + "°C"*/);
                status.humi = (info[1]/* + "%"*/);
                status.L[0] = info[2].toInt()&0x01;
                status.L[1] = (info[2].toInt()>>1)&0x01;
                status.L[2] = (info[2].toInt()>>2)&0x01;
                status.L[3] = (info[2].toInt()>>3)&0x01;
                status.L[4] = (info[2].toInt()>>4)&0x01;
                status.L[5] = (info[2].toInt()>>5)&0x01;
                status.L[6] = (info[2].toInt()>>6)&0x01;
                status.L[7] = (info[2].toInt()>>7)&0x01;
                status.connected = connection_status;

                emit room_status_received(status);
                break;
        }


        case 'L':
            //status.L[data.at(1)-48] = data.at(2)-48;
            //emit room_status_received(status);
           break;
    }
}

void Room::set_connection_status(int newStatus){

    connection_status = newStatus;
    status.connected = connection_status;
    //emit room_status_received(status);
    if(status.connected == Status::FAILED){
        qDebug()<<"[ROOM] Will try to reconnect to"<<ip<<"after"<<RECONNECT_TIMEOUT/1000<<"secs";
        reconnect_timer->start(RECONNECT_TIMEOUT);
    }

}

Room_status Room::get_status(){
    return status;
}


void Room::toggle_light(int nr){

    tcp->sendData(("L"+QString::number(nr)).toLocal8Bit());
    status.L[nr] = !status.L[nr];
    tcp->sendData("A");

}

void Room::toggle_all_lights(){

    tcp->sendData("K");

}

void Room::switch_all_lights(bool enable){

    QByteArray cmd = "J";
    if(enable)
        cmd.append("1");
    else
        cmd.append("0");

    tcp->sendData(cmd);

}

nlohmann::json Room::status2json(){

    std::string name;
    nlohmann::json j;
    nlohmann::json lights = nlohmann::json::array();


    switch (room_id){
    case BATHROOM:
        j["name"] = "Vonia";
        lights = nlohmann::json::array({
                {{"idx",0},{"name","Lubos"},{"value",status.L[0]},{"light", true}},
                {{"idx",1},{"name","LED"},{"value",status.L[1]},{"light", true}},
                {{"idx",2},{"name","Ventiliacija"},{"value",status.L[2]},{"light", false}},
                {{"idx",3},{"name","Veidrodis"},{"value",status.L[3]},{"light", false}}
                });
        break;
    case CORRIDOR:
        j["name"] = "Koridorius";
        lights = nlohmann::json::array({
                {{"idx",0},{"name","Sandeliukas"},{"value",status.L[0]},{"light", true}},
                {{"idx",1},{"name","Koridorius"},{"value",status.L[1]},{"light", true}},
                {{"idx",2},{"name","Prie dūrų"},{"value",status.L[2]},{"light", true}}
                });
        break;
    case BEDROOM:
        j["name"] = "Miegamasis";
        lights = nlohmann::json::array({
                {{"idx",0},{"name","Simos pusė"},{"value",status.L[0]},{"light", true}},
                {{"idx",1},{"name","Lubos"},{"value",status.L[1]},{"light", true}},
                {{"idx",2},{"name","Justo pusė"},{"value",status.L[2]},{"light", true}}
                });
        break;
    case WORKROOM:
        j["name"] = "Vaikų kambarys";
        lights = nlohmann::json::array({
                {{"idx",1},{"name","Lubos"},{"value",status.L[1]},{"light", true}},
                });
        break;
    case LIVING_ROOM:
        j["name"] = "Svetainė";
        lights = nlohmann::json::array({
                {{"idx",0},{"name","LED Virtuvė"},{"value",status.L[0]},{"light", true}},
                {{"idx",1},{"name","Lubos Virtuvė"},{"value",status.L[1]},{"light", true}},
                {{"idx",2},{"name","Lubos"},{"value",status.L[2]},{"light", true}},
                {{"idx",3},{"name","Ventiliacija"},{"value",status.L[3]},{"light", false}},
                {{"idx",4},{"name","Stalas"},{"value",status.L[4]},{"light", true}},
                {{"idx",5},{"name","Karnyzas"},{"value",status.L[5]},{"light", true}},
                {{"idx",7},{"name","LED Lubos"},{"value",status.L[7]},{"light", true}}
                });
        break;
    }

    j["connected"] = status.connected;
    j["room_id"] = room_id;
    j["temp"] = status.temp.toStdString();
    j["humi"] = status.humi.toStdString();
    j["lights"] = lights;

    return j;

}

void Room::status2xml(QDomDocument *domdoc){

    QDomElement element,  root;

    switch (room_id){
    case BATHROOM:
        root = domdoc->createElement("bathroom");
        break;
    case CORRIDOR:
        root = domdoc->createElement("corridor");
        break;
    case BEDROOM:
        root = domdoc->createElement("bedroom");
        break;
    case WORKROOM:
        root = domdoc->createElement("workroom");
        break;
    case LIVING_ROOM:
        root = domdoc->createElement("livingroom");
        break;
    }

    for(int i = 0; i < 8; i++){

        element = domdoc->createElement("L"+QString::number(i));
        element.appendChild(domdoc->createTextNode(QString::number(status.L[i])));
        root.appendChild(element);

    }

    element = domdoc->createElement("H");
    element.appendChild(domdoc->createTextNode(QString::number(status.H)));
    root.appendChild(element);

    element = domdoc->createElement("T");
    element.appendChild(domdoc->createTextNode(QString::number(status.T)));
    root.appendChild(element);

    QDomElement root1 = domdoc->firstChildElement("Status");

    root1.appendChild(root);
    domdoc->appendChild(root1);
}


