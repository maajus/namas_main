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
    
   
    connect(&status_timer, SIGNAL(timeout()), this, SLOT(update_status()));
    connect(&info_timer, SIGNAL(timeout()), this, SLOT(update_info()));
    connect(widget.side_menu,SIGNAL(currentRowChanged(int)),widget.stack_widget,SLOT(setCurrentIndex(int)));
    
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
    QFile stylesheet("formStyle.css");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    qApp->setStyleSheet(setSheet);
    widget.side_menu->setIconSize(QSize(64, 64));
    widget.side_menu->setCurrentRow(0);
    this->update_status();

    
}

MainWindow::~MainWindow() {
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
