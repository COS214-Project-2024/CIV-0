
#ifndef WOODPRODUCERLEVELONEUPGRADE_H
#define WOODPRODUCERLEVELONEUPGRADE_H

#include "WoodProducerUpgrade.h"

class WoodProducerLevelTwoUpgrade;
class WoodProducerLevelOneUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelOneUpgrade(WoodProducer *woodProducer);
    WoodProducerLevelOneUpgrade(WoodProducerLevelOneUpgrade *woodprod);
    ~WoodProducerLevelOneUpgrade();
    void update() override;
    Entity *clone() override;
    int getOutput() override;
    int getLevel() override;
    Entity *upgrade() override;
    Cost getCost() override;

private:
    const int UPGRADE = 2;
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H
