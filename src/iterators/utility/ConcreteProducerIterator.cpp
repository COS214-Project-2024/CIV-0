#include "ConcreteProducerIterator.h"
#include <iostream>
/**
 * @brief Construct a new Concrete Producer Iterator:: Concrete Producer Iterator object
 * 
 */
ConcreteProducerIterator::ConcreteProducerIterator():Iterator(){}

/**
 * @brief Destroy the Concrete Producer Iterator:: Concrete Producer Iterator object
 * 
 */
ConcreteProducerIterator::~ConcreteProducerIterator() {}

/**
 * @brief Construct a new Concrete Producer Iterator:: Concrete Producer Iterator object
 * 
 * @param grid 
 */
ConcreteProducerIterator::ConcreteProducerIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first ConcreteProducer instance in the grid.
 * 
 * Sets the iterator to the first ConcreteProducer found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
void ConcreteProducerIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(*curr);

            if(concreteproducer){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Advances the iterator to the next ConcreteProducer instance in the grid.
 * 
 * Moves to the next ConcreteProducer in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void ConcreteProducerIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();curr++){
            if(*curr){
            Industry* check1 = dynamic_cast<Industry*>(*curr);
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(check1);
            if(concreteproducer && (col!=Tcol || Trow!=row)){found = true;break;}
            }
            col+=1;
        }
        if(found)break;
        row+=1;
    }

    if(!found){
        col = 0;
        row = 0;
        for(currRow=grid.begin();currRow != this->grid.end();++currRow){
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
 * @brief Checks if there is another ConcreteProducer instance in the grid after the current position.
 * 
 * @return true if another ConcreteProducer exists, false otherwise.
 */
bool ConcreteProducerIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
            //std::cout<<"rowHere"<<std::endl;
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            //std::cout<<"colHere"<<std::endl;
            //Entity* check0 = dynamic_cast<Entity*>(*curr);
            //Industry* check1 = dynamic_cast<Industry*>(check0);
            ConcreteProducer* concreteproducer = dynamic_cast<ConcreteProducer*>(*curr);
            if(concreteproducer){found = true;break;}
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
Entity* ConcreteProducerIterator::current(){
    return (*this->curr);
}