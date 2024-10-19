#include "UtilityIterator.h"

UtilityIterator::UtilityIterator() {}
UtilityIterator::~UtilityIterator() {}

UtilityIterator::UtilityIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void UtilityIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Utility* utility = dynamic_cast<Utility*>(*curr);

            if(utility){found = true;break;}
        }
        if(found)break;
    }
}

void UtilityIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Utility* utility = dynamic_cast<Utility*>(*curr);

            if(utility){found = true;break;}
        }
        if(found)break;
    }
}

bool UtilityIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Utility* utility = dynamic_cast<Utility*>(*tempCurr);

            if(utility){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Utility* UtilityIterator::current(){
    return dynamic_cast<Utility*>(*this->curr);
}