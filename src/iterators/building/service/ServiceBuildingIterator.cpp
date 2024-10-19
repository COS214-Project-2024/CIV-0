#include "ServiceBuildingIterator.h"

ServiceBuildingIterator::ServiceBuildingIterator() {}
ServiceBuildingIterator::~ServiceBuildingIterator() {}

ServiceBuildingIterator::ServiceBuildingIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void ServiceBuildingIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ServiceBuilding* servicebuilding = dynamic_cast<ServiceBuilding*>(*curr);

            if(servicebuilding){found = true;break;}
        }
        if(found)break;
    }
}

void ServiceBuildingIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ServiceBuilding* servicebuilding = dynamic_cast<ServiceBuilding*>(*curr);

            if(servicebuilding){found = true;break;}
        }
        if(found)break;
    }
}

bool ServiceBuildingIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            ServiceBuilding* servicebuilding = dynamic_cast<ServiceBuilding*>(*tempCurr);

            if(servicebuilding){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

ServiceBuilding* ServiceBuildingIterator::current(){
    return dynamic_cast<ServiceBuilding*>(*this->curr);
}