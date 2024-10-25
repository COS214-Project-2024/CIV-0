#ifndef WOODPRODUCERLEVELTWOUPGRADE_H
#define WOODPRODUCERLEVELTWOUPGRADE_H

#include "WoodProducerUpgrade.h"
class WoodProducerLevelTwoUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelTwoUpgrade(class WoodProducer *woodProducer);
    ~WoodProducerLevelTwoUpgrade();
    void update();
    Entity *clone();
    int getStrength();
private: 
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELTWOUPGRADE_H
