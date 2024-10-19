#ifndef WOODPRODUCERLEVELTHREEUPGRADE_H
#define WOODPRODUCERLEVELTHREEUPGRADE_H

#include "WoodProducerUpgrade.h"
#incude "Entity.h"
class WoodProducerLevelThreeUpgrade : WoodProducerUpgrade
{
public:
    WoodProducerLevelThreeUpgrade();
    ~WoodProducerLevelThreeUpgrade();
    void update();
    Entity* clone();
    int getStrength();
};

#endif // WOODPRODUCERLEVELTHREEUPGRADE_H
