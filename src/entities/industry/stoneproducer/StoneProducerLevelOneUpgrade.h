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
    int getOutput() override;
    int getLevel() override;
    Entity *clone() override;
    void update() override;
    Entity *upgrade() override;
    Cost getCost() override;

private:
    const int UPGRADE = 2;
};

#endif // STONEPRODUCERLEVELONEUPGRADE_H
