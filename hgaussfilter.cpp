#include "hgaussfilter.h"

HGaussFilter::HGaussFilter()
{

}

void HGaussFilter::realize(const HalconCpp::HObject &image)
{
    try
    {
        HalconCpp::HObject imageGauss;
        HalconCpp::GaussFilter(image,&imageGauss,10);
        this->image = imageGauss;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","image gaussImage error",QMessageBox::Yes);
    }
}

void HGaussFilter::realize(const HalconCpp::HObject &image, int radius)
{
    try
    {
        HalconCpp::HObject imageGauss;
        HalconCpp::GaussFilter(image,&imageGauss,radius);
        this->image = imageGauss;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","image gaussImage error",QMessageBox::Yes);
    }
}
