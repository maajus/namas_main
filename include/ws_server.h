#ifndef ECHOSERVER_H
#define ECHOSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QWebSocketServer>
#include "json.hpp"

//QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
//QT_FORWARD_DECLARE_CLASS(QWebSocket)

class WSserver : public QObject
{
    Q_OBJECT
public:
    explicit WSserver(quint16 port);
    ~WSserver();

    void sendJson(QWebSocket *pClient, nlohmann::json j);

Q_SIGNALS:
    void closed();
    void json_received(QWebSocket *pClient, nlohmann::json j);

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
    bool m_debug;
};

#endif //ECHOSERVER_H
