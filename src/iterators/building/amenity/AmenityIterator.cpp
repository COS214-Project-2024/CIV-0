#include "AmenityIterator.h"

AmenityIterator::AmenityIterator() {}
AmenityIterator::~AmenityIterator() {}

AmenityIterator::AmenityIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

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

void AmenityIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Amenity* amenity = dynamic_cast<Amenity*>(*curr);

            if(amenity){found = true;break;}
        }
        if(found)break;
    }
}

bool AmenityIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Amenity* amenity = dynamic_cast<Amenity*>(*tempCurr);

            if(amenity){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Amenity* AmenityIterator::current(){
    return dynamic_cast<Amenity*>(*this->curr);
}