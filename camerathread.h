#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QThread>
#include "HalconCpp.h"

class CameraThread : public QThread
{
    Q_OBJECT
public:
    CameraThread();


    HalconCpp::HObject  ho_Image;
    bool m_isRun = false;

    void run();
    void startThread();
    void stopThread();

signals:
    void cameraStarted();

private:


};

#endif // CAMERATHREAD_H
