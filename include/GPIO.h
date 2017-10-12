#ifndef _GPIO_H
#define _GPIO_H

#include <QObject>


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

        public slots:
            void interrupt(int);

    private:
        void init_pins();


signals:
        void gpio_interrupt(int intnr);

};

#endif
