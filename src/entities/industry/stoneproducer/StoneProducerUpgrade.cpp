#include "StoneProducerUpgrade.h"

StoneProducerUpgrade::StoneProducerUpgrade(StoneProducer *stoneProd) : StoneProducer(stoneProd)
{
    this->stoneProducer = new StoneProducer(stoneProd);
}

StoneProducerUpgrade::StoneProducerUpgrade(StoneProducerUpgrade *stoneProd) : StoneProducer(stoneProd)
{
    this->stoneProducer = new StoneProducer(stoneProd->stoneProducer);
}

StoneProducerUpgrade::~StoneProducerUpgrade()
{
    if (stoneProducer != nullptr)
    {
        delete stoneProducer;
        stoneProducer = nullptr;
    }
}