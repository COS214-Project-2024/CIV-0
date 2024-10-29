#include "doctest.h"
#include "iterators/utility/ConcreteProducerIterator.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("ConcreteProducerIteratorTest test"){
std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    ConcreteProducer* c = new ConcreteProducer();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(c);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator* aIter = new ConcreteProducerIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete c;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    ConcreteProducer* c = new ConcreteProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator* aIter = new ConcreteProducerIterator(grid);
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
    ConcreteProducer* c = new ConcreteProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator* aIter = new ConcreteProducerIterator(grid);
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
    ConcreteProducer* c = new ConcreteProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator* aIter = new ConcreteProducerIterator(grid);
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
    ConcreteProducer* c = new ConcreteProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(NULL);
    row2.push_back(c);
    row2.push_back(c);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator* aIter = new ConcreteProducerIterator(grid);
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
    ConcreteProducer* c = new ConcreteProducer();
    Theater* t = new Theater();

    row1.push_back(c);
    row1.push_back(c);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator* aIter = new ConcreteProducerIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
    delete aIter;
    delete c;
    delete t;
}



