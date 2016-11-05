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

class info_widget : public QWidget {
    Q_OBJECT
public:
    
    
    
    info_widget(QWidget *parent = 0);
    virtual ~info_widget();
    void set_id(ROOM_ID);
    void set_name(QString);
    void set_temp(QString);
    void set_humi(QString);
    void set_lights(Lights);
    
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    
   
private:

    Ui::info_widget widget;
    QThread *tcp_thread;
    TCP *tcp;
    ROOM_ID id;
    
signals:
    void clicked();
};

#endif /* _INFO_WIDGET_H */
