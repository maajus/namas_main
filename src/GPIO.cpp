#include "GPIO.h"
#include <wiringPi.h>
#include <pcf8574.h>
#include <QDebug>
#include <QThread>
#include <Config.h>

IntHelper *helper;

void Interrupt_REED(void) {

    if(digitalRead(GPIO_REED)){
        emit helper->interrupt(INTERRUPT::INT_DOOR_OPEN);
    }
    else{
        emit helper->interrupt(INTERRUPT::INT_DOOR_CLOSE);
    }
}

void Interrupt_PIR(void) {

    if(digitalRead(GPIO_REED)){
        emit helper->interrupt(INTERRUPT::INT_PIR_ON);
    }
}


GPIO::GPIO(){

#ifndef PC

 
    this->init_pins();

    helper = new IntHelper();
    QObject::connect(helper, SIGNAL(interrupt(int)),this,SLOT(interrupt(int)));

    //pcf8574Setup (100, 0x38) ;

#endif
}

void GPIO::interrupt(int intnr){

    qDebug()<<"Int : "<<intnr;
    emit gpio_interrupt(intnr);
    

    //if(intnr == INTERRUPT::INT_DOOR_OPEN)
        //this->siren_beep();

}


void GPIO::init_pins(){

    //init wiringPI lib
    if (wiringPiSetup () < 0) {
        qDebug()<<"Failed to init GPIO driver";
    }

    //pinMode(GPIO_PIR, INPUT);
    //pinMode(GPIO_SIREN, PWM_OUTPUT);
    //pwmSetMode (PWM_MODE_MS);
    //pwmWrite(GPIO_SIREN, 0);
    //pwmSetClock(32);


    //pullUpDnControl(GPIO_SIREN,PUD_DOWN);
    //pull down on door reed switch
    pullUpDnControl(GPIO_REED,PUD_UP);

    //pull down on pir pin (active high);
    //pullUpDnControl(GPIO_PIR,PUD_DOWN);

    //register reed door switch irq
    if ( wiringPiISR (GPIO_REED, INT_EDGE_BOTH, &Interrupt_REED) < 0 ) {
        qDebug()<<"Failed to init int";
    }

    //register pir switch irq
    if ( wiringPiISR (GPIO_PIR, INT_EDGE_RISING, &Interrupt_PIR) < 0 ) {
        qDebug()<<"Failed to init int";
    }



}

void GPIO::siren_beep(){

    pwmWrite(GPIO_SIREN, 12);
    delay(40);
    pwmWrite(GPIO_SIREN, 0);

}
