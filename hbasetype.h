#ifndef HBASETYPE_H
#define HBASETYPE_H

#include "HalconCpp.h"

class HBaseType
{
public:
    HBaseType();
    HalconCpp::HObject image;
    virtual void realize(const HalconCpp::HObject& image) = 0;
};

#endif // HBASETYPE_H
