
#ifndef CONCRETEPRODUCERLEVELTHREEUPGRADE_H
#define CONCRETEPRODUCERLEVELTHREEUPGRADE_H

#include "ConcreteProducerUpgrade.h"

class ConcreteProducerLevelThreeUpgrade : public ConcreteProducerUpgrade
{
public:
    ConcreteProducerLevelThreeUpgrade(ConcreteProducer* concreteProd);
    ConcreteProducerLevelThreeUpgrade(ConcreteProducerLevelThreeUpgrade* concreteProd);
    ~ConcreteProducerLevelThreeUpgrade();
    int getOutput();
    void update();
    Entity* clone();
private: 
    const int UPGRADE = 4;
};

#endif // CONCRETEPRODUCERLEVELTHREEUPGRADE_H
