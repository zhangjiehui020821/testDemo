#include "hclosing.h"

HClosing::HClosing()
{

}

void HClosing::realize(const HalconCpp::HObject &image)
{
    try
    {
        HalconCpp::HObject ho_image,ho_region,ho_erosion_region;
        //HalconCpp::GetDomain(image,&ho_region);
        HalconCpp::Threshold(image,&ho_region,1,255);
        HalconCpp::ClosingCircle(ho_region,&ho_erosion_region,6);
        HalconCpp::RegionToBin(ho_erosion_region, &ho_image, 255, 0, 10000, 10000);
        this->image = ho_image;
    }catch(HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","Closing error",QMessageBox::Yes);
    }
}

void HClosing::realize(const HalconCpp::HObject &image, int radius)
{
    try
    {
        HalconCpp::HObject ho_image,ho_region,ho_erosion_region;
        //HalconCpp::GetDomain(image,&ho_region);
        HalconCpp::Threshold(image,&ho_region,1,255);
        HalconCpp::ClosingCircle(ho_region,&ho_erosion_region,radius);
        HalconCpp::RegionToBin(ho_erosion_region, &ho_image, 255, 0, 10000, 10000);
        this->image = ho_image;
    }catch(HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","Closing error",QMessageBox::Yes);
    }
}

void HClosing::realize(const HalconCpp::HObject &image, int width, int height)
{
    try
    {
        HalconCpp::HObject ho_image,ho_region,ho_erosion_region;
        //HalconCpp::GetDomain(image,&ho_region);
        HalconCpp::Threshold(image,&ho_region,1,255);
        HalconCpp::ClosingRectangle1(ho_region,&ho_erosion_region,width,height);
        HalconCpp::RegionToBin(ho_erosion_region, &ho_image, 255, 0, 10000, 10000);
        this->image = ho_image;
    }catch(HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","Closing error",QMessageBox::Yes);
    }
}
