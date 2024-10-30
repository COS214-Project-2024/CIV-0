#include "doctest.h"
#include "entities/road/Road.h"
#include "entities/building/amenity/Theater.h"
#include "iterators/road/RoadIterator.h"
#include <vector>

TEST_CASE("Testing RoadIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Road *r = new Road(EntityConfig(), Size::MEDIUM, 0, 0);

    row1.push_back(r);
    row1.push_back(nullptr);
    row2.push_back(r);
    row2.push_back(r);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator *rIter = new RoadIterator(grid);
    rIter->first();
    CHECK(rIter->getRow() == 0);
    CHECK(rIter->getCol() == 0);

    delete rIter;
    delete r;
}

TEST_CASE("Testing RoadIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Road *r = new Road(EntityConfig(), Size::MEDIUM, 0, 0);
    Theater *t = new Theater(EntityConfig(), Size::MEDIUM, 0, 0);

    row1.push_back(r);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(r);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator *rIter = new RoadIterator(grid);
    rIter->first();
    CHECK(rIter->getRow() == 0);
    CHECK(rIter->getCol() == 0);
    CHECK(rIter->hasNext() == true);

    rIter->next();
    CHECK(rIter->getRow() == 2);
    CHECK(rIter->getCol() == 0);
    CHECK(rIter->hasNext() == false);

    delete rIter;
    delete r;
    delete t;
}

TEST_CASE("Testing RoadIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Road *r1 = new Road(EntityConfig(), Size::MEDIUM, 0, 0);
    Road *r2 = new Road(EntityConfig(), Size::MEDIUM, 0, 0);
    Theater *t = new Theater(EntityConfig(), Size::MEDIUM, 0, 0);

    row1.push_back(r1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(r2);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator *rIter = new RoadIterator(grid);
    rIter->first();
    CHECK(rIter->getRow() == 0);
    CHECK(rIter->getCol() == 0);
    CHECK(rIter->hasNext() == true);

    delete rIter;
    delete r1;
    delete r2;
    delete t;
}

TEST_CASE("Testing RoadIterator hasNext() with multiple roads")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Road *r1 = new Road(EntityConfig(), Size::MEDIUM, 0, 0);
    Road *r2 = new Road(EntityConfig(), Size::MEDIUM, 0, 0);
    Theater *t = new Theater(EntityConfig(), Size::MEDIUM, 0, 0);

    row1.push_back(r1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(r2);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator *rIter = new RoadIterator(grid);
    rIter->first();
    CHECK(rIter->hasNext() == true);
    CHECK(rIter->getRow() == 0);
    CHECK(rIter->getCol() == 0);

    rIter->next();
    CHECK(rIter->hasNext() == true);
    CHECK(rIter->getRow() == 1);
    CHECK(rIter->getCol() == 1);

    rIter->next();
    CHECK(rIter->hasNext() == false);
    CHECK(rIter->getRow() == 2);
    CHECK(rIter->getCol() == 0);

    delete rIter;
    delete r1;
    delete r2;
    delete t;
}

TEST_CASE("Testing RoadIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Road *r = new Road(EntityConfig(), Size::MEDIUM, 0, 0);
    Theater *t = new Theater(EntityConfig(), Size::MEDIUM, 0, 0);

    row1.push_back(r);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    RoadIterator *rIter = new RoadIterator(grid);
    rIter->first();
    rIter->next();
    CHECK(rIter->hasNext() == false);

    delete rIter;
    delete r;
    delete t;
}
