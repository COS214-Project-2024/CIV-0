#include "SewageSystemIterator.h"

SewageSystemIterator::SewageSystemIterator() {}
SewageSystemIterator::~SewageSystemIterator() {}

SewageSystemIterator::SewageSystemIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void SewageSystemIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*curr);

            if(sewagesystem){found = true;break;}
        }
        if(found)break;
    }
}

void SewageSystemIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*curr);

            if(sewagesystem){found = true;break;}
        }
        if(found)break;
    }
}

bool SewageSystemIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*tempCurr);

            if(sewagesystem){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

SewageSystem* SewageSystemIterator::current(){
    return dynamic_cast<SewageSystem*>(*this->curr);
}