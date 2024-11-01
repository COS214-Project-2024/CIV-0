#ifndef WOODPRODUCERLEVELTWOUPGRADE_H
#define WOODPRODUCERLEVELTWOUPGRADE_H

#include "WoodProducerUpgrade.h"

class WoodProducerLevelThreeUpgrade;

class WoodProducerLevelTwoUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelTwoUpgrade(WoodProducer *woodProducer);
    WoodProducerLevelTwoUpgrade(WoodProducerLevelTwoUpgrade *woodProd);
    ~WoodProducerLevelTwoUpgrade();
    void update();
    int getOutput();
    int getLevel();
    Entity *clone();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELTWOUPGRADE_H
