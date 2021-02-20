#ifndef HOPENING_H
#define HOPENING_H

#include "hbasetype.h"
#include <QMessageBox>

class HOpening : public HBaseType
{
public:
    HOpening();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int radius);
    void realize(const HalconCpp::HObject &image, int width,int height);
};

#endif // HOPENING_H
