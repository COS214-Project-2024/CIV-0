#include "doctest.h"
#include "entities/building/amenity/Amenity.h"
#include "entities/building/amenity/Monument.h"
#include "entities/building/amenity/Park.h"
#include "entities/building/amenity/Theater.h"
#include "iterators/building/amenity/AmenityIterator.h"
#include <vector>

TEST_CASE("Testing AmenityIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(nullptr);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);

    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing next() with initial setup")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(nullptr);
    row1.push_back(m);
    row2.push_back(p);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);

    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing first()")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(nullptr);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing hasNext() with multiple amenities")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(t);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing hasNext() with no amenities left")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(p);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing hasNext() with final position on Amenity")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(m);
    row1.push_back(nullptr);
    row2.push_back(p);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing next() on alternating amenity layout")
{
    std::vector<std::vector<Entity *>> grid;
    std::vector<Entity *> row1, row2;
    Park *p = new Park();
    Theater *t = new Theater();
    Monument *m = new Monument();

    row1.push_back(m);
    row1.push_back(nullptr);
    row2.push_back(nullptr);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator *aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 1);

    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete p;
    delete m;
    delete t;
}
