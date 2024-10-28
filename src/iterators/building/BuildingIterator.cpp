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
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Building* e = dynamic_cast<Building*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
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
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Building* e = dynamic_cast<Building*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Determines if there is next Building
 * 
 * @return true 
 * @return false 
 */
bool BuildingIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            Building* a = dynamic_cast<Building*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current Building
 * 
 * @return Entity* 
 */
Entity* BuildingIterator::current(){
    return (*this->curr);
}