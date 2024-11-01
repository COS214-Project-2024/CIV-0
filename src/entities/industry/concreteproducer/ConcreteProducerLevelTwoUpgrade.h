
#ifndef CONCRETEPRODUCERLEVELTWOUPGRADE_H
#define CONCRETEPRODUCERLEVELTWOUPGRADE_H

#include "ConcreteProducerUpgrade.h"

class ConcreteProducerLevelTwoUpgrade : public ConcreteProducerUpgrade
{
public:
    ConcreteProducerLevelTwoUpgrade(ConcreteProducer *concreteProd);
    ConcreteProducerLevelTwoUpgrade(ConcreteProducerLevelTwoUpgrade *concreteProd);
    ~ConcreteProducerLevelTwoUpgrade();
    void update();
    int getOutput();
    int getLevel() override;
    Entity *clone();

private:
    const int UPGRADE = 2;
};

#endif // CONCRETEPRODUCERLEVELTWOUPGRADE_H
