#include "PowerPlantIterator.h"

PowerPlantIterator::PowerPlantIterator() {}
PowerPlantIterator::~PowerPlantIterator() {}

PowerPlantIterator::PowerPlantIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void PowerPlantIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            PowerPlant* powerplant = dynamic_cast<PowerPlant*>(*curr);

            if(powerplant){found = true;break;}
        }
        if(found)break;
    }
}

void PowerPlantIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            PowerPlant* powerplant = dynamic_cast<PowerPlant*>(*curr);

            if(powerplant){found = true;break;}
        }
        if(found)break;
    }
}

bool PowerPlantIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            PowerPlant* powerplant = dynamic_cast<PowerPlant*>(*tempCurr);

            if(powerplant){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

PowerPlant* PowerPlantIterator::current(){
    return dynamic_cast<PowerPlant*>(*this->curr);
}