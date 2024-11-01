
#ifndef WOODPRODUCERLEVELTWOUPGRADE_H
#define WOODPRODUCERLEVELTWOUPGRADE_H

#include "WoodProducerUpgrade.h"
class WoodProducerLevelTwoUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelTwoUpgrade(WoodProducer *woodProducer);
    WoodProducerLevelTwoUpgrade(WoodProducerLevelTwoUpgrade *woodProd);
    ~WoodProducerLevelTwoUpgrade();
    void update();
    Entity *clone();
    int getOutput();
    int getLevel() override;

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELTWOUPGRADE_H
