
#ifndef WOODPRODUCERUPGRADE_H
#define WOODPRODUCERUPGRADE_H

#include "WoodProducer.h"
class WoodProducerUpgrade : public WoodProducer
{
public:
    WoodProducerUpgrade(WoodProducer* woodProducer);
    virtual ~WoodProducerUpgrade();
    WoodProducerUpgrade(WoodProducerUpgrade* woodProducerUpgrade);
    virtual void update() = 0;
    virtual int getOutput() = 0;

protected:
    WoodProducer* woodProducer;
};

#endif // WOODPRODUCERUPGRADE_H
