#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "entities/utility/base/Utility.h"

class WasteManagement : public Utility
{
public:
    WasteManagement();
    WasteManagement(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~WasteManagement();

    void update();
    Entity* clone();
};

#endif // WASTEMANAGEMENT_H
