#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "entities/utility/base/Utility.h"

class WasteManagement : public Utility
{
public:
    WasteManagement();
    WasteManagement(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~WasteManagement();

    void update();
    Entity* clone();
};

#endif // WASTEMANAGEMENT_H
