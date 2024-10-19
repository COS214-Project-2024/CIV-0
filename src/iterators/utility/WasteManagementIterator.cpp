#include "WasteManagementIterator.h"

WasteManagementIterator::WasteManagementIterator() {}
WasteManagementIterator::~WasteManagementIterator() {}

WasteManagementIterator::WasteManagementIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void WasteManagementIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WasteManagement* wastemanagement = dynamic_cast<WasteManagement*>(*curr);

            if(wastemanagement){found = true;break;}
        }
        if(found)break;
    }
}

void WasteManagementIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WasteManagement* wastemanagement = dynamic_cast<WasteManagement*>(*curr);

            if(wastemanagement){found = true;break;}
        }
        if(found)break;
    }
}

bool WasteManagementIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            WasteManagement* wastemanagement = dynamic_cast<WasteManagement*>(*tempCurr);

            if(wastemanagement){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

WasteManagement* WasteManagementIterator::current(){
    return dynamic_cast<WasteManagement*>(*this->curr);
}