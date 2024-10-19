#ifndef WOODPRODUCERLEVELTHREEUPGRADE_H
#define WOODPRODUCERLEVELTHREEUPGRADE_H

#include "WoodProducerUpgrade.h"
class WoodProducerLevelThreeUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelThreeUpgrade();
    ~WoodProducerLevelThreeUpgrade();
    void update() override;
    Entity *clone() override;
    int getStrength();
};

#endif // WOODPRODUCERLEVELTHREEUPGRADE_H
