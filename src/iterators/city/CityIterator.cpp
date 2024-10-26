#include "CityIterator.h"
/**
 * @brief Construct a new City Iterator:: City Iterator object
 * 
 */
CityIterator::CityIterator():Iterator(){
    this->row = 0;
    this->col = 0;
}
/**
 * @brief Destroy the City Iterator:: City Iterator object
 * 
 */
CityIterator::~CityIterator() {}

/**
 * @brief Construct a new City Iterator:: City Iterator object
 * 
 * @param grid 
 */
CityIterator::CityIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Goes to first Entity
 * 
 */
void CityIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

/**
 * @brief Goes to next Entity
 * 
 */
void CityIterator::next(){
    ++this->curr;
    col+=1;
    if(curr == currRow->end()){
        ++currRow;
        row+=1;
        if(currRow == grid.end()){--currRow; curr = currRow->end();--curr;row-=1;col-=1;return;}
        curr = currRow->begin();
        col = 0;
    }
}

/**
 * @brief Determines if there is next Entity
 * 
 * @return true 
 * @return false 
 */
bool CityIterator::hasNext(){
    bool found = true;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;
    ++tempCurr;
    if(tempCurr == tempRow->end()){
        ++tempRow;
        if(tempRow == grid.end()){found = false;}
    }
    return found;
}

/**
 * @brief Returns current space
 * 
 * @return Entity* 
 */
Entity* CityIterator::current(){
    return (*this->curr);
}