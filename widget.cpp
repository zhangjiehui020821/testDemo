#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initialize_Data();
    initialize_Ui();


}

Widget::~Widget()
{
    delete ui;
}

//初始化ui界面
void Widget::initialize_Ui()
{

    setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏
    setFixedSize(this->geometry().width(),this->geometry().height());//固定大小

    //初始化stacked索引
    stackedWidgetIndexOne = 1;
    stackedWidgetIndexTwo = 0;
    //初始化stackedWidgetK控件
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndexOne);
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);

    ui->textEdit->setText(">>");

    ui->Layout_Image->addWidget(m_imageDisplay);

    //showMaximized();

    ui->titleBar->installEventFilter(this);
    ui->toolButton->installEventFilter(this);

}

//初始化数据
void Widget::initialize_Data()
{
    m_imageDisplay = new ImageDisplay();
    m_cameraThread=new CameraThread();
    m_threshold = new HThreshold();
    m_scaleImage = new HScaleImage();
    m_erosion = new HErosion();
    m_dilation = new HDilation();
    m_opening = new HOpening();
    m_closing = new HClosing();
    m_meanImage = new HMeanImage();
    m_gaussFilter = new HGaussFilter();

    connect(m_cameraThread,&CameraThread::cameraStarted,this,&Widget::setCameraDisplay);

}

//QString转HTuple
HalconCpp::HTuple Widget::QStringToTuple(QString str)
{
    QByteArray ba = str.toLatin1();
    char* data = ba.data();
    return (HalconCpp::HTuple)data;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->titleBar)
    {
        QMouseEvent *m = static_cast<QMouseEvent*>(event);
        if(event->type() == QEvent::MouseMove)
        {
            this->move(m->globalPos()+ dragPosition);
        }
        else if(event->type() == QEvent::MouseButtonPress)
        {
            dragPosition=this->pos()-m->globalPos();
        }
    }
    return QWidget::eventFilter(watched,event);
}

void Widget::showFlowButton(QString buttonName,QString pathName)
{
    ButtonContextMenu * btn = new ButtonContextMenu();
    btn->setMaximumSize(100,100);
    btn->setMinimumSize(100,100);

    btn->buttonMenuVector.push_back(btn);
    btn->buttonIndex = btn->buttonMenuVector.size()-1;

    QIcon icon(pathName);
    QSize size(70,200);
    btn->setIcon(icon);
    btn->setIconSize(size);
    btn->setText(buttonName);
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    flowImagename++;
    ui->horizontalLayout_4->addWidget(btn);
}




//标题栏信号槽
void Widget::on_pushButton_closeApp_clicked()
{
    this->close();
}

void Widget::on_pushButton_minimizeApp_clicked()
{
    showMinimized();
}

void Widget::on_pushButton_maximizeApp_clicked()
{
    if(this->width()!=1080 && this->height()!=750)
    {
        setFixedSize(1080,750);
        this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    }else
    {
        setFixedSize(QApplication::desktop()->width(),QApplication::desktop()->height());
        this->move((QApplication::desktop()->width() - this->width())/2,(QApplication::desktop()->height() - this->height())/2);
    }
}

//菜单栏stackwidget槽
void Widget::on_pushButton_clicked()
{
     stackedWidgetIndexOne = 1;
     ui->stackedWidget->setCurrentIndex(stackedWidgetIndexOne);
}

void Widget::on_pushButton_4_clicked()
{
    stackedWidgetIndexOne = 0;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndexOne);
}

void Widget::on_pushButton_2_clicked()
{
    stackedWidgetIndexOne = 2;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndexOne);
}

void Widget::on_pushButton_3_clicked()
{
    stackedWidgetIndexOne = 3;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndexOne);
}

void Widget::on_pushButton_5_clicked()
{
    stackedWidgetIndexOne = 4;
    ui->stackedWidget->setCurrentIndex(stackedWidgetIndexOne);
}

//工具栏stackwidget槽
void Widget::on_toolButton_clicked()
{
    stackedWidgetIndexTwo = 1;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_2_clicked()
{
    stackedWidgetIndexTwo = 2;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_12_clicked()
{
    stackedWidgetIndexTwo = 3;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_13_clicked()
{
    stackedWidgetIndexTwo = 4;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_14_clicked()
{
    stackedWidgetIndexTwo = 5;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_15_clicked()
{
    stackedWidgetIndexTwo = 6;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_16_clicked()
{
    stackedWidgetIndexTwo = 7;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_17_clicked()
{
    stackedWidgetIndexTwo = 8;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_18_clicked()
{
    m_imageDisplay->DrawRect();
    double a=0,b=0;
}

void Widget::on_toolButton_19_clicked()
{
    m_imageDisplay->DrawRotateRect();
}

void Widget::on_toolButton_20_clicked()
{
    m_imageDisplay->DrawCircle();
}

void Widget::on_toolButton_21_clicked()
{
    m_imageDisplay->DrawEllipse();
}

void Widget::on_toolButton_22_clicked()
{
    stackedWidgetIndexTwo = 9;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_23_clicked()
{
    stackedWidgetIndexTwo = 10;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_24_clicked()
{
    stackedWidgetIndexTwo = 11;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}

void Widget::on_toolButton_25_clicked()
{
    stackedWidgetIndexTwo = 12;
    ui->stackedWidget_2->setCurrentIndex(stackedWidgetIndexTwo);
}


//选择图片
void Widget::on_pushButton_7_clicked()
{
    try
    {
        QString pathName = QFileDialog::getOpenFileName(this, tr("action"), "/images/", "Image file(*.bmp *.png *.jpg)", 0);

        if(pathName != "")
        {
            ui->lineEdit->setText(pathName);
        }
    }catch(HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,tr("tip"),tr("Selecr image path error"),QMessageBox::Yes);
    }
}

//图片添加到流程
void Widget::on_pushButton_8_clicked()
{
    QString str = "C:/Users/JieH/Desktop/flowImage/";
    str.append(QString::number(flowImagename));
    str.append(".png");
    try
    {
        HalconCpp::HTuple path = QStringToTuple(ui->lineEdit->text());
        HalconCpp::ReadImage(&image,path);
        HalconCpp::WriteImage(image,"png",0,QStringToTuple(str));
        m_imageDisplay->AddImage(image);
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,tr("tip"),tr("Selecr image path error"),QMessageBox::Yes);
        return;
    }
    //未完成：把图片加入到流程图里面
//    QPushButton * wid = new QPushButton("1234");
//    wid->setMinimumSize(100,100);
//    wid->setMaximumSize(100,100);
//    flowWidgets.push_back(wid);

//    QFont font;
//    font.setPointSize(13);

//    for(int i=0;i<1;i++)
//    {
//        for(int j=0;j<1;j++)
//        {
//            QPointF p(-2400+20+(RECT_WIDTH+30)*i,-1500+20+(RECT_HEIGHT+30)*j);
//            m_rectItem = new QGraphicsRectItem(p.x(),p.y(),RECT_WIDTH,RECT_HEIGHT);
//            m_rectItem->setBrush(QColor(79,136,187,255));
//            m_scene->addItem(m_rectItem);
//            QGraphicsTextItem* text = new QGraphicsTextItem(m_rectItem);
//            text->setPlainText("\nImage");
//            QRectF rect = text->boundingRect();
//            text->setDefaultTextColor(QColor(255,255,255));

//            p.setX(p.x() + RECT_WIDTH/2 - rect.width()/2);
//            text->setPos(p);
//            text->setFont(font);
//            m_rectItem->setFlag(QGraphicsItem::ItemIsMovable);
//        }
//    }

    showFlowButton("原图",str);


//    QLabel * lab = new QLabel("   -->");
//    lab->setMaximumSize(60,60);
//    ui->horizontalLayout_4->addWidget(lab);

}





void Widget::RunCircle()
{
    // Local iconic variables
    HalconCpp::HObject ho_Image;

    // Local control variables
    HalconCpp::HTuple hv_AcqHandle;

    // Image Acquisition 01: Code generated by Image Acquisition 01
    HalconCpp::OpenFramegrabber("DirectShow", 1, 1, 0, 0, 0, 0, "default", 8, "rgb", -1, "false",
                                  "default", "[0] Lenovo EasyCamera", 0, -1, &hv_AcqHandle);
    HalconCpp::GrabImageStart(hv_AcqHandle, -1);
    //    while (0 != 1) {
    HalconCpp::GrabImageAsync(&ho_Image, hv_AcqHandle, -1);
    m_imageDisplay->RunImage(ho_Image);
    // Image Acquisition 01: Do something
    //    }
    HalconCpp::CloseFramegrabber(hv_AcqHandle);
}

//实时采集按钮
void Widget::on_pushButton_14_clicked()
{
    // Local iconic variables
    m_cameraThread->startThread();
    m_cameraThread->m_isRun=true;
}

//把相机取到的图片加到imagedisplay
void Widget::setCameraDisplay()
{
    m_imageDisplay->AddImage(m_cameraThread->ho_Image);
    m_imageDisplay->imageVector.pop_back();
}

//停止采集按钮
void Widget::on_pushButton_6_clicked()
{
    m_cameraThread->stopThread();
}

//单帧采集按钮
void Widget::on_pushButton_13_clicked()
{

}

//画矩形
void Widget::on_toolButton_11_clicked()
{
    m_imageDisplay->DrawRect();
}
//画旋转矩形
void Widget::on_toolButton_9_clicked()
{
    m_imageDisplay->DrawRotateRect();
}
//画圆
void Widget::on_toolButton_10_clicked()
{
    m_imageDisplay->DrawCircle();
}
//画椭圆
void Widget::on_toolButton_8_clicked()
{
    m_imageDisplay->DrawEllipse();
}


//二值化 添加流程
void Widget::on_pushButton_16_clicked()
{
    QString str = "C:/Users/JieH/Desktop/flowImage/";
    str.append(QString::number(flowImagename));
    str.append(".png");
    m_threshold->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider->value(),ui->horizontalSlider_2->value());
    HalconCpp::HObject ImagePart;
    //HalconCpp::HTuple height,width;
    //HalconCpp::GetImageSize(m_threshold->image,&width,&height);
    HalconCpp::ChangeFormat(m_threshold->image,&ImagePart,1500,1500);
    HalconCpp::WriteImage(ImagePart,"png",0,QStringToTuple(str));
    m_imageDisplay->AddImage(m_threshold->image);
    showFlowButton("二值化",str);
}

//曝光 添加流程
void Widget::on_pushButton_19_clicked()
{
    m_scaleImage->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_3->value(),-ui->horizontalSlider_4->value());
    m_imageDisplay->AddImage(m_scaleImage->image);
}

//腐蚀（圆形） 添加到流程
void Widget::on_pushButton_21_clicked()
{
    m_erosion->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_5->value());
    m_imageDisplay->AddImage(m_erosion->image);
}

//腐蚀（矩形） 添加到流程
void Widget::on_pushButton_22_clicked()
{
    m_erosion->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_6->value(),ui->horizontalSlider_7->value());
    m_imageDisplay->AddImage(m_erosion->image);
}

//圆形膨胀 添加到流程
void Widget::on_pushButton_24_clicked()
{
    m_dilation->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_8->value());
    m_imageDisplay->AddImage(m_dilation->image);
}

//矩形膨胀 添加到流程
void Widget::on_pushButton_25_clicked()
{
    m_dilation->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_9->value(),ui->horizontalSlider_10->value());
    m_imageDisplay->AddImage(m_dilation->image);
}

//圆形开运算 添加到流程
void Widget::on_pushButton_28_clicked()
{
    m_opening->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_11->value());
    m_imageDisplay->AddImage(m_opening->image);
}

//矩形开运算 添加到流程
void Widget::on_pushButton_27_clicked()
{
    m_opening->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_12->value(),ui->horizontalSlider_13->value());
    m_imageDisplay->AddImage(m_opening->image);
}

//圆形闭运算 添加到流程
void Widget::on_pushButton_32_clicked()
{
    m_closing->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_14->value());
    m_imageDisplay->AddImage(m_closing->image); 
}

//矩形闭运算 添加到流程
void Widget::on_pushButton_31_clicked()
{
    m_closing->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_15->value(),ui->horizontalSlider_16->value());
    m_imageDisplay->AddImage(m_closing->image);
}

//均值滤波添加到流程
void Widget::on_pushButton_33_clicked()
{
    m_meanImage->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider_17->value(),ui->horizontalSlider_18->value());
    m_imageDisplay->AddImage(m_meanImage->image);
}

//高斯滤波添加到流程
void Widget::on_pushButton_35_clicked()
{
    m_gaussFilter->realize(m_imageDisplay->imageVector.back());
    m_imageDisplay->AddImage(m_gaussFilter->image);
}


//二值化阈值滑块数值改变槽函数
void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label_11->setText("最小阈值："+QString::number(ui->horizontalSlider->value()));
    m_threshold->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider->value(),ui->horizontalSlider_2->value());
    m_imageDisplay->AddImage(m_threshold->image);
    m_imageDisplay->imageVector.pop_back();
}

void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_12->setText("最大阈值："+QString::number(ui->horizontalSlider_2->value()));
    m_threshold->realize(m_imageDisplay->imageVector.back(),ui->horizontalSlider->value(),ui->horizontalSlider_2->value());
    m_imageDisplay->AddImage(m_threshold->image);
    m_imageDisplay->imageVector.pop_back();
}

//曝光阈值滑块数值改变槽函数
void Widget::on_horizontalSlider_3_valueChanged(int value)
{
    ui->label_13->setText("曝光倍数:"+QString::number(ui->horizontalSlider_3->value()));
    on_pushButton_19_clicked();
    m_imageDisplay->imageVector.pop_back();
}

void Widget::on_horizontalSlider_4_valueChanged(int value)
{
    ui->label_14->setText("阴影缩放:"+QString::number(ui->horizontalSlider_4->value()));
    on_pushButton_19_clicked();
    m_imageDisplay->imageVector.pop_back();
}


//圆形腐蚀半径数值滑块
void Widget::on_horizontalSlider_5_valueChanged(int value)
{
    ui->label_15->setText("圆形腐蚀半径:"+QString::number(ui->horizontalSlider_5->value()));
    on_pushButton_21_clicked();
    m_imageDisplay->imageVector.pop_back();
}

//矩形腐蚀width数值滑块
void Widget::on_horizontalSlider_6_valueChanged(int value)
{
    ui->label_16->setText("矩形腐蚀宽度:"+QString::number(ui->horizontalSlider_6->value()));
    on_pushButton_22_clicked();
    m_imageDisplay->imageVector.pop_back();
}

//矩形腐蚀height数值化快
void Widget::on_horizontalSlider_7_valueChanged(int value)
{
    ui->label_17->setText("矩形腐蚀长度:"+QString::number(ui->horizontalSlider_7->value()));
    on_pushButton_22_clicked();
    m_imageDisplay->imageVector.pop_back();
}


//圆形膨胀 半径数值滑块
void Widget::on_horizontalSlider_8_valueChanged(int value)
{
    ui->label_18->setText("圆形腐蚀半径:"+QString::number(ui->horizontalSlider_8->value()));
    on_pushButton_24_clicked();
    m_imageDisplay->imageVector.pop_back();
}
//矩形膨胀 宽度数值滑块
void Widget::on_horizontalSlider_9_valueChanged(int value)
{
    ui->label_18->setText("圆形腐 蚀半径:"+QString::number(ui->horizontalSlider_9->value()));
    on_pushButton_25_clicked();
    m_imageDisplay->imageVector.pop_back();
}
//矩形膨胀 高度数值滑块
void Widget::on_horizontalSlider_10_valueChanged(int value)
{
    ui->label_18->setText("圆形腐蚀半径:"+QString::number(ui->horizontalSlider_10->value()));
    on_pushButton_25_clicked();
    m_imageDisplay->imageVector.pop_back();
}

//圆形开运算 半径数值滑块
void Widget::on_horizontalSlider_11_valueChanged(int value)
{
    ui->label_21->setText("圆形开运算半径:"+QString::number(ui->horizontalSlider_11->value()));
    on_pushButton_28_clicked();
    m_imageDisplay->imageVector.pop_back();
}

//矩形开运算 宽度数值滑块
void Widget::on_horizontalSlider_12_valueChanged(int value)
{
    ui->label_22->setText("矩形开运算宽度:"+QString::number(ui->horizontalSlider_12->value()));
    on_pushButton_27_clicked();
    m_imageDisplay->imageVector.pop_back();
}

//;矩形开运算 高度数值滑块
void Widget::on_horizontalSlider_13_valueChanged(int value)
{
    ui->label_23->setText("矩形开运算高度:"+QString::number(ui->horizontalSlider_13->value()));
    on_pushButton_27_clicked();
    m_imageDisplay->imageVector.pop_back();
}



void Widget::on_horizontalSlider_14_valueChanged(int value)
{
    ui->label_26->setText("圆形闭运算半径："+QString::number(ui->horizontalSlider_14->value()));
    on_pushButton_32_clicked();
    m_imageDisplay->imageVector.pop_back();
}

void Widget::on_horizontalSlider_15_valueChanged(int value)
{
    ui->label_24->setText("矩形闭运算宽度："+QString::number(ui->horizontalSlider_15->value()));
    on_pushButton_31_clicked();
    m_imageDisplay->imageVector.pop_back();
}

void Widget::on_horizontalSlider_16_valueChanged(int value)
{
    ui->label_25->setText("矩形闭运算高度："+QString::number(ui->horizontalSlider_16->value()));
    on_pushButton_31_clicked();
    m_imageDisplay->imageVector.pop_back();
}

void Widget::on_horizontalSlider_17_valueChanged(int value)
{
    ui->label_27->setText("模糊宽度："+QString::number(ui->horizontalSlider_17->value()));
    on_pushButton_33_clicked();
    m_imageDisplay->imageVector.pop_back();
}

void Widget::on_horizontalSlider_18_valueChanged(int value)
{
    ui->label_28->setText("模糊高度："+QString::number(ui->horizontalSlider_18->value()));
    on_pushButton_33_clicked();
    m_imageDisplay->imageVector.pop_back();
}


