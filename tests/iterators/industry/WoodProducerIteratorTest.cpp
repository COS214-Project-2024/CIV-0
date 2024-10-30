#include "doctest.h"
#include "iterators/industry/WoodProducerIterator.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "entities/building/amenity/Theater.h"
#include <vector>

TEST_CASE("Testing WoodProducerIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WoodProducer *producer = new WoodProducer();

    row1.push_back(producer);
    row1.push_back(nullptr);
    row2.push_back(producer);
    row2.push_back(producer);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator *wIter = new WoodProducerIterator(grid);
    wIter->first();
    CHECK(wIter->getRow() == 0);
    CHECK(wIter->getCol() == 0);

    delete wIter;
    delete producer;
}

TEST_CASE("Testing WoodProducerIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WoodProducer *producer = new WoodProducer();
    Theater *theater = new Theater();

    row1.push_back(producer);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator *wIter = new WoodProducerIterator(grid);
    wIter->first();
    CHECK(wIter->getRow() == 0);
    CHECK(wIter->getCol() == 0);
    CHECK(wIter->hasNext() == true);

    wIter->next();
    CHECK(wIter->getRow() == 2);
    CHECK(wIter->getCol() == 0);
    CHECK(wIter->hasNext() == false);

    delete wIter;
    delete producer;
    delete theater;
}

TEST_CASE("Testing WoodProducerIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WoodProducer *producer1 = new WoodProducer();
    WoodProducer *producer2 = new WoodProducer();
    Theater *theater = new Theater();

    row1.push_back(producer1);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator *wIter = new WoodProducerIterator(grid);
    wIter->first();
    CHECK(wIter->getRow() == 0);
    CHECK(wIter->getCol() == 0);
    CHECK(wIter->hasNext() == true);

    delete wIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing WoodProducerIterator hasNext() with multiple producers")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WoodProducer *producer1 = new WoodProducer();
    WoodProducer *producer2 = new WoodProducer();
    Theater *theater = new Theater();

    row1.push_back(producer1);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator *wIter = new WoodProducerIterator(grid);
    wIter->first();
    CHECK(wIter->hasNext() == true);
    CHECK(wIter->getRow() == 0);
    CHECK(wIter->getCol() == 0);

    wIter->next();
    CHECK(wIter->hasNext() == true);
    CHECK(wIter->getRow() == 1);
    CHECK(wIter->getCol() == 1);

    wIter->next();
    CHECK(wIter->hasNext() == false);
    CHECK(wIter->getRow() == 2);
    CHECK(wIter->getCol() == 0);

    delete wIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing WoodProducerIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WoodProducer *producer = new WoodProducer();
    Theater *theater = new Theater();

    row1.push_back(producer);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    WoodProducerIterator *wIter = new WoodProducerIterator(grid);
    wIter->first();
    wIter->next();
    CHECK(wIter->hasNext() == false);

    delete wIter;
    delete producer;
    delete theater;
}
