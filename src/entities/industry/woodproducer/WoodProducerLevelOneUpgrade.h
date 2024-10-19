#ifndef WOODPRODUCERLEVELONEUPGRADE_H
#define WOODPRODUCERLEVELONEUPGRADE_H

#include "WoodProducerUpgrade.h"

class WoodProducerLevelOneUpgrade : public WoodProducerUpgrade
{
public:
    WoodProducerLevelOneUpgrade();
    ~WoodProducerLevelOneUpgrade();
    void update() override;
    Entity *clone() override;
    int getStrength();

private:
    const int UPGRADE = 1;
};

#endif // WOODPRODUCERLEVELONEUPGRADE_H
