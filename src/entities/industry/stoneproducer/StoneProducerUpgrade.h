#ifndef STONEPRODUCERUPGRADE_H
#define STONEPRODUCERUPGRADE_H

#include "StoneProducer.h"
#include "Entity.h"
class StoneProducerUpgrade : public StoneProducer
{
public:

    StoneProducerUpgrade();
    ~StoneProducerUpgrade();
    virtual Entity* clone() = 0;
    virtual void update() = 0;
    
private: 
    StoneProducer* stoneProducer; //mweheheheh nobodoy will see this comment
};

#endif // STONEPRODUCERUPGRADE_H
