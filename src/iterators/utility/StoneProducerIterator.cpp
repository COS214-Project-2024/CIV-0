#include "StoneProducerIterator.h"

StoneProducerIterator::StoneProducerIterator() {}
StoneProducerIterator::~StoneProducerIterator() {}

StoneProducerIterator::StoneProducerIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void StoneProducerIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*curr);

            if(stoneproducer){found = true;break;}
        }
        if(found)break;
    }
}

void StoneProducerIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*curr);

            if(stoneproducer){found = true;break;}
        }
        if(found)break;
    }
}

bool StoneProducerIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*tempCurr);

            if(stoneproducer){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

StoneProducer* StoneProducerIterator::current(){
    return dynamic_cast<StoneProducer*>(*this->curr);
}