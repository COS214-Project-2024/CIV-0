#ifndef STONEPRODUCERLEVELONEUPGRADE_H
#define STONEPRODUCERLEVELONEUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelOneUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelOneUpgrade(StoneProducer *stoneProd);
    StoneProducerLevelOneUpgrade(StoneProducerLevelOneUpgrade *stoneProd);
    ~StoneProducerLevelOneUpgrade();
    int getOutput();
    int getLevel() override;
    Entity *clone();
    void update();
    Entity* upgrade();
    Cost getCost();

private:
    const int UPGRADE = 1.5;
};

#endif // STONEPRODUCERLEVELONEUPGRADE_H
