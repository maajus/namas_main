/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainWindow.cpp
 * Author: justas
 *
 * Created on August 6, 2016, 5:03 PM
 */

#include "MainWindow.h"
#include "info_widget.h"
#include <QDateTime>
#include <QFile>
#include <QObject>

MainWindow::MainWindow() {
    widget.setupUi(this);
    
cam = new Camera;
    if(cam->available()){
        cam->set_widget(widget.video_widget);
    }
    connect(&status_timer, SIGNAL(timeout()), this, SLOT(update_status()));
    connect(&info_timer, SIGNAL(timeout()), this, SLOT(update_info()));
    connect(widget.side_menu,SIGNAL(currentRowChanged(int)),SLOT(menu_selected(int)));
    
    status_timer.start(500);
    info_timer.start(5000);
    
    widget.bedroom1_info->set_id(ROOM_ID::BEDROOM_1);
    widget.bedroom2_info->set_id(ROOM_ID::BEDROOM_2);
    widget.kitchen_info->set_id(ROOM_ID::KITCHEN);
    widget.livingroom_info->set_id(ROOM_ID::LIVING_ROOM);
    widget.wc_info->set_id(ROOM_ID::WC);
    
    bathroom = new Bath_Room_win(widget.wc_info);
    connect(widget.wc_info,SIGNAL(clicked()), bathroom, SLOT(show()));
    //Load and apply stylesheet
    QFile stylesheet(qApp->applicationDirPath()+"formStyle.css");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    qApp->setStyleSheet(setSheet);
    widget.side_menu->setIconSize(QSize(64, 64));
    widget.side_menu->setCurrentRow(0);
    this->update_status();

}

MainWindow::~MainWindow() {
}

void MainWindow::on_take_photo_button_clicked(){

    cam->take_photo();

}

void MainWindow::on_rec_button_clicked(){

    cam->capture_photo();

}

void MainWindow::on_leave_button_clicked(){
    
  exit(0); 
}



void MainWindow::update_status(){
    
    widget.time_label->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
    
}

void MainWindow::update_info(){
    
    bathroom->update_info();
    this->repaint();
}

void MainWindow::menu_selected(int menu){

    widget.stack_widget->setCurrentIndex(menu);
    if(menu == Menus::CAMERA){
        if(cam->available())  cam->start();
    }
    else
        if(cam->available()) cam->stop();

}
