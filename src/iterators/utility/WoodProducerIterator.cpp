#include "WoodProducerIterator.h"

WoodProducerIterator::WoodProducerIterator() {}
WoodProducerIterator::~WoodProducerIterator() {}

WoodProducerIterator::WoodProducerIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void WoodProducerIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WoodProducer* woodproducer = dynamic_cast<WoodProducer*>(*curr);

            if(woodproducer){found = true;break;}
        }
        if(found)break;
    }
}

void WoodProducerIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WoodProducer* woodproducer = dynamic_cast<WoodProducer*>(*curr);

            if(woodproducer){found = true;break;}
        }
        if(found)break;
    }
}

bool WoodProducerIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            WoodProducer* woodproducer = dynamic_cast<WoodProducer*>(*tempCurr);

            if(woodproducer){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

WoodProducer* WoodProducerIterator::current(){
    return dynamic_cast<WoodProducer*>(*this->curr);
}