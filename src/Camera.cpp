#include "Camera.h"
#include "Config.h"
#include <QCameraInfo>
#include <QPainter>
#include <QScreen>
#include <QGuiApplication>
#include <QDateTime>

Camera::Camera(){


    camera = new QCamera(this);
    imageCapture = new QCameraImageCapture(camera);
    connect(imageCapture, SIGNAL(imageSaved(int,QString)), this, SLOT(imageSaved(int,QString)));

    
    camera->setCaptureMode(QCamera::CaptureStillImage);


    //QImageEncoderSettings imageSettings;
    //imageSettings.setCodec("image/png");
    //imageSettings.setResolution(352, 288);
    //imageSettings.setQuality(QMultimedia::VeryHighQuality);

    //imageCapture->setEncodingSettings(imageSettings);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    shot_timer.setSingleShot(true);
    connect(&shot_timer, SIGNAL(timeout()), this, SLOT(take_photo_auto()));

};


bool Camera::available()
{
    if (QCameraInfo::availableCameras().count() > 0)
        return true;
    else
        return false;
}


void Camera::start(){

    camera->start();
}

void Camera::stop(){

    camera->stop();

}

void Camera::set_widget(QVideoWidget *widget){

    viewFinder = widget;
    camera->setViewfinder(widget);
}

void Camera::take_photo(){

    //camera->start();
    //QCamera::State state=camera->state();
    QScreen *screen = QGuiApplication::primaryScreen();
    QImage img = screen->grabWindow(viewFinder->winId(), 0, 0, -1, -1).toImage();
    img.save(QDateTime::currentDateTime().toString(DATE_TIME_FORMAT)+".jpg");
    //if(state != QCamera::ActiveState)
        //camera->stop();

        //camera->start();
    //camera->searchAndLock(QCamera::LockExposure);
    //imageCapture->capture();
    //camera->unlock();
}
void Camera::capture_photo(){

    camera->start();
    shot_timer.start(2000);

}

void Camera::take_photo_auto(){

    imageCapture->capture();
    
    //QScreen *screen = QGuiApplication::primaryScreen();
    //QImage img = screen->grabWindow(viewFinder->winId(), 0, 0, -1, -1).toImage();
    //img.save(QDateTime::currentDateTime().toString(DATE_TIME_FORMAT)+".jpg");
 
}


void Camera::imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id);
    Q_UNUSED(fileName);

    qDebug()<<"Filename : "<<fileName;
    isCapturingImage = false;
    camera->stop();
}
