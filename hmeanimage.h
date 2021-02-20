#ifndef HMEANIMAGE_H
#define HMEANIMAGE_H

#include "hbasetype.h"
#include <QMessageBox>

class HMeanImage : public HBaseType
{
public:
    HMeanImage();
    void realize(const HalconCpp::HObject & image);
    void realize(const HalconCpp::HObject &image, int min,int max);
};

#endif // HMEANIMAGE_H
