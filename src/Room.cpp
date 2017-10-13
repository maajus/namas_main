
#include "Room.h"


Room::Room(ROOM_ID id): room_id(id) {

    tcp = new TCP();
    connect(tcp, SIGNAL(dataReceived(QByteArray)), SLOT(tcp_data(QByteArray)));
    connect(tcp, SIGNAL(connected(int)), SLOT(set_connection_status(int)));
    //connection_status = Status::DISCONNECTED;
    this->ip = this->read_ip();

}


void Room::connect2module(){

    tcp->set_ip(ip);
    tcp->connect2room();


}

QString Room::read_ip(){

    switch (room_id){
    case BATHROOM:
        return "vonia";
        break;
    case CORRIDOR:
        return "koridorius";
        break;
    case BEDROOM:
        return "miegamasis";
        break;
    case WORKROOM:
        return "vaikuKambarys";
        break;
    case LIVING_ROOM:
        return "svetaine";
        break;
    }
    return "";
            
}

void Room::sendData(QByteArray data){

    if(connection_status != Status::FAILED)
    tcp->sendData(data);

}


void Room::tcp_data(QByteArray data){

    switch(data.at(0)){
        case 'A':
        {
                QStringList info = QString(data.mid(1,data.length())).split("_");
                if(info.size()<=1) return;
                status.temp = (info[0] + "°C"); 
                status.humi = (info[1] + "%");
                status.L[0] = info[2].toInt();
                status.L[1] = info[3].toInt();
                status.L[2] = info[4].toInt();
                status.L[3] = info[5].toInt();
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

void Room::set_connection_status(int Status){

    connection_status = Status;
    status.connected = connection_status;
    emit room_status_received(status);

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
