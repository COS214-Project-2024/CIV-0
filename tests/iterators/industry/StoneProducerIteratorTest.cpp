#include "doctest.h"
#include "iterators/industry/StoneProducerIterator.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/building/amenity/Theater.h"
#include <vector>

TEST_CASE("Testing StoneProducerIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    StoneProducer *producer = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer);
    row1.push_back(nullptr);
    row2.push_back(producer);
    row2.push_back(producer);

    grid.push_back(row1);
    grid.push_back(row2);

    StoneProducerIterator *sIter = new StoneProducerIterator(grid);
    sIter->first();
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);

    delete sIter;
    delete producer;
}

TEST_CASE("Testing StoneProducerIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    StoneProducer *producer = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer);

    grid.push_back(row1);
    grid.push_back(row2);

    StoneProducerIterator *sIter = new StoneProducerIterator(grid);
    sIter->first();
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);
    CHECK(sIter->hasNext() == true);

    sIter->next();
    CHECK(sIter->getRow() == 2);
    CHECK(sIter->getCol() == 0);
    CHECK(sIter->hasNext() == false);

    delete sIter;
    delete producer;
    delete theater;
}

TEST_CASE("Testing StoneProducerIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    StoneProducer *producer1 = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    StoneProducer *producer2 = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer1);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    StoneProducerIterator *sIter = new StoneProducerIterator(grid);
    sIter->first();
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);
    CHECK(sIter->hasNext() == true);

    delete sIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing StoneProducerIterator hasNext() with multiple producers")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    StoneProducer *producer1 = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    StoneProducer *producer2 = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer1);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    StoneProducerIterator *sIter = new StoneProducerIterator(grid);
    sIter->first();
    CHECK(sIter->hasNext() == true);
    CHECK(sIter->getRow() == 0);
    CHECK(sIter->getCol() == 0);

    sIter->next();
    CHECK(sIter->hasNext() == true);
    CHECK(sIter->getRow() == 1);
    CHECK(sIter->getCol() == 1);

    sIter->next();
    CHECK(sIter->hasNext() == false);
    CHECK(sIter->getRow() == 2);
    CHECK(sIter->getCol() == 0);

    delete sIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing StoneProducerIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    StoneProducer *producer = new StoneProducer(ConfigManager::getEntityConfig(EntityType::STONEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    StoneProducerIterator *sIter = new StoneProducerIterator(grid);
    sIter->first();
    sIter->next();
    CHECK(sIter->hasNext() == false);

    delete sIter;
    delete producer;
    delete theater;
}
