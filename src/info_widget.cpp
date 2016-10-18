/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   info_widget.cpp
 * Author: justas
 *
 * Created on September 4, 2016, 2:45 PM
 */

#include "info_widget.h"
#include <QPainter>
#include <QThread>

info_widget::info_widget(QWidget *parent) :
QWidget(parent)
{
    widget.setupUi(this);
    //widget.frame->setStyleSheet("background-color:#2D2D2D; border:1px solid white; border-radius:5px;");
    room_win = new Room_win();
    connect(room_win, SIGNAL(cmd2EPS(QByteArray)), this, SLOT(cmd2EPS(QByteArray)));

    
}

info_widget::~info_widget() {
}

void info_widget::set_id(ROOM_ID Id){
    
    
    tcp = new TCP(Id);
    //tcp_thread = new QThread();
    //tcp->connect2room(id,data,tcp_thread);
    //tcp->moveToThread(tcp_thread);
    //tcp_thread->start();
    //tcp->connectTcp(0, "A");
    connect(tcp, SIGNAL(dataReceived(QByteArray)), SLOT(tcp_data(QByteArray)));
    connect(tcp, SIGNAL(connection_failed(QAbstractSocket::SocketError)), SLOT(connection_failed(QAbstractSocket::SocketError)));
    
    
    id = Id;
    switch(id){
        case ROOM_ID::BEDROOM_1:
            widget.name_label->setText("Miegamasis");
            this->setStyleSheet("background-color: blue");
            break;
        case ROOM_ID::KITCHEN:
            widget.name_label->setText("Virtuvė");
            this->setStyleSheet("background-color: red");
            break;
        case ROOM_ID::LIVING_ROOM:
            widget.name_label->setText("Salionas");
            this->setStyleSheet("background-color: green");
            break;
        case ROOM_ID::BEDROOM_2:
            widget.name_label->setText("Miegamasis 2");
            this->setStyleSheet("background-color: orange");
            break;
        case ROOM_ID::WC:
            widget.name_label->setText("Vonia");
            this->setStyleSheet("background-color: brown");
            break;
    }
}



void info_widget::update_info(){
    
    this->cmd2EPS("A");
}

void info_widget::cmd2EPS(QByteArray data){
    

    tcp->sendData(data);
    
}

void info_widget::tcp_data(QByteArray data){
    
    switch(data.at(0)){
        case 'A':
        {
                QStringList info = QString(data.mid(1,data.length())).split("_");
                qDebug()<<"Temp "<<info[0];
                widget.temp_label->setText(info[0] + " C");
                qDebug()<<"Humidity "<<info[1];
                widget.humidity_label->setText(info[1] + "%");
                break;
        }
        case 'L':
            qDebug()<<data;
            break;
            
    }
    

}

void info_widget::connection_failed(QAbstractSocket::SocketError error){
    
    qDebug()<<"Connection failed :"<<error;
    
}

void info_widget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void info_widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        room_win->show();
    }
}