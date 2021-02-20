#include "hthreshold.h"


HThreshold::HThreshold()
{

}

void HThreshold::realize(const HalconCpp::HObject& image)
{
    try
    {

        HalconCpp::HObject ho_Regions,ho_Region;
        HalconCpp::Threshold(image,&ho_Regions,87,255);
        HalconCpp::RegionToBin(ho_Regions, &ho_Region, 255, 0, 10000, 10000);
        this->image = ho_Region;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","image threshold error",QMessageBox::Yes);
    }
}

void HThreshold::realize(const HalconCpp::HObject &image, int min, int max)
{
    try
    {
        ImageDisplay  m_imageDisplay;
        HalconCpp::HObject ho_Regions,ho_Region;
        HalconCpp::Threshold(image,&ho_Regions,min,max);
        HalconCpp::RegionToBin(ho_Regions, &ho_Region, 255, 0, 10000, 10000);

        //if (HalconCpp::HDevWindowStack::IsOpen())
            //HalconCpp::DispObj(ho_Regions, HalconCpp::HDevWindowStack::GetActive());
        this->image = ho_Region;
    }catch (HalconCpp::HException& e)
    {
        QMessageBox::information(NULL,"error","image threshold error",QMessageBox::Yes);
    }



}
