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


Bath_Room_win::Bath_Room_win(info_widget * w):info_w(w)  {
    widget.setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    tcp = new TCP(WC);
    connect(tcp, SIGNAL(dataReceived(QByteArray)), SLOT(tcp_data(QByteArray)));
    connect(tcp, SIGNAL(connected(int)), SLOT(set_connection_status(int)));
    connection_status = Status::DISCONNECTED;

    widget.lights0_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights1_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights2_button->setStyleSheet("background-color: #282828; border-width: 0px");

    widget.lights0_button->setIconSize(QSize(128,128));
    widget.lights1_button->setIconSize(QSize(128,128));
    widget.lights2_button->setIconSize(QSize(128,128));

}

Bath_Room_win::~Bath_Room_win() {
}

void Bath_Room_win::on_back_button_clicked(){

    this->close();

}

void Bath_Room_win::set_id(ROOM_ID ID){

    room_id = ID;

}

void Bath_Room_win::on_lights0_button_clicked(){

    this->send_tcp_cmd("L0");

}
void Bath_Room_win::on_lights1_button_clicked(){

    this->send_tcp_cmd("L1");

}
void Bath_Room_win::on_lights2_button_clicked(){

    this->send_tcp_cmd("L2");

}
void Bath_Room_win::update_info(){

    this->send_tcp_cmd("A");
}

void Bath_Room_win::send_tcp_cmd(QString cmd){

    if(connection_status != Status::FAILED)
        tcp->sendData(cmd.toLocal8Bit());

}

void Bath_Room_win::tcp_data(QByteArray data){

    switch(data.at(0)){
        case 'A':
        {
                QStringList info = QString(data.mid(1,data.length())).split("_");
                if(info.size()<=1) return;
                status.temp = (info[0] + " C");
                status.humi = (info[1] + "%");
                status.L[0] = info[2].toInt();
                status.L[1] = info[3].toInt();
                status.L[2] = info[4].toInt();
                status.L[3] = info[5].toInt();
                info_w->set_room_status(status);
                this->update_room_info();
                break;
        }
        case 'L':
            status.L[data.at(1)-48] = data.at(2)-48; 
            this->update_room_info();
           break;
    }
}

void Bath_Room_win::update_room_info(){

        if(status.L[0]) widget.lights0_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights0_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[1]) widget.lights1_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights1_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(status.L[2]) widget.lights2_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights2_button->setIcon(QIcon(":/icons/bulb_off.png"));

    widget.temp_label->setText(status.temp);
    widget.humi_label->setText(status.humi);
    
}

void Bath_Room_win::set_connection_status(int status){

    connection_status = status;
    if(status==Status::FAILED)
        info_w->setEnabled(false);

}


