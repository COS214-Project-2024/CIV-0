#include "ConcreteProducerIterator.h"

ConcreteProducerIterator::ConcreteProducerIterator():Iterator(){}
ConcreteProducerIterator::~ConcreteProducerIterator() {}

ConcreteProducerIterator::ConcreteProducerIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
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
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(*curr);
            if(concreteproducer){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }

    if(!found){
        col = 0;
        row = 0;
        for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            if(col==Tcol && Trow==row)return;
            col+=1;
        }
        row+=1;
    }  
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

Entity* ConcreteProducerIterator::current(){
    return (*this->curr);
}