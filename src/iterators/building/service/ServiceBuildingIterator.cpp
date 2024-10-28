#include "ServiceBuildingIterator.h"

/**
 * @brief Construct a new Service Building Iterator:: Service Building Iterator object
 * 
 */
ServiceBuildingIterator::ServiceBuildingIterator():Iterator(){
    this->row = 0;
    this->col = 0;
}
/**
 * @brief Destroy the Service Building Iterator:: Service Building Iterator object
 * 
 */
ServiceBuildingIterator::~ServiceBuildingIterator() {}

/**
 * @brief Construct a new Service Building Iterator:: Service Building Iterator object
 * 
 * @param grid 
 */
ServiceBuildingIterator::ServiceBuildingIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Goes to first Service Building
 * 
 */
void ServiceBuildingIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ServiceBuilding* servicebuilding = dynamic_cast<ServiceBuilding*>(*curr);

            if(servicebuilding){found = true;break;}
        }
        if(found)break;
    }
}

/**
 * @brief Goes to next Service Building
 * 
 */
void ServiceBuildingIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            ServiceBuilding* servicebuilding = dynamic_cast<ServiceBuilding*>(*curr);
            if(servicebuilding && (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Determines if there is next Service Building
 * 
 * @return true 
 * @return false 
 */
bool ServiceBuildingIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            ServiceBuilding* servicebuilding = dynamic_cast<ServiceBuilding*>(*tempCurr);

            if(servicebuilding){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns current Service Building
 * 
 * @return Entity* 
 */
Entity* ServiceBuildingIterator::current(){
    return (*this->curr);
}