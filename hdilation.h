#ifndef HDILATION_H
#define HDILATION_H

#include "hbasetype.h"

#include <QMessageBox>

class HDilation : public HBaseType
{
public:
    HDilation();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int radius);
    void realize(const HalconCpp::HObject &image, int width,int height);
};

#endif // HDILATION_H
