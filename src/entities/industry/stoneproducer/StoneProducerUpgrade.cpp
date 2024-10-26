#include "StoneProducerUpgrade.h"

StoneProducerUpgrade::StoneProducerUpgrade(StoneProducer* stoneProd) : StoneProducer(stoneProd) {
    this->stoneProducer = stoneProd;
}

StoneProducerUpgrade::StoneProducerUpgrade(StoneProducerUpgrade* stoneProd) : StoneProducer(stoneProd) {
    this->stoneProducer = stoneProd->stoneProducer;
}

StoneProducerUpgrade::~StoneProducerUpgrade() {}
