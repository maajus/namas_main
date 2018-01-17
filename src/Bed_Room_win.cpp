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


Bed_Room_win::Bed_Room_win(info_widget * w):info_w(w)  {
    widget.setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    room  = new Room(ROOM_ID::BEDROOM);
    //tcp_thread = new QThread();
    //tcp->connect_thread(tcp_thread);
    //tcp->moveToThread(tcp_thread);
    //tcp_thread->start();
    connect(room, SIGNAL(room_status_received(Room_status)), this, SLOT(room_status_received(Room_status)));
    
    connection_status = Status::DISCONNECTED;

    widget.lights0_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights1_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights2_button->setStyleSheet("background-color: #282828; border-width: 0px");

    widget.lights0_button->setIconSize(QSize(100,100));
    widget.lights1_button->setIconSize(QSize(100,100));
    widget.lights2_button->setIconSize(QSize(100,100));

}

Bed_Room_win::~Bed_Room_win() {
}

void Bed_Room_win::on_back_button_clicked(){

    this->close();

}



void Bed_Room_win::on_lights0_button_clicked(){

    this->send_tcp_cmd("L0");
    status.L[0] = !status.L[0];
    this->update_room_info();

}
void Bed_Room_win::on_lights1_button_clicked(){

    this->send_tcp_cmd("L1");
    status.L[1] = !status.L[1];
    this->update_room_info();

}
void Bed_Room_win::on_lights2_button_clicked(){

    this->send_tcp_cmd("L2");
    status.L[2] = !status.L[2];
    this->update_room_info();

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
    info_w->set_room_status(status);
    this->update_room_info();



}


void Bed_Room_win::update_room_info(){

    if(status.L[0]) widget.lights0_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights0_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[1]) widget.lights1_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights1_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[2]) widget.lights2_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights2_button->setIcon(QIcon(":/icons/bulb_off.png"));

    widget.temp_label->setText(status.temp);
    widget.humi_label->setText(status.humi);
    
}

void Bed_Room_win::set_connection_status(int status){

    connection_status = status;
    if(status==Status::FAILED)
        info_w->setEnabled(false);

}


Room* Bed_Room_win::get_room(){

    return room;

}

//void Bed_Room_win::checkBox_stateChanged(int){

    //QCheckBox *box = (QCheckBox*) sender();
    //qDebug()<<box->objectName();

    //switch(box->objectName().at(1).toLatin1()){
    //case 'A':
        //qDebug()<<"AAA";
        //break;
    //}
    
//}

