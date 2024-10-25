#include "WoodProducerUpgrade.h"

WoodProducerUpgrade::WoodProducerUpgrade(WoodProducer* WoodProducer) : WoodProducer(woodProducer) {
    this->woodProducer = woodProducer;
}

WoodProducerUpgrade::WoodProducerUpgrade(WoodProducerUpgrade* woodProducerUpgrade) : WoodProducer(woodProducerUpgrade) {
    this->woodProducer = woodProducerUpgrade->woodProducer;
}

WoodProducerUpgrade::~WoodProducerUpgrade() {

}


