/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bath_Room_win.cpp
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#include "Bath_Room_win.h"


Bath_Room_win::Bath_Room_win() {

    room  = new Room(ROOM_ID::BATHROOM);
    connect(room, SIGNAL(room_status_received(Room_status)), this, SLOT(room_status_received(Room_status)));
    connection_status = Status::DISCONNECTED;
}

Bath_Room_win::~Bath_Room_win() {
}


void Bath_Room_win::update_info(){

    this->send_tcp_cmd("A");
}

void Bath_Room_win::send_tcp_cmd(QString cmd){

    if(connection_status != Status::FAILED)
        room->sendData(cmd.toLocal8Bit());

}

void Bath_Room_win::room_status_received(Room_status room_status){


    status = room_status;

    //turn on mirror if it is off, lights are on and humi is high
    if(!status.L[3] && status.L[0] && (status.H > 80))
        this->send_tcp_cmd("L3");

}


void Bath_Room_win::set_connection_status(int status){

    connection_status = status;
}


Room* Bath_Room_win::get_room(){

    return room;

}

