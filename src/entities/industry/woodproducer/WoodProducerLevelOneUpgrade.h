#ifndef WOODPRODUCERLEVELONEUPGRADE_H
#define WOODPRODUCERLEVELONEUPGRADE_H

#include "WoodProducerUpgrade.h"
#include "Entity.h"

class WoodProducerLevelOneUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelOneUpgrade();
    ~WoodProducerLevelOneUpgrade();
    void update();
    Entity* clone();
    int getStrength();

private: 
    const int UPGRADE = 1.5;
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H
