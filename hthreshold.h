#ifndef HTHRESHOLD_H
#define HTHRESHOLD_H
#include "hbasetype.h"
#include "ImageDisplay.h"

#include <QMessageBox>

class HThreshold : public HBaseType
{
public:
    HThreshold();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int min,int max);
};

#endif // HTHRESHOLD_H
