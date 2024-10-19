#include "CityIterator.h"

CityIterator::CityIterator() {}
CityIterator::~CityIterator() {}

CityIterator::CityIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void CityIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Entity* entity = dynamic_cast<Entity*>(*curr);

            if(entity){found = true;break;}
        }
        if(found)break;
    }
}

void CityIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Entity* entity = dynamic_cast<Entity*>(*curr);

            if(entity){found = true;break;}
        }
        if(found)break;
    }
}

bool CityIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Entity* entity = dynamic_cast<Entity*>(*tempCurr);

            if(entity){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Entity* CityIterator::current(){
    return dynamic_cast<Entity*>(*this->curr);
}