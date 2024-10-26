#include "StoneProducerIterator.h"

/**
 * @brief Construct a new Stone Producer Iterator:: Stone Producer Iterator object
 * 
 */
StoneProducerIterator::StoneProducerIterator():Iterator(){}
/**
 * @brief Destroy the Stone Producer Iterator:: Stone Producer Iterator object
 * 
 */
StoneProducerIterator::~StoneProducerIterator() {}

/**
 * @brief Construct a new Stone Producer Iterator:: Stone Producer Iterator object
 * 
 * @param grid 
 */
StoneProducerIterator::StoneProducerIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first StoneProducer instance in the grid.
 * 
 * Sets the iterator to the first ConcreteProducer found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
void StoneProducerIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*curr);

            if(stoneproducer){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Advances the iterator to the next StoneProducer instance in the grid.
 * 
 * Moves to the next StoneProducer in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void StoneProducerIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*curr);
            if(stoneproducer&& (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Checks if there is another StoneProducer instance in the grid after the current position.
 * 
 * @return true if another StoneProducer exists, false otherwise.
 */
bool StoneProducerIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); ++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); ++tempCurr){
            StoneProducer* stoneproducer = dynamic_cast<StoneProducer*>(*tempCurr);

            if(stoneproducer){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns current StoneProducer
 * 
 * @return Entity* 
 */
Entity* StoneProducerIterator::current(){
    return (*this->curr);
}