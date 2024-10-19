#ifndef STONEPRODUCERUPGRADE_H
#define STONEPRODUCERUPGRADE_H

#include "StoneProducer.h"
class StoneProducerUpgrade : public StoneProducer
{
public:
    StoneProducerUpgrade();
    ~StoneProducerUpgrade();

private:
    StoneProducer *stoneProducer; // mweheheheh nobodoy will see this comment
};

#endif // STONEPRODUCERUPGRADE_H
