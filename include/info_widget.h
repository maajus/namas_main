/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   info_widget.h
 * Author: justas
 *
 * Created on September 4, 2016, 2:45 PM
 */

#ifndef _INFO_WIDGET_H
#define _INFO_WIDGET_H

#include <QObject>
#include <QMouseEvent>
#include "ui_info_widget.h"
#include "TCP.h"
#include "definitions.h"
#include <QString>

struct Room_status {
    int L[8]; //lights state
    QString temp;
    QString humi;
    int connected;
    Room_status(){
        temp = "N/A";
        humi = "N/A";
        connected = 0;
        memset(L,0,sizeof(L));
    }
};


class info_widget : public QWidget {
    Q_OBJECT
public:
    
    
    
    info_widget(QWidget *parent = 0);
    virtual ~info_widget();
   void set_room_status(Room_status);
   void set_color(QString);
   void set_name(QString);
    
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    
   
private:

    Ui::info_widget widget;
    QThread *tcp_thread;
    TCP *tcp;
    ROOM_ID id;
    QString bg_color;
    
signals:
    void clicked();
};

#endif /* _INFO_WIDGET_H */
