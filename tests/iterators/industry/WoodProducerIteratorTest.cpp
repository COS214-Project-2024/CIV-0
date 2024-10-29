#include "doctest.h"
#include "iterators/industry/WoodProducerIterator.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "entities/building/amenity/Theater.h"

 TEST_CASE("WoodProducerIteratorTest test") {
std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WoodProducer* c = new WoodProducer();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(c);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator* aIter = new WoodProducerIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete c;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WoodProducer* c = new WoodProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator* aIter = new WoodProducerIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete c;
    delete t;
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WoodProducer* c = new WoodProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator* aIter = new WoodProducerIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete c;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WoodProducer* c = new WoodProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator* aIter = new WoodProducerIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == false);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete c;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WoodProducer* c = new WoodProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(NULL);
    row2.push_back(c);
    row2.push_back(c);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator* aIter = new WoodProducerIterator(grid);
    //aIter->next();
    //aIter->next();
    //aIter->next();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    //CHECK(aIter->hasNext() == true);
    delete aIter;
    delete c;
    delete t;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    WoodProducer* c = new WoodProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator* aIter = new WoodProducerIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
    delete aIter;
    delete c;
    delete t;
}




