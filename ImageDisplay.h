#ifndef IMAGEDISPLAY_H
#define IMAGEDISPLAY_H

#include <QWidget>
#include "HalconCpp.h"
#include <QMessageBox>
#include <QVector>

namespace Ui {
class ImageDisplay;
}

class ImageDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ImageDisplay(QWidget *parent = 0);
    ~ImageDisplay();

    void DrawRect();
    void DrawRotateRect();
    void DrawCircle();
    void DrawEllipse();
    void Threshold();
    void Blob();
    void AddImage(const HalconCpp::HObject& image);
    void RunImage(const HalconCpp::HObject& image);
    void UpdateImage();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);

private:
    void InitData();
    void InitUi();

    void moveImage(double motionX, double motionY);
    void setImagePart(double r1, double c1, double r2, double c2);
    void zoomImage(double x, double y, double scale);

public:
    HalconCpp::HTuple hv_WindowHandle;
    HalconCpp::HTuple imageWidth;
    HalconCpp::HTuple imageHeight;

    QVector<HalconCpp::HObject> imageVector;

private:

    bool              mouseLeftPressed;
    double            startX, startY;
    int               windowWidth;
    int               windowHeight;

    double            ImgRow1, ImgCol1, ImgRow2, ImgCol2;
    bool              m_isDraw;

    HalconCpp::HObject m_referImage;

    bool               m_isfirst;
    HalconCpp::HObject m_region;  ///检测范围

    Ui::ImageDisplay *ui;
};

#endif // IMAGEDISPLAY_H
