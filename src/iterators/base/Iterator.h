#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <unordered_set>
#include "entities/base/Entity.h"

class Iterator
{
protected:
    std::vector<std::vector<Entity *>> grid;
    std::vector<std::vector<Entity *>>::iterator currRow;
    std::vector<Entity *>::iterator curr;
    int row;
    int col;
    std::unordered_set<Entity *> visitedEntities; // Tracks visited entities

public:
    Iterator();
    virtual ~Iterator();

    Iterator(std::vector<std::vector<Entity *>> &grid) : grid(grid) {};
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual Entity *current() = 0;
    virtual int getRow();
    virtual int getCol();

protected:
    bool isVisited(Entity *entity);
    void markVisited(Entity *entity);
};

#endif // ITERATOR_H
