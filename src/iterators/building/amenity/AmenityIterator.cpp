#include "AmenityIterator.h"
#include <iostream>
/**
 * @brief Construct a new Amenity Iterator:: Amenity Iterator object
 * 
 */
AmenityIterator::AmenityIterator():Iterator(){
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Amenity Iterator:: Amenity Iterator object
 * 
 */
AmenityIterator::~AmenityIterator() {}

/**
 * @brief Construct a new Amenity Iterator:: Amenity Iterator object
 * 
 * @param grid 
 */
AmenityIterator::AmenityIterator(std::vector<std::vector<Entity*>> &grid):Iterator(){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Returns first Amenity
 * 
 */
void AmenityIterator::first(){
    //this->currRow = this->grid.begin();
    //his->curr = currRow->begin();
    bool found = false;

    for(currRow = grid.begin();currRow != this->grid.end(); currRow++){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Amenity* amenity = dynamic_cast<Amenity*>(*curr);
            if(amenity){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
}

/**
 * @brief goes to next Amenity
 * 
 */
void AmenityIterator::next(){
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if(hasNext()){
        col = 0;
        row = 0;
    for(currRow = grid.begin();currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Amenity* amenity = dynamic_cast<Amenity*>(*curr);
            if(amenity && (Tcol<col || Trow<row)){found = true;break;}
            col+=1;
        }
        if(found)break;
        row+=1;
    }
    }//hasNext
}

/**
 * @brief Determines if there is next Amenity
 * 
 * @return true 
 * @return false 
 */
bool AmenityIterator::hasNext(){
    int tr = 0;
    int tc = 0;
    for(std::vector<std::vector<Entity*>>::iterator itRow = grid.begin();itRow != grid.end();  itRow++){
        for(std::vector<Entity*>::iterator itCol = itRow->begin();itCol != itRow->end();  itCol++){
            Amenity* a = dynamic_cast<Amenity*>(*itCol);
            if((a) && (tc>col && tr>row))return true;
            tc+=1;
        }
        tr+=1;
    }
    return false;
}

/**
 * @brief Returns current Amentity
 * 
 * @return Entity* 
 */
Entity* AmenityIterator::current(){
    return (*this->curr);
}