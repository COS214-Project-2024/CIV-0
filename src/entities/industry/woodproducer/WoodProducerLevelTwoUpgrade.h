#ifndef WOODPRODUCERLEVELTWOUPGRADE_H
#define WOODPRODUCERLEVELTWOUPGRADE_H

#include "WoodProducerUpgrade.h"
#include "WoodProducer.h"
class WoodProducerLevelTwoUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelTwoUpgrade(WoodProducer* woodProducer);
    ~WoodProducerLevelTwoUpgrade();
    void update();
    Entity* clone();
    int getStrength();
};

#endif // WOODPRODUCERLEVELTWOUPGRADE_H
