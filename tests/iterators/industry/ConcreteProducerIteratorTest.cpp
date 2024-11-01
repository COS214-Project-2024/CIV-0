#include "doctest.h"
#include "iterators/industry/ConcreteProducerIterator.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/building/amenity/Theater.h"
#include <iostream>
#include <vector>

TEST_CASE("Testing ConcreteProducerIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer);
    row1.push_back(nullptr);
    row2.push_back(producer);
    row2.push_back(producer);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator *cIter = new ConcreteProducerIterator(grid);
    cIter->first();
    CHECK(cIter->getRow() == 0);
    CHECK(cIter->getCol() == 0);

    delete cIter;
    delete producer;
}

TEST_CASE("Testing ConcreteProducerIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator *cIter = new ConcreteProducerIterator(grid);
    cIter->first();
    CHECK(cIter->getRow() == 0);
    CHECK(cIter->getCol() == 0);
    CHECK(cIter->hasNext() == true);

    cIter->next();

    CHECK(cIter->getRow() == 2);
    CHECK(cIter->getCol() == 0);
    CHECK(cIter->hasNext() == false);

    delete cIter;
    delete producer;
    delete theater;
}

TEST_CASE("Testing ConcreteProducerIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer1 = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    ConcreteProducer *producer2 = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer1);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator *cIter = new ConcreteProducerIterator(grid);
    cIter->first();
    CHECK(cIter->getRow() == 0);
    CHECK(cIter->getCol() == 0);
    CHECK(cIter->hasNext() == true);

    delete cIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing ConcreteProducerIterator hasNext() with multiple producers")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer1 = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    ConcreteProducer *producer2 = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer1);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator *cIter = new ConcreteProducerIterator(grid);
    cIter->first();
    CHECK(cIter->hasNext() == true);
    CHECK(cIter->getRow() == 0);
    CHECK(cIter->getCol() == 0);

    cIter->next();
    CHECK(cIter->hasNext() == true);
    CHECK(cIter->getRow() == 1);
    CHECK(cIter->getCol() == 1);

    delete cIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing ConcreteProducerIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    ConcreteProducerIterator *cIter = new ConcreteProducerIterator(grid);
    cIter->first();
    cIter->next();
    CHECK(cIter->hasNext() == false);

    delete cIter;
    delete producer;
    delete theater;
}
