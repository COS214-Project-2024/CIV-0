#include "doctest.h"
#include "iterators/building/economic/EconomicBuildingIterator.h"
#include "entities/building/economic/ShoppingMall.h"
#include "entities/building/economic/Factory.h"
#include "entities/building/economic/Office.h"
#include <vector>

TEST_CASE("Testing EconomicBuildingIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Office *o = new Office();
    Factory *f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(nullptr);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator *aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing EconomicBuildingIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Office *o = new Office();
    Factory *f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(nullptr);
    row2.push_back(o);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator *aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing EconomicBuildingIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Office *o = new Office();
    Factory *f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(nullptr);
    row2.push_back(o);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator *aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing EconomicBuildingIterator hasNext() with multiple buildings")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Office *o = new Office();
    Factory *f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(nullptr);
    row2.push_back(o);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator *aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing EconomicBuildingIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Office *o = new Office();
    Factory *f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(nullptr);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator *aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete o;
    delete f;
}
