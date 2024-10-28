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
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            StoneProducer* e = dynamic_cast<StoneProducer*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
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
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            StoneProducer* e = dynamic_cast<StoneProducer*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Checks if there is another StoneProducer instance in the grid after the current position.
 * 
 * @return true if another StoneProducer exists, false otherwise.
 */
bool StoneProducerIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            StoneProducer* a = dynamic_cast<StoneProducer*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current StoneProducer
 * 
 * @return Entity* 
 */
Entity* StoneProducerIterator::current(){
    return (*this->curr);
}