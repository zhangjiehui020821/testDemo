#ifndef HEROSION_H
#define HEROSION_H

#include "hbasetype.h"

#include <QMessageBox>

class HErosion : public HBaseType
{
public:
    HErosion();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int radius);
    void realize(const HalconCpp::HObject &image, int width,int height);
};

#endif // HEROSION_H
