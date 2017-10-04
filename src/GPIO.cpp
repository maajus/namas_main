#include "GPIO.h"
#include <wiringPi.h>
#include <pcf8574.h>
#include <QDebug>
#include <Config.h>

IntHelper *helper;

void Interrupt(void) {

    if(digitalRead(GPIO_PIR)){
        digitalWrite (GPIO_SIREN, HIGH) ;
        qDebug()<<"PIR ON";
        emit helper->interrupt(1);
    }
    else{
        digitalWrite (GPIO_SIREN,  LOW) ;
        qDebug()<<"PIR OFF";
        emit helper->interrupt(0);
    }
}


GPIO::GPIO(){

#ifndef PC

    helper = new IntHelper();
    //QObject::connect(&helper,&IntHelper::interrupt, this, &GPIO::interrupt);
    QObject::connect(helper, SIGNAL(interrupt(int)),this,SLOT(interrupt(int)));
if (wiringPiSetup () < 0) {
            qDebug()<<"Failed to init GPIO driver";
}
  

pinMode (0, OUTPUT) ;
  

if ( wiringPiISR (GPIO_PIR, INT_EDGE_BOTH, &Interrupt) < 0 ) {
       qDebug()<<"Failed to init int";
  }


pcf8574Setup (100, 0x38) ;



//for (;;)
  //{
     //delay (500) ;
     //delay (500) ;
  //}

#endif
}

void GPIO::interrupt(int intnr){

    qDebug()<<"Int : "<<intnr;

}

