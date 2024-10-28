#include "UtilityIterator.h"
/**
 * @brief Construct a new Utility Iterator:: Utility Iterator object
 * 
 */
UtilityIterator::UtilityIterator():Iterator(){}

/**
 * @brief Destroy the Utility Iterator:: Utility Iterator object
 * 
 */
UtilityIterator::~UtilityIterator() {}

/**
 * @brief Construct a new Utility Iterator:: Utility Iterator object
 * 
 * @param grid 
 */
UtilityIterator::UtilityIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Finds first Utility
 * 
 */
void UtilityIterator::first(){
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Utility* e = dynamic_cast<Utility*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
}

/**
 * @brief Finds next Utility
 * 
 */
void UtilityIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Utility* e = dynamic_cast<Utility*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Determines if there is next Utility
 * 
 * @return true 
 * @return false 
 */
bool UtilityIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            Utility* a = dynamic_cast<Utility*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief 
 * 
 * @return Entity* 
 */
Entity* UtilityIterator::current(){
    return (*this->curr);
}