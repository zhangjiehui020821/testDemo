#include "hmeanimage.h"

HMeanImage::HMeanImage()
{

}

void HMeanImage::realize(const HalconCpp::HObject & image)
{
    try
    {

        HalconCpp::HObject imageMean;
        HalconCpp::MeanImage(image,&imageMean,10,10);
        this->image = imageMean;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","image meanImage error",QMessageBox::Yes);
    }
}

void HMeanImage::realize(const HalconCpp::HObject &image, int width, int height)
{
    try
    {

        HalconCpp::HObject imageMean;
        HalconCpp::MeanImage(image,&imageMean,width,height);
        this->image = imageMean;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","image meanImage error",QMessageBox::Yes);
    }
}
