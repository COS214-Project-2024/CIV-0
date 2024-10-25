#include "SewageSystemIterator.h"

SewageSystemIterator::SewageSystemIterator() {}
SewageSystemIterator::~SewageSystemIterator() {}

SewageSystemIterator::SewageSystemIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

void SewageSystemIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*curr);

            if(sewagesystem){found = true;break;}
        }
        if(found)break;
    }
}

void SewageSystemIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*curr);
            if(sewagesystem){found = true;break;}
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

bool SewageSystemIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*tempCurr);

            if(sewagesystem){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Entity* SewageSystemIterator::current(){
    return (*this->curr);
}