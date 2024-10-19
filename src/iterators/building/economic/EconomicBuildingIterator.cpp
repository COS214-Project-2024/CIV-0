#include "EconomicBuildingIterator.h"

EconomicBuildingIterator::EconomicBuildingIterator() {}
EconomicBuildingIterator::~EconomicBuildingIterator() {}

EconomicBuildingIterator::EconomicBuildingIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void EconomicBuildingIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            EconomicBuilding* economicbuilding = dynamic_cast<EconomicBuilding*>(*curr);

            if(economicbuilding){found = true;break;}
        }
        if(found)break;
    }
}

void EconomicBuildingIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            EconomicBuilding* economicbuilding = dynamic_cast<EconomicBuilding*>(*curr);

            if(economicbuilding){found = true;break;}
        }
        if(found)break;
    }
}

bool EconomicBuildingIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            EconomicBuilding* economicbuilding = dynamic_cast<EconomicBuilding*>(*tempCurr);

            if(economicbuilding){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

EconomicBuilding* EconomicBuildingIterator::current(){
    return dynamic_cast<EconomicBuilding*>(*this->curr);
}