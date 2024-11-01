
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
    int getOutput();
    int getLevel();
    Entity *clone();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H
