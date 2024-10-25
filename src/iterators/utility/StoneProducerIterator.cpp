#include "StoneProducerIterator.h"

StoneProducerIterator::StoneProducerIterator():Iterator(){}
StoneProducerIterator::~StoneProducerIterator() {}

StoneProducerIterator::StoneProducerIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
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
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*curr);
            if(stoneproducer){found = true;break;}
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

Entity* StoneProducerIterator::current(){
    return (*this->curr);
}