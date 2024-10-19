#ifndef WOODPRODUCERUPGRADE_H
#define WOODPRODUCERUPGRADE_H

#include "WoodProducer.h"
class WoodProducerUpgrade : public WoodProducer
{
public:
    WoodProducerUpgrade();
    ~WoodProducerUpgrade();

protected:
    WoodProducer *WoodProducer;
};

#endif // WOODPRODUCERUPGRADE_H
