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

    row1.push_back(new Office());
    row1.push_back(new Factory());
    row2.push_back(NULL);
    row2.push_back(new Office());

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}


TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Office());
    row1.push_back(new Factory());
    row2.push_back(NULL);
    row2.push_back(new Office());

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Office());
    row1.push_back(new Factory());
    row2.push_back(NULL);
    row2.push_back(new Office());

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Office());
    row1.push_back(new Factory());
    row2.push_back(NULL);
    row2.push_back(new Office());

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == true);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Office());
    row1.push_back(new Factory());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    EconomicBuildingIterator* aIter = new EconomicBuildingIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
}


