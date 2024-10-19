#ifndef WOODPRODUCERUPGRADE_H
#define WOODPRODUCERUPGRADE_H
 

#include "WoodProducer.h"
#include "Entity.h"
class WoodProducerUpgrade : public WoodProducer
{
public:

    WoodProducerUpgrade();
    ~WoodProducerUpgrade();
    virtual Entity* clone() = 0;
    virtual void update() = 0;
    
private: 
    WoodProducer* WoodProducer;
    
};

#endif // WOODPRODUCERUPGRADE_H
