#include "WaterSupplyIterator.h"

/**
 * @brief Construct a new Water Supply Iterator:: Water Supply Iterator object
 * 
 */
WaterSupplyIterator::WaterSupplyIterator() {}

/**
 * @brief Destroy the Water Supply Iterator:: Water Supply Iterator object
 * 
 */
WaterSupplyIterator::~WaterSupplyIterator() {}

/**
 * @brief Construct a new Water Supply Iterator:: Water Supply Iterator object
 * 
 * @param grid 
 */
WaterSupplyIterator::WaterSupplyIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first WaterSupply instance in the grid.
 * 
 * Sets the iterator to the first WaterSupply found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
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

/**
 * @brief Advances the iterator to the next WaterSupply instance in the grid.
 * 
 * Moves to the next WaterSupply in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void WaterSupplyIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            WaterSupply* watersupply = dynamic_cast<WaterSupply*>(*curr);
            if(watersupply&& (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Checks if there is another WaterSupply instance in the grid after the current position.
 * 
 * @return true if another WaterSupply exists, false otherwise.
 */
bool WaterSupplyIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); ++tempCurr){
            WaterSupply* watersupply = dynamic_cast<WaterSupply*>(*tempCurr);

            if(watersupply){found = true;break;}
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
Entity* WaterSupplyIterator::current(){
    return (*this->curr);
}
