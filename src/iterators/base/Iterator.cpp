#include "Iterator.h"
/**
 * @brief Construct a new Iterator:: Iterator object
 * 
 */
Iterator::Iterator() {
    this->row = 0;
    this->col = 0;
}

/**
 * @brief Destroy the Iterator:: Iterator object
 * 
 */
Iterator::~Iterator() {}

/**
 * @brief 
 * 
 * @return int 
 */
int Iterator::getRow(){return this->row;}

/**
 * @brief 
 * 
 * @return int 
 */
int Iterator::getCol(){return this->col;}
