#include "ws_server.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>
#include "json.hpp"


QT_USE_NAMESPACE

WSserver::WSserver(quint16 port) :
    QObject(),
    m_pWebSocketServer(new QWebSocketServer(QStringLiteral("Echo Server"),
                                            QWebSocketServer::NonSecureMode, this)),
    m_debug(true)
{
    if (m_pWebSocketServer->listen(QHostAddress::Any, port)) {
        if (m_debug)
            qDebug() << "[WS] listening on port" << port;
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &WSserver::onNewConnection);
        connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &WSserver::closed);
    }
}

WSserver::~WSserver()
{
    m_pWebSocketServer->close();
    qDeleteAll(m_clients.begin(), m_clients.end());
}

//! [onNewConnection]
void WSserver::onNewConnection()
{
    QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
    connect(pSocket, &QWebSocket::textMessageReceived, this, &WSserver::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &WSserver::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &WSserver::socketDisconnected);
    m_clients << pSocket;

    qDebug() << "[WS] socket connected:" << pSocket->peerAddress().toString();
}


void WSserver::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    nlohmann::json j;
        //qDebug() << "[WS] Message received:" << message;

    try{
        j = nlohmann::json::parse(message.toStdString()); //parse json from received string
    }
    catch (const std::exception&) {
        qDebug() << "[WS] Failed to parse json "<< message;
        return;
    }

    json_received(pClient, j);

    //if (pClient) {
        //pClient->sendTextMessage(message);
    //}

}



void WSserver::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "[WS] Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}


void WSserver::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (m_debug)
        qDebug() << "[WS] socket disconnected:" << pClient->peerAddress().toString();
    if (pClient) {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}

void WSserver::sendJson(QWebSocket *pClient, nlohmann::json j){

    std::string message = j.dump();
        pClient->sendTextMessage(QString::fromStdString(message));
        //qDebug()<<QString::fromStdString(message);
}


