/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bath_Room_win.h
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#ifndef _ROOM_WIN_H
#define _ROOM_WIN_H



#include "ui_Bath_Room_win.h"
#include "definitions.h"
#include "info_widget.h"
#include "TCP.h"

class Bath_Room_win : public QDialog {
    Q_OBJECT
public:
    Bath_Room_win(info_widget*);
    virtual ~Bath_Room_win();
    void set_id(ROOM_ID ID);
    void update_info();
    void update_lights_state();
    
private:
    Ui::Bath_Room_win widget;
    ROOM_ID room_id;
    info_widget *info_w;
    TCP *tcp;
    Lights lights;

private slots:
    void tcp_data(QByteArray);
    void connection_failed(QAbstractSocket::SocketError);
    void on_lights0_button_clicked();
    void on_lights1_button_clicked();
    void on_lights2_button_clicked();

    void on_back_button_clicked();
};

#endif /* _ROOM_WIN_H */
