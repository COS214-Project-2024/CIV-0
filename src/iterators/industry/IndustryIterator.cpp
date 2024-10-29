#include "IndustryIterator.h"

/**
 * @brief Construct a new Industry Iterator:: Industry Iterator object
 */
IndustryIterator::IndustryIterator() : Iterator() {}

/**
 * @brief Destroy the Industry Iterator:: Industry Iterator object
 */
IndustryIterator::~IndustryIterator() {}

/**
 * @brief Construct a new Industry Iterator:: Industry Iterator object
 * 
 * @param grid 
 */
IndustryIterator::IndustryIterator(std::vector<std::vector<Entity*>> &grid) : Iterator() {
    this->grid = grid;
    this->currRow = this->grid.begin();
    this->curr = currRow->begin();
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Finds first Industry
 */
void IndustryIterator::first() {
    bool found = false;

    for (currRow = grid.begin(); currRow != this->grid.end(); currRow++) {
        col = 0;
        for (curr = currRow->begin(); curr != currRow->end(); curr++) {
            Industry* e = dynamic_cast<Industry*>(*curr);
            if (e) { found = true; break; }
            col += 1;
        }
        if (found) break;
        row += 1;
    }
}

/**
 * @brief Finds next Industry
 */
void IndustryIterator::next() {
    bool found = false;
    int Tcol = this->col;
    int Trow = this->row;
    if (hasNext()) {
        col = 0;
        row = 0;
        for (currRow = grid.begin(); currRow != this->grid.end(); ++currRow) {
            col = 0;
            for (curr = currRow->begin(); curr != currRow->end(); ++curr) {
                Industry* e = dynamic_cast<Industry*>(*curr);
                if (e && (Tcol < col || Trow < row)) { found = true; break; }
                col += 1;
            }
            if (found) break;
            row += 1;
        }
    }
}

/**
 * @brief Determines if there is next Industry
 * 
 * @return true 
 * @return false 
 */
bool IndustryIterator::hasNext() {
    int tr = 0;
    int tc = 0;
    for (std::vector<std::vector<Entity*>>::iterator itRow = grid.begin(); itRow != grid.end(); itRow++) {
        tc = 0;
        for (std::vector<Entity*>::iterator itCol = itRow->begin(); itCol != itRow->end(); itCol++) {
            Industry* a = dynamic_cast<Industry*>(*itCol);
            if ((a) && (tr > row)) { return true; }
            if ((a) && (tr >= row && tc > col)) { return true; }
            tc += 1;
        }
        tr += 1;
    }
    return false;
}

/**
 * @brief 
 * 
 * @return Entity* 
 */
Entity* IndustryIterator::current() {
    return (*this->curr);
}