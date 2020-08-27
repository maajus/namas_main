/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bed_Room_win.cpp
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#include "Bed_Room_win.h"


Bed_Room_win::Bed_Room_win() {
    //this->setAttribute(Qt::WA_DeleteOnClose);
    room  = new Room(ROOM_ID::BEDROOM);
    connect(room, SIGNAL(room_status_received(Room_status)), this, SLOT(room_status_received(Room_status)));
    connection_status = Status::DISCONNECTED;
}

Bed_Room_win::~Bed_Room_win() {
}



void Bed_Room_win::update_info(){

    this->send_tcp_cmd("A");
}

void Bed_Room_win::send_tcp_cmd(QString cmd){

    if(connection_status != Status::FAILED)
        room->sendData(cmd.toLocal8Bit());

}

void Bed_Room_win::room_status_received(Room_status room_status){

    status = room_status;

}


void Bed_Room_win::set_connection_status(int status){

    connection_status = status;

}


Room* Bed_Room_win::get_room(){

    return room;

}

