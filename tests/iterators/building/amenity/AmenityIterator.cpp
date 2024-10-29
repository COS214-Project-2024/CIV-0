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
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing next()"){
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    //aIter->next();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete m;
    delete t;
}

 TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(p);
    row1.push_back(m);
    row2.push_back(t);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete m;
    delete t;
}

 TEST_CASE("Testing hasNext()"){
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    //aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete p;
    delete m;
    delete t;
} 

TEST_CASE("Testing next()"){
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(NULL);
    row1.push_back(m);
    row2.push_back(p);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    aIter->next();
    //aIter->next();
    //aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 1);
    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing HasNext()"){
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(m);
    row1.push_back(NULL);
    row2.push_back(p);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    aIter->next();
    //aIter->next();
    //aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 1);
    delete aIter;
    delete p;
    delete m;
    delete t;
}

TEST_CASE("Testing next()"){
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Park* p = new Park();
    Theater* t = new Theater();
    Monument* m = new Monument();

    row1.push_back(m);
    row1.push_back(NULL);
    row2.push_back(NULL);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    AmenityIterator* aIter = new AmenityIterator(grid);
    aIter->first();
    aIter->next();
    //aIter->next();
    //aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 1);
    delete aIter;
    delete p;
    delete m;
    delete t;
}
