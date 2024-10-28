#include "RoadIterator.h"
/**
 * @brief Construct a new Road Iterator:: Road Iterator object
 * 
 */
RoadIterator::RoadIterator():Iterator(){}

/**
 * @brief Destroy the Road Iterator:: Road Iterator object
 * 
 */
RoadIterator::~RoadIterator() {}

/**
 * @brief Construct a new Road Iterator:: Road Iterator object
 * 
 * @param grid 
 */
RoadIterator::RoadIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Goes to first Road
 * 
 */
void RoadIterator::first(){
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Road* e = dynamic_cast<Road*>(*curr);
            if(e){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
}

/**
 * @brief Goes to next Road
 * 
 */
void RoadIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Road* e = dynamic_cast<Road*>(*curr);
            if(e && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Determines if there is next Road
 * 
 * @return true 
 * @return false 
 */
bool RoadIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        tc=0;
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            Road* a = dynamic_cast<Road*>(*itCol);
            if((a) && (tr>row)){return true;}
            if((a) && (tr>=row && tc>col)){return true;}
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current Road
 * 
 * @return Entity* 
 */
Entity* RoadIterator::current(){
    return (*this->curr);
}