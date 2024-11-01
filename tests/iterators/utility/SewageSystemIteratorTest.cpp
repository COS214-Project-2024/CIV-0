#include "doctest.h"
#include "iterators/utility/SewageSystemIterator.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("SewageSystemIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    SewageSystem *s1 = new SewageSystem();
    Theater *t = new Theater();

    row1.push_back(s1);
    row1.push_back(s1);
    row2.push_back(nullptr);
    row2.push_back(s1);

    grid.push_back(row1);
    grid.push_back(row2);

    SewageSystemIterator *sIter = new SewageSystemIterator(grid);
    sIter->first();
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);

    delete sIter;
    delete s1;
    delete t;
}

TEST_CASE("SewageSystemIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    SewageSystem *s1 = new SewageSystem();
    Theater *t = new Theater();

    row1.push_back(s1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(s1);

    grid.push_back(row1);
    grid.push_back(row2);

    SewageSystemIterator *sIter = new SewageSystemIterator(grid);
    sIter->first();
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);

    sIter->next();
    CHECK(sIter->getRow() == 2);
    CHECK(sIter->getCol() == 0);
    CHECK(sIter->hasNext() == false);

    delete sIter;
    delete s1;
    delete t;
}

TEST_CASE("SewageSystemIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    SewageSystem *s1 = new SewageSystem();
    Theater *t = new Theater();

    row1.push_back(s1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(s1);

    grid.push_back(row1);
    grid.push_back(row2);

    SewageSystemIterator *sIter = new SewageSystemIterator(grid);
    sIter->first();
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);
    CHECK(sIter->hasNext() == true);

    delete sIter;
    delete s1;
    delete t;
}

TEST_CASE("SewageSystemIterator hasNext() with multiple SewageSystems")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    SewageSystem *s1 = new SewageSystem();
    SewageSystem *s2 = new SewageSystem();
    Theater *t = new Theater();

    row1.push_back(s1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(s2);

    grid.push_back(row1);
    grid.push_back(row2);

    SewageSystemIterator *sIter = new SewageSystemIterator(grid);
    sIter->first();
    CHECK(sIter->hasNext() == true);
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);

    sIter->next();
    CHECK(sIter->getRow() == 1);
    CHECK(sIter->getCol() == 1);
    CHECK(sIter->hasNext() == true);

    sIter->next();
    CHECK(sIter->getRow() == 2);
    CHECK(sIter->getCol() == 0);
    CHECK(sIter->hasNext() == false);

    delete sIter;
    delete s1;
    delete s2;
    delete t;
}

TEST_CASE("SewageSystemIterator reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    SewageSystem *s1 = new SewageSystem();
    Theater *t = new Theater();

    row1.push_back(s1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    SewageSystemIterator *sIter = new SewageSystemIterator(grid);
    sIter->first();
    sIter->next();
    CHECK(sIter->hasNext() == false);

    delete sIter;
    delete s1;
    delete t;
}
