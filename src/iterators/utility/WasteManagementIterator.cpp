#include "WasteManagementIterator.h"

/**
 * @brief Construct a new Waste Management Iterator:: Waste Management Iterator object
 * 
 */
WasteManagementIterator::WasteManagementIterator():Iterator(){}

/**
 * @brief Destroy the Waste Management Iterator:: Waste Management Iterator object
 * 
 */
WasteManagementIterator::~WasteManagementIterator() {}

/**
 * @brief Construct a new Waste Management Iterator:: Waste Management Iterator object
 * 
 * @param grid 
 */
WasteManagementIterator::WasteManagementIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Resets the iterator to the first WasteManagement instance in the grid.
 * 
 * Sets the iterator to the first WasteManagement found in the grid. If no instance is found, it will 
 * position at the end of the grid.
 */
void WasteManagementIterator::first(){
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            WasteManagement* e = dynamic_cast<WasteManagement*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
}

/**
 * @brief Advances the iterator to the next WasteManagement instance in the grid.
 * 
 * Moves to the next WasteManagement in the grid based on the current position.
 * If no more instances are found, resets the iterator.
 */
void WasteManagementIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            WasteManagement* e = dynamic_cast<WasteManagement*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Checks if there is another WasteManagement instance in the grid after the current position.
 * 
 * @return true if another WasteManagement exists, false otherwise.
 */
bool WasteManagementIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            WasteManagement* a = dynamic_cast<WasteManagement*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns the current Entity instance pointed to by the iterator.
 * 
 * @return A pointer to the current Entity instance.
 */
Entity* WasteManagementIterator::current(){
    return (*this->curr);
}