#include "doctest.h"
#include "iterators/utility/WasteManagementIterator.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("WasteManagementIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WasteManagement *wm1 = new WasteManagement();
    Theater *t = new Theater();

    row1.push_back(wm1);
    row1.push_back(wm1);
    row2.push_back(nullptr);
    row2.push_back(wm1);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator *wmIter = new WasteManagementIterator(grid);
    wmIter->first();
    CHECK(wmIter->getRow() == 0);
    CHECK(wmIter->getCol() == 0);

    delete wmIter;
    delete wm1;
    delete t;
}

TEST_CASE("WasteManagementIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WasteManagement *wm1 = new WasteManagement();
    Theater *t = new Theater();

    row1.push_back(wm1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(wm1);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator *wmIter = new WasteManagementIterator(grid);
    wmIter->first();
    CHECK(wmIter->getRow() == 0);
    CHECK(wmIter->getCol() == 0);

    wmIter->next();
    CHECK(wmIter->getRow() == 2);
    CHECK(wmIter->getCol() == 0);
    CHECK(wmIter->hasNext() == false);

    delete wmIter;
    delete wm1;
    delete t;
}

TEST_CASE("WasteManagementIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WasteManagement *wm1 = new WasteManagement();
    Theater *t = new Theater();

    row1.push_back(wm1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(wm1);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator *wmIter = new WasteManagementIterator(grid);
    wmIter->first();
    CHECK(wmIter->getRow() == 0);
    CHECK(wmIter->getCol() == 0);
    CHECK(wmIter->hasNext() == true);

    delete wmIter;
    delete wm1;
    delete t;
}

TEST_CASE("WasteManagementIterator hasNext() with multiple WasteManagement instances")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WasteManagement *wm1 = new WasteManagement();
    WasteManagement *wm2 = new WasteManagement();
    Theater *t = new Theater();

    row1.push_back(wm1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(wm2);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator *wmIter = new WasteManagementIterator(grid);
    wmIter->first();
    CHECK(wmIter->hasNext() == true);
    CHECK(wmIter->getRow() == 0);
    CHECK(wmIter->getCol() == 0);

    wmIter->next();
    CHECK(wmIter->getRow() == 1);
    CHECK(wmIter->getCol() == 1);
    CHECK(wmIter->hasNext() == true);

    wmIter->next();
    CHECK(wmIter->getRow() == 2);
    CHECK(wmIter->getCol() == 0);
    CHECK(wmIter->hasNext() == false);

    delete wmIter;
    delete wm1;
    delete wm2;
    delete t;
}

TEST_CASE("WasteManagementIterator reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WasteManagement *wm1 = new WasteManagement();
    Theater *t = new Theater();

    row1.push_back(wm1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator *wmIter = new WasteManagementIterator(grid);
    wmIter->first();
    wmIter->next();
    CHECK(wmIter->hasNext() == false);

    delete wmIter;
    delete wm1;
    delete t;
}
