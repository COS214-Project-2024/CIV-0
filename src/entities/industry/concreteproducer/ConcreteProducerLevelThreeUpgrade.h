
#ifndef CONCRETEPRODUCERLEVELTHREEUPGRADE_H
#define CONCRETEPRODUCERLEVELTHREEUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

class ConcreteProducerLevelThreeUpgrade : public ConcreteProducerUpgrade
{
public:
    ConcreteProducerLevelThreeUpgrade(ConcreteProducer *concreteProd);
    ConcreteProducerLevelThreeUpgrade(ConcreteProducerLevelThreeUpgrade *concreteProd);
    ~ConcreteProducerLevelThreeUpgrade();
    int getOutput() override;
    void update() override;
    int getLevel() override;
    Entity *clone() override;
    Cost getCost() override;
    Entity *upgrade() override;

private:
    const int UPGRADE = 4;
};

#endif // CONCRETEPRODUCERLEVELTHREEUPGRADE_H
