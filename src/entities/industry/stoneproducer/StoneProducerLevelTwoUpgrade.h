
#ifndef STONEPRODUCERLEVELTWOUPGRADE_H
#define STONEPRODUCERLEVELTWOUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelTwoUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelTwoUpgrade(StoneProducer* stoneProd);
    StoneProducerLevelTwoUpgrade(StoneProducerLevelTwoUpgrade* stoneProd);
    ~StoneProducerLevelTwoUpgrade();
    Entity* clone();
    void update();
    int getOutput();
private: 
    const int UPGRADE = 2;
};

#endif // STONEPRODUCERLEVELTWOUPGRADE_H
