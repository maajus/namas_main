/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pinctrl.cpp
 * Author: justas
 * 
 * Created on August 7, 2016, 1:02 PM
 */

#include "Pinctrl.h"
#include <wiringPi.h>
#include <QDebug>

#define BUTTON_PIN 0

// myInterrupt:  called every time an event occurs
void myInterrupt(void) {
    qDebug()<<"Interrupt";
}



Pinctrl::Pinctrl() {
    
  wiringPiSetup () ;
  
//  pinMode (0, OUTPUT) ;
//
//  digitalWrite (0, HIGH) ; delay (500) ;
//  digitalWrite (0,  LOW) ; delay (500) ;
    
    
  // set Pin 17/0 generate an interrupt on high-to-low transitions
  // and attach myInterrupt() to the interrupt
  if ( wiringPiISR (BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt) < 0 )
      qDebug()<< "Unable to setup ISR";

  
  
}


Pinctrl::~Pinctrl() {
}

void Pinctrl::init_pins(){
    
    
}

void Pinctrl::write_pin(int pin, int state){
    
}
