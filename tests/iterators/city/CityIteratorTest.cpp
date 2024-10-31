#include "doctest.h"
#include "entities/base/Entity.h"
#include "entities/building/economic/Factory.h"
#include "iterators/city/CityIterator.h"

TEST_CASE("CityIteratorTest test")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete f;
}

TEST_CASE("Testing first")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete f;
}

TEST_CASE("Testing next() 1")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete f;
}

TEST_CASE("Testing next() 2")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->first();
    aIter->next();
    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete f;
}

TEST_CASE("Testing next() 3")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 1);

    delete aIter;
    delete f;
}

TEST_CASE("Testing next() 4")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->next();
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);
    delete aIter;
    delete f;
}

TEST_CASE("Testing hasNext()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->hasNext() == true);
    delete aIter;
    delete f;
}

TEST_CASE("Testing hasNext()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, false);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete f;
}

TEST_CASE("CityIteratorTest test iterate unique")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Factory *f = new Factory();

    row1.push_back(f);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    CityIterator *aIter = new CityIterator(grid, true);

    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete f;
}