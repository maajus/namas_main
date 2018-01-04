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
#include <QGraphicsDropShadowEffect>

info_widget::info_widget(QWidget *parent) :
    QWidget(parent)
{
    widget.setupUi(this);
    //widget.frame->setStyleSheet("background-color:#2D2D2D; border:1px solid white; border-radius:5px;");
    //connect(room_win, SIGNAL(cmd2EPS(QByteArray)), this, SLOT(cmd2EPS(QByteArray)));
    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
    bodyShadow->setBlurRadius(9.0);
    bodyShadow->setColor(QColor(0, 0, 0, 160));
    bodyShadow->setOffset(7.0);
    this->setGraphicsEffect(bodyShadow);
    this->setStyleSheet("background-color: #435F70");
    widget.status_label->setStyleSheet("color:#4c4c4c");
    widget.bulb_label->setVisible(false);

}

info_widget::~info_widget() {
}


void info_widget::set_room_status(Room_status status){

    if(status.connected == Status::CONNECTED){
        widget.temp_label->setText(status.temp);
        widget.humidity_label->setText(status.humi);
        //widget.status_label->setText("connected");
    }
    if(status.connected == Status::CONNECTING)
        widget.status_label->setText("connecting");
    if(status.connected == Status::FAILED)
        widget.status_label->setText("connection failed");

    int i = 0;
    for(i = 0; i < 8; i++){
        if(status.L[i]){
            widget.bulb_label->setVisible(true);
            break;
        }
    }
    if(i == 8)
        widget.bulb_label->setVisible(false);


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
        emit clicked();
    }
}

void info_widget::set_color(QString color){

    bg_color = color;
    this->setStyleSheet("background-color: "+color);

}

void info_widget::set_name(QString name){

    widget.name_label->setText(name);

}
