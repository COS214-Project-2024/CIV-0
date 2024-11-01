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
    void update() override;
    int getOutput() override;
    int getLevel() override;
    Entity *clone() override;
    Entity *upgrade() override;
    Cost getCost() override;

private:
    const int UPGRADE = 2;
};

#endif // CONCRETEPRODUCERLEVELONEUPGRADE_H
