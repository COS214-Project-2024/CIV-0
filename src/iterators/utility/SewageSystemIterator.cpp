#include "SewageSystemIterator.h"
/**
 * @brief Construct a new Sewage System Iterator:: Sewage System Iterator object
 * 
 */
SewageSystemIterator::SewageSystemIterator() {}

/**
 * @brief Destroy the Sewage System Iterator:: Sewage System Iterator object
 * 
 */
SewageSystemIterator::~SewageSystemIterator() {}

/**
 * @brief Construct a new Sewage System Iterator:: Sewage System Iterator object
 * 
 * @param grid 
 */
SewageSystemIterator::SewageSystemIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first SewageSystem instance in the grid.
 * 
 * Sets the iterator to the first SewageSystem found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
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

/**
 * @brief Advances the iterator to the next SewageSystm instance in the grid.
 * 
 * Moves to the next SewageSystem in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void SewageSystemIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*curr);
            if(sewagesystem&& (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Advances the iterator to the next SewageSystem instance in the grid.
 * 
 * Moves to the next SewageSystem in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
bool SewageSystemIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end(); ++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); ++tempCurr){
            SewageSystem* sewagesystem = dynamic_cast<SewageSystem*>(*tempCurr);

            if(sewagesystem){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns the current Entity instance pointed to by the iterator.
 * 
 * @return A pointer to the current Entity instance.
 */
Entity* SewageSystemIterator::current(){
    return (*this->curr);
}