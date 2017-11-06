#ifndef _GPIO_H
#define _GPIO_H

#include <QObject>
#include "Blank_widget.h"


enum INTERRUPT {
    INT_DOOR_OPEN,
    INT_DOOR_CLOSE,
    INT_PIR_ON,
};

class IntHelper : public QObject {
    Q_OBJECT

    public:
        IntHelper(){}
signals:
        void interrupt(int);
};













class GPIO : public QObject {

    Q_OBJECT
    public:

        GPIO();
        void initPins();
        void siren_beep();
        void idle_timer_increment();
        void reset_idle_timer();
        void enable_backlight(bool);

        public slots:
            void interrupt(int);


    private:
        void init_pins();
        bool backlight_state;
        int off_timeout;
        int idle_timer;
        Blank_widget *blank;


signals:
        void gpio_interrupt(int intnr);

};

#endif
