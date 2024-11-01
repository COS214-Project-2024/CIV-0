#ifndef CONCRETEPRODUCERLEVELTWOUPGRADE_H
#define CONCRETEPRODUCERLEVELTWOUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

class ConcreteProducerLevelThreeUpgrade;

class ConcreteProducerLevelTwoUpgrade : public ConcreteProducerUpgrade
{
public:
    ConcreteProducerLevelTwoUpgrade(ConcreteProducer *concreteProd);
    ConcreteProducerLevelTwoUpgrade(ConcreteProducerLevelTwoUpgrade *concreteProd);
    ~ConcreteProducerLevelTwoUpgrade();
    void update();
    int getOutput();
    int getLevel();
    Entity *clone();
    Cost getCost();
    Entity* upgrade();

private:
    const int UPGRADE = 2;
};

#endif // CONCRETEPRODUCERLEVELTWOUPGRADE_H
