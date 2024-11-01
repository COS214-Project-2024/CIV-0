#ifndef STONEPRODUCERLEVELTHREEUPGRADE_H
#define STONEPRODUCERLEVELTHREEUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelThreeUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelThreeUpgrade(StoneProducer *stoneProd);
    StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade *stoneProd);
    ~StoneProducerLevelThreeUpgrade();
    void update();
    int getOutput();
    int getLevel();
    Entity *clone();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 4;
};

#endif // STONEPRODUCERLEVELTHREEUPGRADE_H
