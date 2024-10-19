#include "WaterSupplyIterator.h"

WaterSupplyIterator::WaterSupplyIterator() {}
WaterSupplyIterator::~WaterSupplyIterator() {}

WaterSupplyIterator::WaterSupplyIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void WaterSupplyIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WaterSupply* watersupply = dynamic_cast<WaterSupply*>(*curr);

            if(watersupply){found = true;break;}
        }
        if(found)break;
    }
}

void WaterSupplyIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WaterSupply* watersupply = dynamic_cast<WaterSupply*>(*curr);

            if(watersupply){found = true;break;}
        }
        if(found)break;
    }
}

bool WaterSupplyIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            WaterSupply* watersupply = dynamic_cast<WaterSupply*>(*tempCurr);

            if(watersupply){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

WaterSupply* WaterSupplyIterator::current(){
    return dynamic_cast<WaterSupply*>(*this->curr);
}
