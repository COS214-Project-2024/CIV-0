#include "ResidentialBuildingIterator.h"

ResidentialBuildingIterator::ResidentialBuildingIterator() {}
ResidentialBuildingIterator::~ResidentialBuildingIterator() {}

ResidentialBuildingIterator::ResidentialBuildingIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void ResidentialBuildingIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ResidentialBuilding* residentialbuilding = dynamic_cast<ResidentialBuilding*>(*curr);

            if(residentialbuilding){found = true;break;}
        }
        if(found)break;
    }
}

void ResidentialBuildingIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ResidentialBuilding* residentialbuilding = dynamic_cast<ResidentialBuilding*>(*curr);

            if(residentialbuilding){found = true;break;}
        }
        if(found)break;
    }
}

bool ResidentialBuildingIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            ResidentialBuilding* residentialbuilding = dynamic_cast<ResidentialBuilding*>(*tempCurr);

            if(residentialbuilding){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

ResidentialBuilding* ResidentialBuildingIterator::current(){
    return dynamic_cast<ResidentialBuilding*>(*this->curr);
}