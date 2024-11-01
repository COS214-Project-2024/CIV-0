#include "doctest.h"
#include "iterators/utility/WaterSupplyIterator.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("WaterSupplyIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WaterSupply *ws1 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 5, 5);

    row1.push_back(ws1);
    row1.push_back(ws1);
    row2.push_back(nullptr);
    row2.push_back(ws1);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator *wsIter = new WaterSupplyIterator(grid);
    wsIter->first();
    CHECK(wsIter->getRow() == 0);
    CHECK(wsIter->getCol() == 0);

    delete wsIter;
    delete ws1;
    delete t;
}

TEST_CASE("WaterSupplyIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WaterSupply *ws1 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 5, 5);

    row1.push_back(ws1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(ws1);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator *wsIter = new WaterSupplyIterator(grid);
    wsIter->first();
    CHECK(wsIter->getRow() == 0);
    CHECK(wsIter->getCol() == 0);

    wsIter->next();
    CHECK(wsIter->getRow() == 2);
    CHECK(wsIter->getCol() == 0);
    CHECK(wsIter->hasNext() == false);

    delete wsIter;
    delete ws1;
    delete t;
}

TEST_CASE("WaterSupplyIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WaterSupply *ws1 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 5, 5);

    row1.push_back(ws1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(ws1);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator *wsIter = new WaterSupplyIterator(grid);
    wsIter->first();
    CHECK(wsIter->getRow() == 0);
    CHECK(wsIter->getCol() == 0);
    CHECK(wsIter->hasNext() == true);

    delete wsIter;
    delete ws1;
    delete t;
}

TEST_CASE("WaterSupplyIterator hasNext() with multiple WaterSupply instances")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WaterSupply *ws1 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    WaterSupply *ws2 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 5, 5);

    row1.push_back(ws1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(ws2);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator *wsIter = new WaterSupplyIterator(grid);
    wsIter->first();
    CHECK(wsIter->hasNext() == true);
    CHECK(wsIter->getRow() == 0);
    CHECK(wsIter->getCol() == 0);

    wsIter->next();
    CHECK(wsIter->getRow() == 1);
    CHECK(wsIter->getCol() == 1);
    CHECK(wsIter->hasNext() == true);

    wsIter->next();
    CHECK(wsIter->getRow() == 2);
    CHECK(wsIter->getCol() == 0);
    CHECK(wsIter->hasNext() == false);

    delete wsIter;
    delete ws1;
    delete ws2;
    delete t;
}

TEST_CASE("WaterSupplyIterator reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WaterSupply *ws1 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 5, 5);

    row1.push_back(ws1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    WaterSupplyIterator *wsIter = new WaterSupplyIterator(grid);
    wsIter->first();
    wsIter->next();
    CHECK(wsIter->hasNext() == false);

    delete wsIter;
    delete ws1;
    delete t;
}