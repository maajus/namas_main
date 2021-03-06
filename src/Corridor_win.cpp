/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Corridor_win.cpp
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */
#include "Corridor_win.h"


Corridor_win::Corridor_win(info_widget * w):info_w(w)  {
    widget.setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    room  = new Room(ROOM_ID::CORRIDOR);
    //tcp_thread = new QThread();
    //tcp->connect_thread(tcp_thread);
    //tcp->moveToThread(tcp_thread);
    //tcp_thread->start();
    connect(room, SIGNAL(room_status_received(Room_status)), this, SLOT(room_status_received(Room_status)));
    
    connection_status = Status::DISCONNECTED;

    widget.lights0_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights1_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights2_button->setStyleSheet("background-color: #282828; border-width: 0px");

    widget.lights0_button->setIconSize(QSize(128,128));
    widget.lights1_button->setIconSize(QSize(128,128));
    widget.lights2_button->setIconSize(QSize(210,210));

}

Corridor_win::~Corridor_win() {
}

void Corridor_win::on_back_button_clicked(){

    this->close();

}


void Corridor_win::on_lights2_button_clicked(){

    this->send_tcp_cmd("L0");
    status.L[0] = !status.L[0];
    this->update_room_info();

}
void Corridor_win::on_lights1_button_clicked(){

    this->send_tcp_cmd("L2");
    status.L[2] = !status.L[2];
    this->update_room_info();

}
void Corridor_win::on_lights0_button_clicked(){

    this->send_tcp_cmd("L1");
    status.L[1] = !status.L[1];
    this->update_room_info();

}
void Corridor_win::update_info(){

    this->send_tcp_cmd("A");
}

void Corridor_win::send_tcp_cmd(QString cmd){

    if(connection_status != Status::FAILED)
        room->sendData(cmd.toLocal8Bit());

}

void Corridor_win::room_status_received(Room_status room_status){


    status = room_status;
    info_w->set_room_status(status);
    this->update_room_info();



}


void Corridor_win::update_room_info(){

    if(status.L[0]) 
        widget.lights2_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else 
        widget.lights2_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[2]) 
        widget.lights1_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else 
        widget.lights1_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[1]) 
        widget.lights0_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else 
        widget.lights0_button->setIcon(QIcon(":/icons/bulb_off.png"));

    widget.temp_label->setText(status.temp);
    widget.humi_label->setText(status.humi);
    
}

void Corridor_win::set_connection_status(int status){

    connection_status = status;
    if(status==Status::FAILED)
        info_w->setEnabled(false);

}


Room* Corridor_win::get_room(){

    return room;

}

Room_status Corridor_win::GetStatus(){
    return status;

}

void Corridor_win::status_xml(QDomDocument *domdoc){

    room->status2xml(domdoc);

}

//void Corridor_win::checkBox_stateChanged(int){

    //QCheckBox *box = (QCheckBox*) sender();
    //qDebug()<<box->objectName();

    //switch(box->objectName().at(1).toLatin1()){
    //case 'A':
        //qDebug()<<"AAA";
        //break;
    //}
    
//}

