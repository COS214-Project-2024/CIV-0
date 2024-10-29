#include "doctest.h"
#include "iterators/building/economic/EconomicBuildingIterator.h"
#include "entities/building/economic/ShoppingMall.h"
#include "entities/building/economic/Factory.h"
#include "entities/building/economic/Office.h"
#include <vector>

TEST_CASE("EconomicBuildingIterator test") {
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Office* o = new Office();
    Factory* f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete o;
    delete f;
}


TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Office* o = new Office();
    Factory* f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(o);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Office* o = new Office();
    Factory* f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(o);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Office* o = new Office();
    Factory* f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(o);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    aIter->next();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->hasNext() == true);
    delete aIter;
    delete o;
    delete f;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Office* o = new Office();
    Factory* f = new Factory();

    row1.push_back(o);
    row1.push_back(f);
    row2.push_back(NULL);
    row2.push_back(f);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 1);
    delete aIter;
    delete o;
    delete f;
}


