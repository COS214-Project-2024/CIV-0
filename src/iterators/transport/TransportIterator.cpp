#include "TransportIterator.h"

TransportIterator::TransportIterator() {}
TransportIterator::~TransportIterator() {}

TransportIterator::TransportIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void TransportIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Transport* transport = dynamic_cast<Transport*>(*curr);

            if(transport){found = true;break;}
        }
        if(found)break;
    }
}

void TransportIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Transport* transport = dynamic_cast<Transport*>(*curr);

            if(transport){found = true;break;}
        }
        if(found)break;
    }
}

bool TransportIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Transport* transport = dynamic_cast<Transport*>(*tempCurr);

            if(transport){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Transport* TransportIterator::current(){
    return dynamic_cast<Transport*>(*this->curr);
}