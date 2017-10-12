#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "TCP.h"
#include "info_widget.h"

class Room : public QObject
{

Q_OBJECT
    
public:
    Room (ROOM_ID);
    QString read_ip();
    void connect2module();
    void sendData(QByteArray);
    void switch_all_lights(bool);
    void toggle_all_lights();

private:
    QString ip;
    TCP *tcp;
     Room_status status;
    int connection_status;

   ROOM_ID roomd_id;

private slots:
    void tcp_data(QByteArray data);
    void set_connection_status(int);

signals:
    void room_status_received(Room_status);
};




#endif // ifndef ROOM_H

