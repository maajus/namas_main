/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Living_Room_win.cpp
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#include "Living_Room_win.h"


Living_Room_win::Living_Room_win(info_widget * w):info_w(w)  {
    widget.setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    room  = new Room(ROOM_ID::LIVING_ROOM);
    //tcp_thread = new QThread();
    //tcp->connect_thread(tcp_thread);
    //tcp->moveToThread(tcp_thread);
    //tcp_thread->start();
    connect(room, SIGNAL(room_status_received(Room_status)), this, SLOT(room_status_received(Room_status)));
    
    connection_status = Status::DISCONNECTED;

    widget.lights0_button->setStyleSheet("QPushButton{background-color: #282828; border-width: 0px}");
    //widget.lights1_button->setStyleSheet("background-color: #282828; border-width: 0px");
    //widget.lights2_button->setStyleSheet("background-color: #282828; border-width: 0px");
    //widget.lights3_button->setStyleSheet("background-color: #282828; border-width: 0px");

    widget.lights0_button->setIconSize(QSize(128,128));
    widget.lights1_button->setIconSize(QSize(128,128));
    widget.lights2_button->setIconSize(QSize(128,128));
    widget.lights3_button->setIconSize(QSize(128,128));
    widget.lights4_button->setIconSize(QSize(128,128));
    widget.lights5_button->setIconSize(QSize(128,128));

}

Living_Room_win::~Living_Room_win() {
}

void Living_Room_win::on_back_button_clicked(){

    this->close();

}



void Living_Room_win::on_lights0_button_clicked(){
    this->send_tcp_cmd("L0");
    status.L[0] = !status.L[0];
    this->update_room_info();
}
void Living_Room_win::on_lights1_button_clicked(){
    this->send_tcp_cmd("L1");
    status.L[1] = !status.L[1];
    this->update_room_info();
}
void Living_Room_win::on_lights2_button_clicked(){
    this->send_tcp_cmd("L2");
    status.L[2] = !status.L[2];
    this->update_room_info();
}
void Living_Room_win::on_lights3_button_clicked(){
    this->send_tcp_cmd("L3");
    status.L[3] = !status.L[3];
    this->update_room_info();
}
void Living_Room_win::on_lights4_button_clicked(){
    this->send_tcp_cmd("L4");
    status.L[4] = !status.L[4];
    this->update_room_info();
}
void Living_Room_win::on_lights5_button_clicked(){
    this->send_tcp_cmd("L5");
    status.L[5] = !status.L[5];
    this->update_room_info();
}


void Living_Room_win::update_info(){

    this->send_tcp_cmd("A\n");
}

void Living_Room_win::send_tcp_cmd(QString cmd){

    if(connection_status != Status::FAILED)
        room->sendData(cmd.toLocal8Bit());

}

void Living_Room_win::room_status_received(Room_status room_status){

    status = room_status;
    info_w->set_room_status(status);
    this->update_room_info();

}


void Living_Room_win::update_room_info(){

        if(status.L[0]) widget.lights0_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights0_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[1]) widget.lights1_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights1_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[2]) widget.lights2_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights2_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[3]) widget.lights3_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights3_button->setIcon(QIcon(":/icons/bulb_off.png"));


    widget.temp_label->setText(status.temp);
    widget.humi_label->setText(status.humi);
    
}

void Living_Room_win::set_connection_status(int status){

    connection_status = status;
    if(status==Status::FAILED)
        info_w->setEnabled(false);

}


Room* Living_Room_win::get_room(){

    return room;

}

//void Living_Room_win::checkBox_stateChanged(int){

    //QCheckBox *box = (QCheckBox*) sender();
    //qDebug()<<box->objectName();

    //switch(box->objectName().at(1).toLatin1()){
    //case 'A':
        //qDebug()<<"AAA";
        //break;
    //}
    
//}

