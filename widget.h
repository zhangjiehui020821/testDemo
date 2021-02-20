#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QWidget>
#include <QStringList>
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QVector>

#include "ImageDisplay.h"
#include "camerathread.h"
#include "HalconCpp.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsELLipseItem>
#include <QMouseEvent>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>

#include "hthreshold.h"
#include "hscaleimage.h"
#include "herosion.h"
#include "hdilation.h"
#include "hopening.h"
#include "hclosing.h"
#include "hmeanimage.h"
#include "hgaussfilter.h"

#include "buttoncontextmenu.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();




private slots:
    void on_pushButton_closeApp_clicked();

    void on_pushButton_minimizeApp_clicked();

    void on_pushButton_maximizeApp_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_toolButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void RunCircle();

    void on_toolButton_2_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_toolButton_11_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_toolButton_13_clicked();

    void on_horizontalSlider_4_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_pushButton_19_clicked();

    void on_toolButton_14_clicked();

    void on_pushButton_21_clicked();

    void on_horizontalSlider_5_valueChanged(int value);

    void on_pushButton_22_clicked();

    void on_horizontalSlider_6_valueChanged(int value);

    void on_horizontalSlider_7_valueChanged(int value);

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_horizontalSlider_8_valueChanged(int value);

    void on_horizontalSlider_9_valueChanged(int value);



    void on_horizontalSlider_10_valueChanged(int value);

    void on_toolButton_15_clicked();

    void on_toolButton_16_clicked();

    void on_toolButton_17_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_horizontalSlider_11_valueChanged(int value);

    void on_horizontalSlider_12_valueChanged(int value);

    void on_horizontalSlider_13_valueChanged(int value);

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_horizontalSlider_14_valueChanged(int value);

    void on_horizontalSlider_15_valueChanged(int value);

    void on_horizontalSlider_16_valueChanged(int value);

    void on_toolButton_18_clicked();

    void on_toolButton_19_clicked();

    void on_toolButton_20_clicked();

    void on_toolButton_21_clicked();

    void on_toolButton_22_clicked();

    void on_toolButton_23_clicked();

    void on_toolButton_24_clicked();

    void on_toolButton_25_clicked();

    void on_pushButton_33_clicked();

    void on_horizontalSlider_17_valueChanged(int value);

    void on_horizontalSlider_18_valueChanged(int value);

    void on_pushButton_35_clicked();

private:
    void initialize_Ui();//初始化UI
    void initialize_Data();//初始化数据

    //把相机取到的图片加到imagedisplay
    void setCameraDisplay();

private:
    Ui::Widget *ui;

    ImageDisplay* m_imageDisplay;
    CameraThread* m_cameraThread;
    HThreshold* m_threshold;
    HScaleImage * m_scaleImage;
    HErosion * m_erosion;
    HDilation * m_dilation;
    HOpening * m_opening;
    HClosing * m_closing;
    HMeanImage * m_meanImage;
    HGaussFilter * m_gaussFilter;

    HalconCpp::HTuple QStringToTuple(QString str);
    HalconCpp::HObject image;

    int stackedWidgetIndexOne;
    int stackedWidgetIndexTwo;

    QPoint dragPosition;

    int flowImagename = 1;


    bool eventFilter(QObject *watched, QEvent *event);

    void showFlowButton(QString buttonName,QString pathName);

};

#endif // WIDGET_H
