#ifndef STONEPRODUCERLEVELONEUPGRADE_H
#define STONEPRODUCERLEVELONEUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelOneUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelOneUpgrade(StoneProducer* stoneProd);
    StoneProducerLevelOneUpgrade(StoneProducerLevelOneUpgrade* stoneProd);
    ~StoneProducerLevelOneUpgrade();
    int getOutput();
    Entity* clone();
    void update();
private: 
    const int UPGRADE = 1.5;
};

#endif // STONEPRODUCERLEVELONEUPGRADE_H
