#include "doctest.h"
#include "iterators/utility/WaterSupplyIterator.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("WaterSupplyIteratorTest test") {
std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WaterSupply* p = new WaterSupply();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator* aIter = new WaterSupplyIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WaterSupply* p = new WaterSupply();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator* aIter = new WaterSupplyIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WaterSupply* p = new WaterSupply();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator* aIter = new WaterSupplyIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WaterSupply* p = new WaterSupply();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator* aIter = new WaterSupplyIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WaterSupply* p = new WaterSupply();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(t);
    row2.push_back(p);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator* aIter = new WaterSupplyIterator(grid);

    WaterSupply* testP = new WaterSupply();
    Utility* castCheck1 = dynamic_cast<Utility*>(testP);
    WaterSupply* castCheck2 = dynamic_cast<WaterSupply*>(castCheck1);
    CHECK(castCheck2 != NULL);
    aIter->next();
    aIter->next();   
    //aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->hasNext() == false);
    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WaterSupply* p = new WaterSupply();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator* aIter = new WaterSupplyIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
    delete aIter;
    delete p;
    delete t;
}





