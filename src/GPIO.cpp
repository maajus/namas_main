#include "GPIO.h"
#ifndef PC
#include <wiringPi.h>
#include <pcf8574.h>
#endif
#include <QDebug>
#include <QThread>
#include <Config.h>

#ifdef PC
#define HIGH 1
#define LOW 0
int digitalRead(int){return false;}
int digitalWrite(int,int){return false;}
int delay(int){return 0;}
#endif

IntHelper *helper;

void Interrupt_REED(void) {

    delay(10);
    if(digitalRead(GPIO_REED)){
        emit helper->interrupt(INTERRUPT::INT_DOOR_OPEN);
    }
    else{
        emit helper->interrupt(INTERRUPT::INT_DOOR_CLOSE);
    }
}

void Interrupt_PIR(void) {

    if(digitalRead(GPIO_PIR)){
        emit helper->interrupt(INTERRUPT::INT_PIR_ON);
        //qDebug()<<"pir on";
    }
    else{
        emit helper->interrupt(INTERRUPT::INT_PIR_OFF);
        //qDebug()<<"pir off";
    }
}

GPIO::GPIO(){

#ifndef PC

    blank = new Blank_widget;
    this->init_pins();
    helper = new IntHelper();
    QObject::connect(helper, SIGNAL(interrupt(int)),this,SLOT(interrupt(int)));
    off_timeout = 60000;
    idle_timer = 0;
    pir_lcd = false;

    this->enable_backlight(true);

    //pcf8574Setup (100, 0x38) ;

#endif
}

void GPIO::interrupt(int intnr){

    //qDebug()<<"Int : "<<intnr;
    emit gpio_interrupt(intnr);

}

void GPIO::init_pins(){

#ifndef PC
    //init wiringPI lib
    if (wiringPiSetup () < 0) {
        qDebug()<<"Failed to init GPIO driver";
    }

    //pinMode(GPIO_SIREN, PWM_OUTPUT);
    //pwmSetMode (PWM_MODE_MS);
    //pwmWrite(GPIO_SIREN, 0);
    //pwmSetClock(32);


    pinMode(GPIO_LCD_BL, OUTPUT);
    pinMode(GPIO_SIREN, OUTPUT);
    digitalWrite(GPIO_SIREN, LOW);

    //pull up on door reed switch
    pullUpDnControl(GPIO_REED,PUD_UP);

    //pull down on pir pin (active high);
    pullUpDnControl(GPIO_PIR,PUD_DOWN);

    //pull down on siren pin (active high);
    pullUpDnControl(GPIO_SIREN,PUD_DOWN);



    //register reed door switch irq
    if ( wiringPiISR (GPIO_REED, INT_EDGE_BOTH, &Interrupt_REED) < 0 ) {
        qDebug()<<"Failed to init int";
    }

    //register pir switch irq
    if ( wiringPiISR (GPIO_PIR, INT_EDGE_BOTH, &Interrupt_PIR) < 0 ) {
        qDebug()<<"Failed to init int";
    }

#endif

}

void GPIO::siren_beep(){

    digitalWrite(GPIO_SIREN, HIGH);
    QThread::msleep(1);
    digitalWrite(GPIO_SIREN, LOW);

}


void GPIO::idle_timer_increment() {

    //return if both timeouts are disabled
    //if ((off_timeout == 0) && (dim_timeout == 0)) return;

    //count only if screen is on and not in dim mode
    if (backlight_state) idle_timer++;


    //turn off screen if timeout is reached and screen is not off already (off_timeout==0 always on)
    if ((off_timeout > 0) && (idle_timer * STATUS_REFRESH >= off_timeout) && (backlight_state)) {
        idle_timer = 0;

        if(pir_lcd && digitalRead(GPIO_PIR))
            return;

        this->enable_backlight(false);

    }

}

void GPIO::reset_idle_timer() {

    //reset counter
    idle_timer = 0;
    if(!backlight_state)
        this->enable_backlight(true);

}

void GPIO::enable_backlight(bool enable){

#ifndef PC
    if(!enable)
        blank->show();
    else
        blank->hide();

    digitalWrite(GPIO_LCD_BL, !enable);
    backlight_state = enable;
#endif

}

int GPIO::read(int pin){
    return digitalRead(pin);
}

void GPIO::SetPirLcd(bool enable){

    pir_lcd = enable;
}
