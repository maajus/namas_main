/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Work_Room_win.cpp
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#include "Work_Room_win.h"


Work_Room_win::Work_Room_win(info_widget * w):info_w(w)  {
    widget.setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    room  = new Room(ROOM_ID::WORKROOM);
    //tcp_thread = new QThread();
    //tcp->connect_thread(tcp_thread);
    //tcp->moveToThread(tcp_thread);
    //tcp_thread->start();
    connect(room, SIGNAL(room_status_received(Room_status)), this, SLOT(room_status_received(Room_status)));
    
 
    connection_status = Status::DISCONNECTED;

    widget.lights0_button->setStyleSheet("background-color: #282828; border-width: 0px");

    widget.lights0_button->setIconSize(QSize(128,128));

}

Work_Room_win::~Work_Room_win() {
}

void Work_Room_win::on_back_button_clicked(){

    this->close();

}



void Work_Room_win::on_lights0_button_clicked(){

    this->send_tcp_cmd("L1");
    status.L[0] = !status.L[0];
    this->update_room_info();

}

void Work_Room_win::update_info(){

    this->send_tcp_cmd("A");
}

void Work_Room_win::send_tcp_cmd(QString cmd){

    if(connection_status != Status::FAILED)
        room->sendData(cmd.toLocal8Bit());

}

void Work_Room_win::room_status_received(Room_status room_status){


    status = room_status;
    info_w->set_room_status(status);
    this->update_room_info();



}


void Work_Room_win::update_room_info(){

    if(status.L[0]) widget.lights0_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights0_button->setIcon(QIcon(":/icons/bulb_off.png"));

    widget.temp_label->setText(status.temp);
    widget.humi_label->setText(status.humi);
    
}

void Work_Room_win::set_connection_status(int status){

    connection_status = status;
    if(status==Status::FAILED)
        info_w->setEnabled(false);

}


Room* Work_Room_win::get_room(){

    return room;

}

