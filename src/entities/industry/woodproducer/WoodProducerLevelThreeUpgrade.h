#ifndef WOODPRODUCERLEVELTHREEUPGRADE_H
#define WOODPRODUCERLEVELTHREEUPGRADE_H

#include "WoodProducerUpgrade.h"

class WoodProducerLevelThreeUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelThreeUpgrade(WoodProducer *woodProd);
    WoodProducerLevelThreeUpgrade(WoodProducerLevelThreeUpgrade *woodProd);
    ~WoodProducerLevelThreeUpgrade();
    void update();
    int getOutput();
    int getLevel();
    Entity *clone();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 4;
};

#endif // WOODPRODUCERLEVELTHREEUPGRADE_H
