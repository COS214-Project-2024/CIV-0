
#ifndef STONEPRODUCERUPGRADE_H
#define STONEPRODUCERUPGRADE_H

#include "StoneProducer.h"
class StoneProducerUpgrade : public StoneProducer
{
public:
    StoneProducerUpgrade(StoneProducer *stoneProd);
    StoneProducerUpgrade(StoneProducerUpgrade *stoneProd);
    virtual ~StoneProducerUpgrade();

    virtual void update() = 0;
    virtual Entity *clone() = 0;
    virtual int getOutput() = 0;
    virtual Entity* upgrade() = 0;
    virtual Cost getCost() = 0;
    

protected:
    StoneProducer *stoneProducer; // mweheheheh nobodoy will see this comment
};

#endif // STONEPRODUCERUPGRADE_H
