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
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            ServiceBuilding* e = dynamic_cast<ServiceBuilding*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
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
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            ServiceBuilding* e = dynamic_cast<ServiceBuilding*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Determines if there is next Service Building
 * 
 * @return true 
 * @return false 
 */
bool ServiceBuildingIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            ServiceBuilding* a = dynamic_cast<ServiceBuilding*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current Service Building
 * 
 * @return Entity* 
 */
Entity* ServiceBuildingIterator::current(){
    return (*this->curr);
}