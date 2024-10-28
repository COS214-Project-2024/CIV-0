#include "doctest.h"
#include "iterators/utility/WasteManagementIterator.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("WasteManagementIteratorTest test") {
std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WasteManagement* p = new WasteManagement();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator* aIter = new WasteManagementIterator(grid);
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
    WasteManagement* p = new WasteManagement();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator* aIter = new WasteManagementIterator(grid);
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
    WasteManagement* p = new WasteManagement();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator* aIter = new WasteManagementIterator(grid);
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
    WasteManagement* p = new WasteManagement();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator* aIter = new WasteManagementIterator(grid);
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
    WasteManagement* p = new WasteManagement();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(t);
    row2.push_back(p);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator* aIter = new WasteManagementIterator(grid);

    WasteManagement* testP = new WasteManagement();
    Utility* castCheck1 = dynamic_cast<Utility*>(testP);
    WasteManagement* castCheck2 = dynamic_cast<WasteManagement*>(castCheck1);
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
    WasteManagement* p = new WasteManagement();
    Theater* t = new Theater();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    WasteManagementIterator* aIter = new WasteManagementIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
    delete aIter;
    delete p;
    delete t;
}




