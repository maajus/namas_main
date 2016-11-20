#include "Camera.h"
#include <QCameraInfo>

Camera::Camera(){


    camera = new QCamera(this);
    imageCapture = new QCameraImageCapture(camera);
    connect(imageCapture, SIGNAL(imageSaved(int,QString)), this, SLOT(imageSaved(int,QString)));

    


    QCamera::CaptureModes captureMode = QCamera::CaptureStillImage;// : QCamera::CaptureVideo;
    QImageEncoderSettings imageSettings;
    imageSettings.setCodec("image/png");
    imageSettings.setResolution(352, 288);
    imageSettings.setQuality(QMultimedia::VeryHighQuality);

    imageCapture->setEncodingSettings(imageSettings);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setCaptureMode(captureMode);

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

    camera->setViewfinder(widget);
}

void Camera::take_photo(){

        camera->start();
    camera->searchAndLock();
    imageCapture->capture();
    camera->unlock();


}


void Camera::imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id);
    Q_UNUSED(fileName);

    qDebug()<<"Filename : "<<fileName;
    isCapturingImage = false;
}
