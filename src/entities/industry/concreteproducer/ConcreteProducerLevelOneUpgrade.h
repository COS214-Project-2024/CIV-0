#ifndef CONCRETEPRODUCERLEVELONEUPGRADE_H
#define CONCRETEPRODUCERLEVELONEUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

class ConcreteProducerLevelTwoUpgrade;

class ConcreteProducerLevelOneUpgrade : public ConcreteProducerUpgrade
{
public:
    ConcreteProducerLevelOneUpgrade(ConcreteProducer *concreteProd);
    ConcreteProducerLevelOneUpgrade(ConcreteProducerLevelOneUpgrade *concreteProd);
    ~ConcreteProducerLevelOneUpgrade();
    void update();
    int getOutput();
    int getLevel();
    Entity *clone();
    Entity* upgrade();
    Cost getCost();
private:
    const int UPGRADE = 2;
};

#endif // CONCRETEPRODUCERLEVELONEUPGRADE_H
