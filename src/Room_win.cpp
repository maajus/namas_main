/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Room_win.cpp
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#include "Room_win.h"


Room_win::Room_win()  {
    widget.setupUi(this);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    
}

Room_win::~Room_win() {
}

void Room_win::on_back_button_clicked(){
    
    this->close();
    
}

void Room_win::set_id(ROOM_ID ID){
    
    room_id = ID;
    
}

void Room_win::on_lights1_button_clicked(){
    
    emit cmd2EPS("L0");
    
}