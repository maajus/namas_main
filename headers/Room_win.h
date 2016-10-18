/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Room_win.h
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#ifndef _ROOM_WIN_H
#define _ROOM_WIN_H

enum ROOM_ID{KITCHEN,LIVING_ROOM,BEDROOM_1,BEDROOM_2,WC};


#include "ui_Room_win.h"

class Room_win : public QDialog {
    Q_OBJECT
public:
    Room_win();
    virtual ~Room_win();
    void set_id(ROOM_ID ID);
private:
    Ui::Room_win widget;
    ROOM_ID room_id;
    
private slots:
    void on_lights1_button_clicked();
    
signals:
    void cmd2EPS(QByteArray data);
    
private slots:
    void on_back_button_clicked();     
};

#endif /* _ROOM_WIN_H */
