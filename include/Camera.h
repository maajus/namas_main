#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QVideoWidget>
#include <QCamera>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QCameraImageCapture>
#include <QTimer>

class Camera : public QObject {
    Q_OBJECT

    public:
        Camera();
        bool available(); 
        void start();
        void stop();
        void set_widget(QVideoWidget*);
        void take_photo();
        void capture_photo();

    private:

        QCamera* camera;
        QCameraImageCapture *imageCapture;
        QVideoWidget *viewFinder;
        bool isCapturingImage;
        QTimer shot_timer;

    private slots:

        void imageSaved(int, const QString&);
        void take_photo_auto();
};




#endif
