#ifndef HGAUSSFILTER_H
#define HGAUSSFILTER_H


#include "hbasetype.h"

#include <QMessageBox>

class HGaussFilter : public HBaseType
{
public:
    HGaussFilter();
    void realize(const HalconCpp::HObject& image);
    void realize(const HalconCpp::HObject& image,int radius);
};

#endif // HGAUSSFILTER_H
