
#ifndef CONCRETEPRODUCERLEVELONEUPGRADE_H
#define CONCRETEPRODUCERLEVELONEUPGRADE_H

#include "ConcreteProducerUpgrade.h"

class ConcreteProducerLevelOneUpgrade : public ConcreteProducerUpgrade
{
public:
    ConcreteProducerLevelOneUpgrade(ConcreteProducer *concreteProd);
    ConcreteProducerLevelOneUpgrade(ConcreteProducerLevelOneUpgrade *concreteProd);
    ~ConcreteProducerLevelOneUpgrade();
    void update();
    int getOutput();
    int getLevel() override;
    Entity *clone();

private:
    const int UPGRADE = 2;
};

#endif // CONCRETEPRODUCERLEVELONEUPGRADE_H
