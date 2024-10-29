#include "doctest.h"
#include "doctest.h"
#include "entities/road/Road.h"
#include "entities/building/amenity/Theater.h"


#include "iterators/road/RoadIterator.h"
#include <vector>
TEST_CASE("RoadIteratorTest test") {

    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Road* r = new Road(EntityConfig(),Size::MEDIUM,0,0);
    Theater* t = new Theater(EntityConfig(),Size::MEDIUM,0,0);

    row1.push_back(r);
    row1.push_back(r);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator* aIter = new RoadIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete r;
    delete t;
}

TEST_CASE("Testing next()"){
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Road* r = new Road(EntityConfig(),Size::MEDIUM,0,0);
    Theater* t = new Theater(EntityConfig(),Size::MEDIUM,0,0);

    row1.push_back(r);
    row1.push_back(r);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator* aIter = new RoadIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete r;
    delete t;
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Road* r = new Road(EntityConfig(),Size::MEDIUM,0,0);
    Theater* t = new Theater(EntityConfig(),Size::MEDIUM,0,0);

    row1.push_back(r);
    row1.push_back(r);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator* aIter = new RoadIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete r;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Road* r = new Road(EntityConfig(),Size::MEDIUM,0,0);
    Theater* t = new Theater(EntityConfig(),Size::MEDIUM,0,0);

    row1.push_back(r);
    row1.push_back(r);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator* aIter = new RoadIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == false);
    delete aIter;
    delete r;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Road* r = new Road(EntityConfig(),Size::MEDIUM,0,0);
    Theater* t = new Theater(EntityConfig(),Size::MEDIUM,0,0);

    row1.push_back(r);
    row1.push_back(r);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator* aIter = new RoadIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
    delete aIter;
    delete r;
    delete t;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Road* r = new Road(EntityConfig(),Size::MEDIUM,0,0);

    row1.push_back(r);
    row1.push_back(r);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator* aIter = new RoadIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
    delete aIter;
    delete r;
}

