#include "WoodProducerUpgrade.h"

WoodProducerUpgrade::WoodProducerUpgrade(WoodProducer *woodProducer)  : WoodProducer(woodProducer)
{
    this->woodProducer = new WoodProducer(woodProducer);
}

WoodProducerUpgrade::WoodProducerUpgrade(WoodProducerUpgrade *woodProducerUpgrade) : WoodProducer(woodProducerUpgrade)
{
    this->woodProducer = new WoodProducer(woodProducerUpgrade->woodProducer);
}

WoodProducerUpgrade::~WoodProducerUpgrade()
{
    if (woodProducer != nullptr)
    {
        delete woodProducer;
        woodProducer = nullptr;
    }
}
