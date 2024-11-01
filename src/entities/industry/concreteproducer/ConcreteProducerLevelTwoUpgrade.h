
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
    void update() override;
    int getOutput() override;
    int getLevel() override;
    Entity *clone() override;
    Cost getCost() override;
    Entity *upgrade() override;

private:
    const int UPGRADE = 2;
};

#endif // CONCRETEPRODUCERLEVELTWOUPGRADE_H
