#ifndef STONEPRODUCERLEVELTHREEUPGRADE_H
#define STONEPRODUCERLEVELTHREEUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelThreeUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelThreeUpgrade(StoneProducer *stoneProd);
    StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade *stoneProd);
    ~StoneProducerLevelThreeUpgrade();
    void update() override;
    int getOutput() override;
    int getLevel() override;
    Entity *clone() override;
    Entity *upgrade() override;
    Cost getCost() override;

private:
    const int UPGRADE = 4;
};

#endif // STONEPRODUCERLEVELTHREEUPGRADE_H
