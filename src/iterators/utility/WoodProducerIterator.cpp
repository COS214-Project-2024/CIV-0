#include "WoodProducerIterator.h"
/**
 * @brief Construct a new Wood Producer Iterator:: Wood Producer Iterator object
 * 
 */
WoodProducerIterator::WoodProducerIterator():Iterator(){}

/**
 * @brief Destroy the Wood Producer Iterator:: Wood Producer Iterator object
 * 
 */
WoodProducerIterator::~WoodProducerIterator() {}

/**
 * @brief Construct a new Wood Producer Iterator:: Wood Producer Iterator object
 * 
 * @param grid 
 */
WoodProducerIterator::WoodProducerIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first WoodProducer instance in the grid.
 * 
 * Sets the iterator to the first WoodProducer found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
void WoodProducerIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WoodProducer* woodproducer = dynamic_cast<WoodProducer*>(*curr);

            if(woodproducer){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Advances the iterator to the next WoodProducer instance in the grid.
 * 
 * Moves to the next WoodProducer in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void WoodProducerIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            WoodProducer* woodproducer = dynamic_cast<WoodProducer*>(*curr);
            if(woodproducer&& (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Checks if there is another WoodProducer instance in the grid after the current position.
 * 
 * @return true if another WoodProducer exists, false otherwise.
 */
bool WoodProducerIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end(); ++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); ++tempCurr){
            WoodProducer* woodproducer = dynamic_cast<WoodProducer*>(*tempCurr);

            if(woodproducer){found = true;break;}
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
Entity* WoodProducerIterator::current(){
    return (*this->curr);
}