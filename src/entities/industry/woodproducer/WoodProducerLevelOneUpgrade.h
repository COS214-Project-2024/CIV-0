#ifndef WOODPRODUCERLEVELONEUPGRADE_H
#define WOODPRODUCERLEVELONEUPGRADE_H

#include "WoodProducerUpgrade.h"

class WoodProducerLevelTwoUpgrade;

class WoodProducerLevelOneUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelOneUpgrade(WoodProducer *woodProducer);
    WoodProducerLevelOneUpgrade(WoodProducerLevelOneUpgrade *woodprod);
    ~WoodProducerLevelOneUpgrade();
    void update();
    Entity *clone();
    int getOutput();
    int getLevel();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H
