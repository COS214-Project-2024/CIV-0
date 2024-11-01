#include "doctest.h"
#include "entities/building/residential/Apartment.h"
#include "entities/building/residential/House.h"
#include "iterators/building/residential/ResidentialBuildingIterator.h"
#include <vector>

TEST_CASE("Testing ResidentialBuildingIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    House *h = new House();
    Apartment *a = new Apartment();

    row1.push_back(h);
    row1.push_back(a);
    row2.push_back(nullptr);
    row2.push_back(h);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator *aIter = new ResidentialBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete h;
    delete a;
}

TEST_CASE("Testing ResidentialBuildingIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    House *h = new House();
    Apartment *a = new Apartment();

    row1.push_back(h);
    row1.push_back(a);
    row2.push_back(nullptr);
    row2.push_back(h);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator *aIter = new ResidentialBuildingIterator(grid);
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
    delete h;
    delete a;
}

TEST_CASE("Testing ResidentialBuildingIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    House *h = new House();
    Apartment *a = new Apartment();

    row1.push_back(h);
    row1.push_back(a);
    row2.push_back(nullptr);
    row2.push_back(h);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator *aIter = new ResidentialBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete h;
    delete a;
}

TEST_CASE("Testing ResidentialBuildingIterator hasNext() with multiple buildings")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    House *h = new House();
    Apartment *a = new Apartment();

    row1.push_back(h);
    row1.push_back(a);
    row2.push_back(nullptr);
    row2.push_back(h);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator *aIter = new ResidentialBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    delete aIter;
    delete h;
    delete a;
}

TEST_CASE("Testing ResidentialBuildingIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    House *h = new House();
    Apartment *a = new Apartment();

    row1.push_back(h);
    row1.push_back(a);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    ResidentialBuildingIterator *aIter = new ResidentialBuildingIterator(grid);
    aIter->first();
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete h;
    delete a;
}
