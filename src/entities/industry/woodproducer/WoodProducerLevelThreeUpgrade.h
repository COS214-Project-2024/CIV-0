#ifndef WOODPRODUCERLEVELTHREEUPGRADE_H
#define WOODPRODUCERLEVELTHREEUPGRADE_H

#include "WoodProducerUpgrade.h"
class WoodProducerLevelThreeUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelThreeUpgrade(WoodProducer* woodProd);
    WoodProducerLevelThreeUpgrade(WoodProducerLevelThreeUpgrade* woodProd);
    ~WoodProducerLevelThreeUpgrade();
    void update() override;
    Entity *clone() override;
    int getOutput();
private:
    const int UPGRADE = 4;
};

#endif // WOODPRODUCERLEVELTHREEUPGRADE_H
