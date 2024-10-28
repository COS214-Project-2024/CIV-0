#include "BuildingIterator.h"

/**
 * @brief Construct a new Building Iterator:: Building Iterator object
 * 
 */
BuildingIterator::BuildingIterator():Iterator(){
    this->row = 0;
    this-> col = 0;
}
/**
 * @brief Destroy the Building Iterator:: Building Iterator object
 * 
 */
BuildingIterator::~BuildingIterator() {}

/**
 * @brief Construct a new Building Iterator:: Building Iterator object
 * 
 * @param grid 
 */
BuildingIterator::BuildingIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

/**
 * @brief Goes tp first Building
 * 
 */
void BuildingIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Building* building = dynamic_cast<Building*>(*curr);

            if(building){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Goes to next Building
 * 
 */
void BuildingIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Building* building = dynamic_cast<Building*>(*curr);
            if(building){found = true;break;}
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
 * @brief Determines if there is next Building
 * 
 * @return true 
 * @return false 
 */
bool BuildingIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Building* building = dynamic_cast<Building*>(*tempCurr);

            if(building){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns current Building
 * 
 * @return Entity* 
 */
Entity* BuildingIterator::current(){
    return (*this->curr);
}