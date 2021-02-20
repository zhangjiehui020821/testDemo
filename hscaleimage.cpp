#include "hscaleimage.h"

HScaleImage::HScaleImage()
{

}

void HScaleImage::realize(const HalconCpp::HObject &image)
{
    try
    {
        HalconCpp::HObject ho_Regions,ho_Region;
        HalconCpp::ScaleImage(image,&ho_Regions,87,255);
        HalconCpp::RegionToBin(ho_Regions, &ho_Region, 255, 0, 10000, 10000);
        this->image = ho_Region;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","iscale image error",QMessageBox::Yes);
    }
}

void HScaleImage::realize(const HalconCpp::HObject &image, int min, int max)
{
    try
    {
        HalconCpp::HObject ho_Regions,ho_Region;
        HalconCpp::ScaleImage(image,&ho_Regions,min,-max);
        this->image = ho_Regions;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","scale image error",QMessageBox::Yes);
    }
}
