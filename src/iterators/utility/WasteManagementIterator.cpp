#include "WasteManagementIterator.h"

WasteManagementIterator::WasteManagementIterator():Iterator(){}
WasteManagementIterator::~WasteManagementIterator() {}

WasteManagementIterator::WasteManagementIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
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
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            WasteManagement* wastemanagement = dynamic_cast<WasteManagement*>(*curr);
            if(wastemanagement&& (col!=Tcol || Trow!=row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }

    if(!found){
        col = 0;
        row = 0;
        for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            if(col==Tcol && Trow==row)return;
            col+=1;
        }
        row+=1;
    }  
    }
}

bool WasteManagementIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end(); ++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            WasteManagement* wastemanagement = dynamic_cast<WasteManagement*>(*tempCurr);

            if(wastemanagement){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Entity* WasteManagementIterator::current(){
    return (*this->curr);
}