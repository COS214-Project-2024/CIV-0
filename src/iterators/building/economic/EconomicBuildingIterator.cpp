#include "EconomicBuildingIterator.h"
/**
 * @brief Construct a new Economic Building Iterator:: Economic Building Iterator object
 * 
 */
EconomicBuildingIterator::EconomicBuildingIterator():Iterator(){
    this->row = 0;
    this->col = 0;
}
/**
 * @brief Destroy the Economic Building Iterator:: Economic Building Iterator object
 * 
 */
EconomicBuildingIterator::~EconomicBuildingIterator() {}

/**
 * @brief Construct a new Economic Building Iterator:: Economic Building Iterator object
 * 
 * @param grid 
 */
EconomicBuildingIterator::EconomicBuildingIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row - 0;
    this->col - 0;
}

/**
 * @brief Goes to first EconomicBuilding
 * 
 */
void EconomicBuildingIterator::first(){
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            EconomicBuilding* e = dynamic_cast<EconomicBuilding*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
}

/**
 * @brief Goes to next EconomicBuilding
 * 
 */
void EconomicBuildingIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            EconomicBuilding* e = dynamic_cast<EconomicBuilding*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Determines if there is next EconomicBuilding
 * 
 * @return true 
 * @return false 
 */
bool EconomicBuildingIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            EconomicBuilding* a = dynamic_cast<EconomicBuilding*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current EconomicBuilding
 * 
 * @return Entity* 
 */
Entity* EconomicBuildingIterator::current(){
    return (*this->curr);
}