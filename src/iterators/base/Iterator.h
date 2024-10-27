#ifndef ITERATOR_H
#define ITERATOR_H
#include<vector>
#include "entities/base/Entity.h"

class Iterator{
protected:
    std::vector<std::vector<Entity*>> grid;
    std::vector<std::vector<Entity*>>::iterator currRow;
    std::vector<Entity*>::iterator curr;
    int row;
    int col;

public:
    Iterator();
    virtual ~Iterator();

    Iterator(std::vector<std::vector<Entity*>> &grid);
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual Entity* current() = 0;
    virtual int getRow();
    virtual int getCol();

};

#endif // ITERATOR_H
