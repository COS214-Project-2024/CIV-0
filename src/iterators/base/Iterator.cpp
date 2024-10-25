#include "Iterator.h"

Iterator::Iterator() {
    this->row = 0;
    this->col = 0;
}

Iterator::~Iterator() {}

int Iterator::getRow(){return this->row;}

int Iterator::getCol(){return this->col;}
