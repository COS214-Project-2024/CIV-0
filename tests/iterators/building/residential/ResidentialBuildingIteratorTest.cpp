#include "doctest.h"
#include "doctest.h"
#include "entities/building/residential/Apartment.h"
#include "entities/building/residential/House.h"

#include "iterators/building/residential/ResidentialBuildingIterator.h"
#include <vector>

TEST_CASE("ResidentialBuildingIteratorTest test") {
    // Add your test cases here
    CHECK(1 == 1);
}

TEST_CASE("ResidentialBuildingIterator test") {
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new House());
    row1.push_back(new Apartment());
    row2.push_back(NULL);
    row2.push_back(new House());

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator* aIter = new ResidentialBuildingIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new House());
    row1.push_back(new Apartment());
    row2.push_back(NULL);
    row2.push_back(new House());

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator* aIter = new ResidentialBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new House());
    row1.push_back(new Apartment());
    row2.push_back(NULL);
    row2.push_back(new House());

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator* aIter = new ResidentialBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new House());
    row1.push_back(new Apartment());
    row2.push_back(NULL);
    row2.push_back(new House());

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator* aIter = new ResidentialBuildingIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == true);
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new House());
    row1.push_back(new Apartment());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator* aIter = new ResidentialBuildingIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;

    row1.push_back(new House());
    row1.push_back(new Apartment());
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator* aIter = new ResidentialBuildingIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
}

