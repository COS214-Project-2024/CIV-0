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
    void update() override;
    int getOutput() override;
    int getLevel() override;
    Entity *clone() override;
    Entity *upgrade() override;
    Cost getCost() override;

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELTWOUPGRADE_H
