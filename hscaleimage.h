#ifndef HSCALEIMAGE_H
#define HSCALEIMAGE_H

#include "hbasetype.h"

#include <QMessageBox>


class HScaleImage : public HBaseType
{
public:
    HScaleImage();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int min,int max);
};

#endif // HSCALEIMAGE_H
