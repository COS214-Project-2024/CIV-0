#include "RoadIterator.h"

RoadIterator::RoadIterator() {}
RoadIterator::~RoadIterator() {}

RoadIterator::RoadIterator(std::vector<std::vector<Entity*>> &grid){
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
}

void RoadIterator::first(){
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Road* road = dynamic_cast<Road*>(*curr);

            if(road){found = true;break;}
        }
        if(found)break;
    }
}

void RoadIterator::next(){
    bool found = false;

    for(;currRow != this->grid.end(); currRow++){
        for(curr = currRow->begin(); curr != currRow->end(); curr++){
            Road* road = dynamic_cast<Road*>(*curr);

            if(road){found = true;break;}
        }
        if(found)break;
    }
}

bool RoadIterator::hasNext(){
    bool found = false;
    std::vector<std::vector<Entity*>>::iterator tempRow = this->currRow;
    std::vector<Entity*>::iterator tempCurr = this->curr;

        for(;tempRow != this->grid.end(); tempRow++){
        for(tempCurr = tempRow->begin(); tempCurr != tempRow->end(); tempCurr++){
            Road* road = dynamic_cast<Road*>(*tempCurr);

            if(road){found = true;break;}
        }
        if(found)break;
    }
    return found;
}

Road* RoadIterator::current(){
    return dynamic_cast<Road*>(*this->curr);
}