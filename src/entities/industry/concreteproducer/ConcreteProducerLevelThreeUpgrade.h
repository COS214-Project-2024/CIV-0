#ifndef CONCRETEPRODUCERLEVELTHREEUPGRADE_H
#define CONCRETEPRODUCERLEVELTHREEUPGRADE_H

#include "entities/industry/concreteproducer/ConcreteProducerUpgrade.h"

class ConcreteProducerLevelThreeUpgrade : public ConcreteProducerUpgrade {
public:
    ConcreteProducerLevelThreeUpgrade(ConcreteProducer* concreteProd);
    ConcreteProducerLevelThreeUpgrade(ConcreteProducerLevelThreeUpgrade* concreteProd);
    ~ConcreteProducerLevelThreeUpgrade();
    int getOutput();
    void update();
    int getLevel();
    Entity *clone();
    Cost getCost();
    Entity *upgrade();

private:
    const int UPGRADE = 4;
};

#endif // CONCRETEPRODUCERLEVELTHREEUPGRADE_H
