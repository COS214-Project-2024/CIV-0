#ifndef STONEPRODUCERLEVELONEUPGRADE_H
#define STONEPRODUCERLEVELONEUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelTwoUgprade;
class StoneProducerLevelOneUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelOneUpgrade(StoneProducer *stoneProd);
    StoneProducerLevelOneUpgrade(StoneProducerLevelOneUpgrade *stoneProd);
    ~StoneProducerLevelOneUpgrade();
    int getOutput();
    int getLevel();
    Entity *clone();
    void update();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 2;
};

#endif // STONEPRODUCERLEVELONEUPGRADE_H
