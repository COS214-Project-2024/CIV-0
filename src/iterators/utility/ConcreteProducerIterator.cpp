#include "ConcreteProducerIterator.h"

ConcreteProducerIterator::ConcreteProducerIterator() {}
ConcreteProducerIterator::~ConcreteProducerIterator() {}

ConcreteProducerIterator::ConcreteProducerIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void ConcreteProducerIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(*curr);

            if(concreteproducer){found = true;break;}
        }
        if(found)break;
    }
}

void ConcreteProducerIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(*curr);

            if(concreteproducer){found = true;break;}
        }
        if(found)break;
    }
}

bool ConcreteProducerIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(*tempCurr);

            if(concreteproducer){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

ConcreteProducer* ConcreteProducerIterator::current(){
    return dynamic_cast<ConcreteProducer*>(*this->curr);
}