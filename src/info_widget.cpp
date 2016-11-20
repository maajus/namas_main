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

    
}

info_widget::~info_widget() {
}

void info_widget::set_id(ROOM_ID Id){
    
   QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
   bodyShadow->setBlurRadius(9.0);
   bodyShadow->setColor(QColor(0, 0, 0, 160));
   bodyShadow->setOffset(7.0);
  this->setGraphicsEffect(bodyShadow);
        
    id = Id;
    switch(id){
        case ROOM_ID::BEDROOM_1:
            widget.name_label->setText("Miegamasis");
            this->setStyleSheet("background-color: blue; border: 1px solid gray");
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


void info_widget::set_room_status(Room_status status){

    widget.temp_label->setText(status.temp);
    widget.humidity_label->setText(status.humi);
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
