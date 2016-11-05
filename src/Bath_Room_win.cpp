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
    connect(tcp, SIGNAL(connection_failed(QAbstractSocket::SocketError)), SLOT(connection_failed(QAbstractSocket::SocketError)));

    memset(&lights, 0, sizeof(Lights));
    widget.lights0_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights1_button->setStyleSheet("background-color: #282828; border-width: 0px");
    widget.lights2_button->setStyleSheet("background-color: #282828; border-width: 0px");

    widget.lights0_button->setIconSize(QSize(128,128));
    widget.lights1_button->setIconSize(QSize(128,128));
    widget.lights2_button->setIconSize(QSize(128,128));

    this->update_lights_state();
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

    tcp->sendData("L0");

}
void Bath_Room_win::on_lights1_button_clicked(){

    tcp->sendData("L1");

}
void Bath_Room_win::on_lights2_button_clicked(){

    tcp->sendData("L2");

}
void Bath_Room_win::update_info(){

    tcp->sendData("A");
}



void Bath_Room_win::tcp_data(QByteArray data){

    switch(data.at(0)){
        case 'A':
        {
                QStringList info = QString(data.mid(1,data.length())).split("_");
                if(info.size()<=1) return;
                //qDebug()<<"Temp "<<info[0];
                info_w->set_temp(info[0] + " C");
                //qDebug()<<"Humidity "<<info[1];
                info_w->set_humi(info[1] + "%");
                lights.L[0] = info[2].toInt();
                lights.L[1] = info[3].toInt();
                lights.L[2] = info[4].toInt();
                lights.L[3] = info[5].toInt();
                this->update_lights_state();
                break;
        }
        case 'L':
            lights.L[data.at(1)-48] = data.at(2)-48; 
            this->update_lights_state();
           break;
    }
}

void Bath_Room_win::update_lights_state(){

        if(lights.L[0]) widget.lights0_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights0_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(lights.L[1]) widget.lights1_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights1_button->setIcon(QIcon(":/icons/bulb_off.png"));

    if(lights.L[2]) widget.lights2_button->setIcon(QIcon(":/icons/bulb_on.png"));
    else widget.lights2_button->setIcon(QIcon(":/icons/bulb_off.png"));
    this->repaint();

}

void Bath_Room_win::connection_failed(QAbstractSocket::SocketError error){

    qDebug()<<"Connection failed :"<<error;

}


