#include "BuildingIterator.h"

BuildingIterator::BuildingIterator() {}
BuildingIterator::~BuildingIterator() {}

BuildingIterator::BuildingIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void BuildingIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Building* building = dynamic_cast<Building*>(*curr);

            if(building){found = true;break;}
        }
        if(found)break;
    }
}

void BuildingIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Building* building = dynamic_cast<Building*>(*curr);

            if(building){found = true;break;}
        }
        if(found)break;
    }
}

bool BuildingIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Building* building = dynamic_cast<Building*>(*tempCurr);

            if(building){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Building* BuildingIterator::current(){
    return dynamic_cast<Building*>(*this->curr);
}