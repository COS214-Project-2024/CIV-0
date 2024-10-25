#include "doctest.h"
#include "entities/building/amenity/Amenity.h"
#include "entities/building/amenity/Monument.h"
#include "entities/building/amenity/Park.h"
#include "entities/building/amenity/Theater.h"

#include "iterators/building/amenity/AmenityIterator.h"
#include <vector>

TEST_CASE("AmenityIterator test") {
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Park());
    row1.push_back(new Monument());
    row2.push_back(NULL);
    row2.push_back(new Theater());

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Park());
    row1.push_back(new Monument());
    row2.push_back(NULL);
    row2.push_back(new Theater());

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Park());
    row1.push_back(new Monument());
    row2.push_back(NULL);
    row2.push_back(new Theater());

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Park());
    row1.push_back(new Monument());
    row2.push_back(NULL);
    row2.push_back(new Theater());

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == true);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Park());
    row1.push_back(new Monument());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new Park());
    row1.push_back(new Monument());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
}

