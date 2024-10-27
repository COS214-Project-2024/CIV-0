#include "RoadIterator.h"
/**
 * @brief Construct a new Road Iterator:: Road Iterator object
 * 
 */
RoadIterator::RoadIterator():Iterator(){}

/**
 * @brief Destroy the Road Iterator:: Road Iterator object
 * 
 */
RoadIterator::~RoadIterator() {}

/**
 * @brief Construct a new Road Iterator:: Road Iterator object
 * 
 * @param grid 
 */
RoadIterator::RoadIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Goes to first Road
 * 
 */
void RoadIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Road* road = dynamic_cast<Road*>(*curr);

            if(road){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Goes to next Road
 * 
 */
void RoadIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Road* road = dynamic_cast<Road*>(*curr);
            if(road && (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Determines if there is next Road
 * 
 * @return true 
 * @return false 
 */
bool RoadIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            Road* road = dynamic_cast<Road*>(*tempCurr);

            if(road){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns current Road
 * 
 * @return Entity* 
 */
Entity* RoadIterator::current(){
    return (*this->curr);
}