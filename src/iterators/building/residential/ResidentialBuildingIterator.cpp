#include "ResidentialBuildingIterator.h"
/**
 * @brief Construct a new Residential Building Iterator:: Residential Building Iterator object
 * 
 */
ResidentialBuildingIterator::ResidentialBuildingIterator():Iterator(){
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Residential Building Iterator:: Residential Building Iterator object
 * 
 */
ResidentialBuildingIterator::~ResidentialBuildingIterator() {}

/**
 * @brief Construct a new Residential Building Iterator:: Residential Building Iterator object
 * 
 * @param grid 
 */
ResidentialBuildingIterator::ResidentialBuildingIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Goes to first Residential Building
 * 
 */
void ResidentialBuildingIterator::first(){
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ResidentialBuilding* e = dynamic_cast<ResidentialBuilding*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
}

/**
 * @brief Goes to next Residential Building
 * 
 */
void ResidentialBuildingIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            ResidentialBuilding* e = dynamic_cast<ResidentialBuilding*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Deteremines if there is next Residential Building
 * 
 * @return true 
 * @return false 
 */
bool ResidentialBuildingIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            ResidentialBuilding* a = dynamic_cast<ResidentialBuilding*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current Residential Building
 * 
 * @return Entity* 
 */
Entity* ResidentialBuildingIterator::current(){
    return (*this->curr);
}