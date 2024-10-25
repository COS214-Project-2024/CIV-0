#include "doctest.h"
#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"
#include "iterators/building/service/ServiceBuildingIterator.h"
#include <vector>

TEST_CASE("ServiceBuildingIterator test") {
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Hospital());
    row1.push_back(new PoliceStation());
    row2.push_back(NULL);
    row2.push_back(new School());

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator* aIter = new ServiceBuildingIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new School());
    row1.push_back(new PoliceStation());
    row2.push_back(NULL);
    row2.push_back(new Hospital());

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator* aIter = new ServiceBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Hospital());
    row1.push_back(new School());
    row2.push_back(NULL);
    row2.push_back(new PoliceStation());

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator* aIter = new ServiceBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new School());
    row1.push_back(new Hospital());
    row2.push_back(NULL);
    row2.push_back(new PoliceStation());

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator* aIter = new ServiceBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == true);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new School());
    row1.push_back(new PoliceStation());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator* aIter = new ServiceBuildingIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Hospital());
    row1.push_back(new PoliceStation());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator* aIter = new ServiceBuildingIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
}

