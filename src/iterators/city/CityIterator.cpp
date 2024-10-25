#include "CityIterator.h"

CityIterator::CityIterator():Iterator(){
    this->row = 0;
    this->col = 0;
}
CityIterator::~CityIterator() {}

CityIterator::CityIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
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
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Entity* entity = dynamic_cast<Entity*>(*curr);
            if(entity){found = true;break;}
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
    return (*this->curr);
}