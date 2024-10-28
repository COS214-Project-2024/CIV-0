#include "TransportIterator.h"
/**
 * @brief Construct a new Transport Iterator:: Transport Iterator object
 * 
 */
TransportIterator::TransportIterator():Iterator(){}

/**
 * @brief Destroy the Transport Iterator:: Transport Iterator object
 * 
 */
TransportIterator::~TransportIterator() {}

/**
 * @brief Construct a new Transport Iterator:: Transport Iterator object
 * 
 * @param grid 
 */
TransportIterator::TransportIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Goes to first Transport
 * 
 */
void TransportIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Transport* transport = dynamic_cast<Transport*>(*curr);

            if(transport){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Goes to next Transport
 * 
 */
void TransportIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Transport* transport = dynamic_cast<Transport*>(*curr);
            if(transport && (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Determines if there is next Transport
 * 
 * @return true 
 * @return false 
 */
bool TransportIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            Transport* transport = dynamic_cast<Transport*>(*tempCurr);

            if(transport){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns current Transport
 * 
 * @return Entity* 
 */
Entity* TransportIterator::current(){
    return (*this->curr);
}