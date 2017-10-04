#ifndef _GPIO_H
#define _GPIO_H

#include <QObject>

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
public slots:
        void interrupt(int);



};

#endif
