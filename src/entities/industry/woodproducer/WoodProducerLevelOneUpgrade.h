
#ifndef WOODPRODUCERLEVELONEUPGRADE_H
#define WOODPRODUCERLEVELONEUPGRADE_H

#include "WoodProducerUpgrade.h"

class WoodProducerLevelOneUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelOneUpgrade(WoodProducer *woodProducer);
    WoodProducerLevelOneUpgrade(WoodProducerLevelOneUpgrade *woodprod);
    ~WoodProducerLevelOneUpgrade();
    void update();
    Entity *clone();
    int getOutput();
    int getLevel() override;

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H
