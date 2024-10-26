#include "UtilityIterator.h"
/**
 * @brief Construct a new Utility Iterator:: Utility Iterator object
 * 
 */
UtilityIterator::UtilityIterator():Iterator(){}

/**
 * @brief Destroy the Utility Iterator:: Utility Iterator object
 * 
 */
UtilityIterator::~UtilityIterator() {}

/**
 * @brief Construct a new Utility Iterator:: Utility Iterator object
 * 
 * @param grid 
 */
UtilityIterator::UtilityIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief 
 * 
 */
void UtilityIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Utility* utility = dynamic_cast<Utility*>(*curr);

            if(utility){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief 
 * 
 */
void UtilityIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Utility* utility = dynamic_cast<Utility*>(*curr);
            if(utility&& (col!=Tcol || Trow!=row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }

    if(!found){
        col = 0;
        row = 0;
        for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            if(col==Tcol && Trow==row)return;
            col+=1;
        }
        row+=1;
    }  
    }
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool UtilityIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            Utility* utility = dynamic_cast<Utility*>(*tempCurr);

            if(utility){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief 
 * 
 * @return Entity* 
 */
Entity* UtilityIterator::current(){
    return (*this->curr);
}