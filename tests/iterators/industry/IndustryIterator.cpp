#include "doctest.h"
#include "iterators/industry/IndustryIterator.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "entities/building/amenity/Theater.h"
#include <vector>

TEST_CASE("Testing IndustryIterator initial position")
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

    IndustryIterator *iIter = new IndustryIterator(grid);
    iIter->first();
    CHECK(iIter->getRow() == 0);
    CHECK(iIter->getCol() == 0);

    delete iIter;
    delete producer;
}

TEST_CASE("Testing IndustryIterator next()")
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

    IndustryIterator *iIter = new IndustryIterator(grid);
    iIter->first();
    CHECK(iIter->getRow() == 0);
    CHECK(iIter->getCol() == 0);
    CHECK(iIter->hasNext() == true);

    iIter->next();
    CHECK(iIter->getRow() == 2);
    CHECK(iIter->getCol() == 0);
    CHECK(iIter->hasNext() == false);

    delete iIter;
    delete producer;
    delete theater;
}

TEST_CASE("Testing IndustryIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer1 = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    WoodProducer *producer2 = new WoodProducer(ConfigManager::getEntityConfig(EntityType::WOODPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer1);
    row1.push_back(theater);
    row2.push_back(nullptr);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    IndustryIterator *iIter = new IndustryIterator(grid);
    iIter->first();
    CHECK(iIter->getRow() == 0);
    CHECK(iIter->getCol() == 0);
    CHECK(iIter->hasNext() == true);

    delete iIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing IndustryIterator hasNext() with multiple producers")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    ConcreteProducer *producer1 = new ConcreteProducer(ConfigManager::getEntityConfig(EntityType::CONCRETEPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    WoodProducer *producer2 = new WoodProducer(ConfigManager::getEntityConfig(EntityType::WOODPRODUCER, Size::SMALL), Size::SMALL, 10, 10);
    Theater *theater = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(producer1);
    row1.push_back(nullptr);
    row2.push_back(theater);
    row2.push_back(producer2);

    grid.push_back(row1);
    grid.push_back(row2);

    IndustryIterator *iIter = new IndustryIterator(grid);
    iIter->first();
    CHECK(iIter->hasNext() == true);
    CHECK(iIter->getRow() == 0);
    CHECK(iIter->getCol() == 0);

    iIter->next();
    CHECK(iIter->hasNext() == true);
    CHECK(iIter->getRow() == 1);
    CHECK(iIter->getCol() == 1);

    iIter->next();
    CHECK(iIter->hasNext() == false);
    CHECK(iIter->getRow() == 2);
    CHECK(iIter->getCol() == 0);

    delete iIter;
    delete producer1;
    delete producer2;
    delete theater;
}

TEST_CASE("Testing IndustryIterator hasNext() reaching the end")
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

    IndustryIterator *iIter = new IndustryIterator(grid);
    iIter->first();
    iIter->next();
    CHECK(iIter->hasNext() == false);

    delete iIter;
    delete producer;
    delete theater;
}
