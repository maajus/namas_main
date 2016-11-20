#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QVideoWidget>
#include <QCamera>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QCameraImageCapture>


class Camera : public QObject {
    Q_OBJECT

    public:
        Camera();
        bool available(); 
        void start();
        void stop();
        void set_widget(QVideoWidget*);
        void take_photo();

    private:

        QCamera* camera;
        QCameraImageCapture *imageCapture;
        bool isCapturingImage;

    private slots:

        void imageSaved(int, const QString&);
};




#endif
