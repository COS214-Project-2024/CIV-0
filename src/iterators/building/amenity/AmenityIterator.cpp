#include "AmenityIterator.h"
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
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Amenity* amenity = dynamic_cast<Amenity*>(*curr);

            if(amenity){found = true;break;}
        }
        if(found)break;
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
    for(;currRow != this->grid.end();++currRow){
        col = 0;
        for(curr = currRow->begin(); curr != currRow->end();++curr){
            Amenity* amenity = dynamic_cast<Amenity*>(*curr);
            if(amenity && (col!=Tcol || Trow!=row)){found = true;break;}
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
 * @brief Determines if there is next Amenity
 * 
 * @return true 
 * @return false 
 */
bool AmenityIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = ++this->currRow;
    std::vector<Entity*>::iterator tempCurr = ++this->curr;

        for(;tempRow != this->grid.end();++tempRow){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end();++tempCurr){
            Amenity* amenity = dynamic_cast<Amenity*>(*tempCurr);
            if(amenity){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

/**
 * @brief Returns current Amentity
 * 
 * @return Entity* 
 */
Entity* AmenityIterator::current(){
    return (*this->curr);
}