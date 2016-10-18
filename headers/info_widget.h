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
#include "Room_win.h"



class info_widget : public QWidget {
    Q_OBJECT
public:
    
    
    
    info_widget(QWidget *parent = 0);
    virtual ~info_widget();
    void set_id(ROOM_ID);
    void update_info();
    
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    
private slots:
    void tcp_data(QByteArray);
    void connection_failed(QAbstractSocket::SocketError);
    void cmd2EPS(QByteArray data);
    
private:
    QThread *tcp_thread;
    Ui::info_widget widget;
    TCP *tcp;
    ROOM_ID id;
    Room_win *room_win;
    
};

#endif /* _INFO_WIDGET_H */
