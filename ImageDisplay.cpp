#include "ImageDisplay.h"
#include "ui_ImageDisplay.h"
#include <QMouseEvent>

ImageDisplay::ImageDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageDisplay)
{
    ui->setupUi(this);
}

ImageDisplay::~ImageDisplay()
{
    delete ui;
}

void ImageDisplay::DrawRect() {
    m_isDraw = true;

    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "green");

    // Local control variables
    HalconCpp::HTuple hv_Row1, hv_Column1;
    HalconCpp::HTuple hv_Row2, hv_Column2;

    HalconCpp::DrawRectangle1(hv_WindowHandle, &hv_Row1, &hv_Column1, &hv_Row2, &hv_Column2);

    HalconCpp::GenRectangle1(&m_region, hv_Row1, hv_Column1, hv_Row2, hv_Column2);
    HalconCpp::DispRectangle1(hv_WindowHandle, hv_Row1, hv_Column1, hv_Row2, hv_Column2);

    m_isDraw = false;
}

void ImageDisplay::DrawRotateRect() {
    m_isDraw = true;

    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "blue");

    // Local control variables
    HalconCpp::HTuple hv_Row, hv_Column, hv_Phi;
    HalconCpp::HTuple hv_Length1, hv_Length2;

    DrawRectangle2(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Phi, &hv_Length1, &hv_Length2);
    GenRectangle2(&m_region, hv_Row, hv_Column, hv_Phi, hv_Length1, hv_Length2);
    HalconCpp::DispRectangle2(hv_WindowHandle, hv_Row, hv_Column, hv_Phi, hv_Length1, hv_Length2);

    m_isDraw = false;
}

void ImageDisplay::DrawCircle() {
    m_isDraw = true;

    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "red");

    // Local control variables
    HalconCpp::HTuple hv_Row, hv_Column;
    HalconCpp::HTuple hv_Radius;

    HalconCpp::DrawCircle(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Radius);
    HalconCpp::GenCircle(&m_region, hv_Row, hv_Column, hv_Radius);
    HalconCpp::DispCircle(hv_WindowHandle, hv_Row, hv_Column, hv_Radius);

    m_isDraw = false;
}

void ImageDisplay::DrawEllipse() {
    m_isDraw = true;

    HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "yellow");

    // Local control variables
    HalconCpp::HTuple hv_Row, hv_Column, hv_Phi;
    HalconCpp::HTuple hv_Radius1, hv_Radius2;

    HalconCpp::DrawEllipse(hv_WindowHandle, &hv_Row, &hv_Column, &hv_Phi, &hv_Radius1, &hv_Radius2);
    HalconCpp::GenEllipse(&m_region, hv_Row, hv_Column, hv_Phi, hv_Radius1, hv_Radius2);
    HalconCpp::DispEllipse(hv_WindowHandle, hv_Row, hv_Column, hv_Phi, hv_Radius1, hv_Radius2);

    m_isDraw = false;
}

void ImageDisplay::Threshold() {
    // Local iconic variables
    HalconCpp::HObject ho_ImageReduced;
    HalconCpp::HObject ho_Region, ho_ConnectedRegions, ho_SelectedRegions;

    // Local control variables
    HalconCpp::HTuple hv_Area, hv_Row, hv_Column;

    HalconCpp::ReduceDomain(m_referImage, m_region, &ho_ImageReduced);

    HalconCpp::Threshold(ho_ImageReduced, &ho_Region, 0, 200);
    HalconCpp::RegionToBin(ho_Region, &ho_Region, 255, 0, imageWidth, imageHeight);

    if (HalconCpp::HDevWindowStack::IsOpen())
        HalconCpp::DispObj(ho_Region, HalconCpp::HDevWindowStack::GetActive());
}

void ImageDisplay::Blob() {
    // Local iconic variables
    HalconCpp::HObject ho_ImageReduced, ho_ImageMean;
    HalconCpp::HObject ho_Region, ho_ConnectedRegions, ho_SelectedRegions;

    // Local control variables
    HalconCpp::HTuple hv_Area, hv_Row, hv_Column;

    HalconCpp::ReduceDomain(m_referImage, m_region, &ho_ImageReduced);

    //    HalconCpp::Threshold(ho_ImageReduced, &ho_Region, 0, 200);

    MeanImage(ho_ImageReduced, &ho_ImageMean, 9, 9);
    DynThreshold(m_referImage, ho_ImageMean, &ho_Region, 5, "light");

    HalconCpp::Connection(ho_Region, &ho_ConnectedRegions);

    HalconCpp::SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 150, 99999);

    HalconCpp::AreaCenter(ho_SelectedRegions, &hv_Area, &hv_Row, &hv_Column);

    if (HalconCpp::HDevWindowStack::IsOpen())
        HalconCpp::DispObj(ho_SelectedRegions, HalconCpp::HDevWindowStack::GetActive());

    int test = hv_Area.Length();
    int ddd  = 0;

//    HalconCpp::SobelAmp(m_referImage, &ho_ImageReduced, "sum_abs", 3);
//    HalconCpp::DispObj(ho_ImageReduced, HalconCpp::HDevWindowStack::GetActive());

}

void ImageDisplay::AddImage(const HalconCpp::HObject& image) {
    try
    {

        m_referImage = image;
        imageVector.push_back(image);
        InitData();
        InitUi();
        m_isfirst = false;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,tr("error"),tr("display add image error"),QMessageBox::Yes);
    }

}

void ImageDisplay::RunImage(const HalconCpp::HObject& image) {
    m_referImage = image;
    HalconCpp::DispObj(m_referImage, HalconCpp::HDevWindowStack::GetActive());
    Blob();
}

void ImageDisplay::mouseMoveEvent(QMouseEvent* event) {
    if (mouseLeftPressed && !m_isDraw) {
        double motionX = 0, motionY = 0;

        double scale = 0;

        motionX = event->x() - startX;
        motionY = event->y() - startY;
        if ((0 != (int)motionX) || (0 != (int)motionY)) {
            moveImage(motionX, motionY);
            startX = event->x();
            startY = event->y();
        }
    }
}

void ImageDisplay::mousePressEvent(QMouseEvent* event) {
    if (Qt::LeftButton == event->buttons() && !m_isDraw) {
        mouseLeftPressed = true;
        startX           = event->x();
        startY           = event->y();
    }
}

void ImageDisplay::mouseReleaseEvent(QMouseEvent* event) {
    mouseLeftPressed = false;
}

void ImageDisplay::wheelEvent(QWheelEvent* event) {
    double scale = 0;

    int numDegrees = event->delta() / 8;
    int numStep    = numDegrees / 15;
    if (numStep > 0) {
        scale = 0.9 * 1;
    } else {
        scale = 1 / (0.9 * 1);
    }
    zoomImage(event->x(), event->y(), scale);
}

void ImageDisplay::InitData() {
    mouseLeftPressed = false;
    //    this->resize(2000, 1000);
    windowWidth  = this->width();
    windowHeight = this->height();

    GetImageSize(m_referImage, &imageWidth, &imageHeight);

    ImgRow1  = 0;
    ImgCol1  = 0;
    ImgRow2  = imageHeight.I() - 1;
    ImgCol2  = imageWidth.I() - 1;
    m_isDraw = false;
}

void ImageDisplay::InitUi() {
    if (m_isfirst) {
        HalconCpp::SetSystem("width", 5000);
        HalconCpp::SetSystem("height", 5000);

        HalconCpp::SetWindowAttr("background_color", "black");

        HWND hwndID = (HWND)this->winId();
        HalconCpp::OpenWindow(this->rect().top(), this->rect().left(), this->rect().width(), this->rect().height(),
                              (Hlong)hwndID, "visible", "", &hv_WindowHandle);

        HalconCpp::HDevWindowStack::Push(hv_WindowHandle);

        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetColor(HalconCpp::HDevWindowStack::GetActive(), "green");
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetDraw(HalconCpp::HDevWindowStack::GetActive(), "margin");
        if (HalconCpp::HDevWindowStack::IsOpen())
            HalconCpp::SetLineWidth(HalconCpp::HDevWindowStack::GetActive(), 2);
        setImagePart(ImgRow1, ImgCol1, ImgRow2, ImgCol2);
    }

    if (HalconCpp::HDevWindowStack::IsOpen())
        HalconCpp::DispObj(m_referImage, HalconCpp::HDevWindowStack::GetActive());
}

void ImageDisplay::moveImage(double motionX, double motionY) {
    double deltaR = motionY / windowHeight * (ImgRow2 - ImgRow1);
    double deltaC = motionX / windowWidth * (ImgCol2 - ImgCol1);
    ImgRow1 += -(deltaR);
    ImgRow2 += -deltaR;

    ImgCol1 += -deltaC;
    ImgCol2 += -deltaC;

    setImagePart(ImgRow1, ImgCol1, ImgRow2, ImgCol2);

    UpdateImage();
}

void ImageDisplay::setImagePart(double r1, double c1, double r2, double c2) {
    ImgRow1 = r1;
    ImgCol1 = c1;
    ImgRow2 = r2;
    ImgCol2 = c2;

    HalconCpp::SetPart(hv_WindowHandle, (int)ImgRow1, (int)ImgCol1, (int)ImgRow2, (int)ImgCol2);
}

void ImageDisplay::UpdateImage() {
    HalconCpp::ClearWindow(hv_WindowHandle);
    DispObj(m_referImage, hv_WindowHandle);
}

void ImageDisplay::zoomImage(double x, double y, double scale) {
    double xInImage = 0, yInImage = 0;
    xInImage = ImgCol1 + x / windowWidth * (ImgCol2 - ImgCol1);
    yInImage = ImgRow1 + y / windowHeight * (ImgRow2 - ImgRow1);

    double lengthC, lengthR;
    double pencentC, pencentR;

    pencentC = (0 == (ImgCol2 - ImgCol1) ? 0 : (xInImage - ImgCol1) / (ImgCol2 - ImgCol1));
    pencentR = (0 == (ImgRow2 - ImgRow1) ? 0 : (yInImage - ImgRow1) / (ImgRow2 - ImgRow1));

    lengthC = (ImgCol2 - ImgCol1) * scale;
    lengthR = (ImgRow2 - ImgRow1) * scale;

    double ImgCol1Tmp = xInImage - lengthC * pencentC;
    double ImgCol2Tmp = xInImage + lengthC * (1 - pencentC);
    double ImgRow1Tmp = yInImage - lengthR * pencentR;
    double ImgRow2Tmp = yInImage + lengthR * (1 - pencentR);
    if (ImgCol1Tmp == ImgCol2Tmp) {
        ImgCol1Tmp = xInImage - 0.5;
        ImgCol2Tmp = xInImage + 0.5;

        ImgCol1 = ImgCol1Tmp;
        ImgCol2 = ImgCol2Tmp;
    }

    if (ImgRow1 == ImgRow2) {
        ImgRow1Tmp = yInImage - 0.5;
        ImgRow2Tmp = yInImage + 0.5;
        ImgRow1    = ImgRow1Tmp;
        ImgRow2    = ImgRow2Tmp;
    }

    double T = 30000;
    if (fabs(ImgCol1Tmp) < T && fabs(ImgCol2Tmp) < T && fabs(ImgRow1Tmp) < T && fabs(ImgRow2Tmp) < T) {
        ImgCol1 = ImgCol1Tmp;
        ImgCol2 = ImgCol2Tmp;
        ImgRow1 = ImgRow1Tmp;
        ImgRow2 = ImgRow2Tmp;

        setImagePart(ImgRow1, ImgCol1, ImgRow2, ImgCol2);
        UpdateImage();
    }
}
