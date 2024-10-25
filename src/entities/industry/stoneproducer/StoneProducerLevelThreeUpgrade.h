#ifndef STONEPRODUCERLEVELTHREEUPGRADE_H
#define STONEPRODUCERLEVELTHREEUPGRADE_H

#include "StoneProducerUpgrade.h"

class StoneProducerLevelThreeUpgrade : public StoneProducerUpgrade
{
public:
    StoneProducerLevelThreeUpgrade(StoneProducer* stoneProd);
    StoneProducerLevelThreeUpgrade(StoneProducerLevelThreeUpgrade* stoneProd);
    ~StoneProducerLevelThreeUpgrade();
    void update();
    int getOutput();
    Entity* clone();
private:
    const int UPGRADE = 4;
};

#endif // STONEPRODUCERLEVELTHREEUPGRADE_H
