#include "PowerPlantIterator.h"

/**
 * @brief Construct a new Power Plant Iterator:: Power Plant Iterator object
 * 
 */
PowerPlantIterator::PowerPlantIterator():Iterator(){}
/**
 * @brief Destroy the Power Plant Iterator:: Power Plant Iterator object
 * 
 */
PowerPlantIterator::~PowerPlantIterator() {}

/**
 * @brief Construct a new Power Plant Iterator:: Power Plant Iterator object
 * 
 * @param grid 
 */
PowerPlantIterator::PowerPlantIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first PowerPlant instance in the grid.
 * 
 * Sets the iterator to the first PowerPlant found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
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

/**
 * @brief Advances the iterator to the next PowerPlant instance in the grid.
 * 
 * Moves to the next PowerPlant in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void PowerPlantIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            if(*curr){
            Utility* check1 = dynamic_cast<Utility*>(*curr);
            PowerPlant* powerplant = dynamic_cast<PowerPlant*>(check1);
            if(powerplant&& (col!=Tcol || Trow!=row)){found = true;break;}
            }
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
 * @brief Checks if there is another PowerPlant instance in the grid after the current position.
 * 
 * @return true if another PowerPlant exists, false otherwise.
 */
bool PowerPlantIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            if(*tempCurr){
            Utility* check1 = dynamic_cast<Utility*>(*tempCurr);
            PowerPlant* powerplant = dynamic_cast<PowerPlant*>(check1);
            if(powerplant != NULL){found = true;break;}
            }
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
Entity* PowerPlantIterator::current(){
    return (*this->curr);
}