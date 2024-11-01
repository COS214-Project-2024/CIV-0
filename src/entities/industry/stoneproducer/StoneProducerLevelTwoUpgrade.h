
#ifndef STONEPRODUCERLEVELTWOUPGRADE_H
#define STONEPRODUCERLEVELTWOUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelThreeUpgrade;

class StoneProducerLevelTwoUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelTwoUpgrade(StoneProducer *stoneProd);
    StoneProducerLevelTwoUpgrade(StoneProducerLevelTwoUpgrade *stoneProd);
    ~StoneProducerLevelTwoUpgrade();
    Entity *clone() override;
    void update() override;
    int getOutput() override;
    int getLevel() override;
    Entity *upgrade() override;
    Cost getCost() override;

private:
    const int UPGRADE = 2;
};

#endif // STONEPRODUCERLEVELTWOUPGRADE_H
