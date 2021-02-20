#ifndef HCLOSING_H
#define HCLOSING_H

#include "hbasetype.h"
#include <QMessageBox>

class HClosing : public HBaseType
{
public:
    HClosing();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int radius);
    void realize(const HalconCpp::HObject &image, int width,int height);
};

#endif // HCLOSING_H
