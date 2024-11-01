#include "doctest.h"
#include "entities/transport/Airport.h"
#include "entities/transport/BusStop.h"
#include "entities/transport/TrainStation.h"
#include "iterators/transport/TransportIterator.h"
#include <vector>

TEST_CASE("Testing TransportIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Airport *a = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    BusStop *b = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    TrainStation *t = new TrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(a);
    row1.push_back(b);
    row2.push_back(nullptr);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator *aIter = new TransportIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing TransportIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Airport *a = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    BusStop *b = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    TrainStation *t = new TrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(a);
    row1.push_back(nullptr);
    row2.push_back(b);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator *aIter = new TransportIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing TransportIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Airport *a = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    BusStop *b = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    TrainStation *t = new TrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(a);
    row1.push_back(nullptr);
    row2.push_back(b);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator *aIter = new TransportIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing TransportIterator hasNext() with multiple transports")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Airport *a = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    BusStop *b = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    TrainStation *t = new TrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(a);
    row1.push_back(nullptr);
    row2.push_back(b);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator *aIter = new TransportIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing TransportIterator reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Airport *a = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    BusStop *b = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    TrainStation *t = new TrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(a);
    row1.push_back(nullptr);
    row2.push_back(b);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator *aIter = new TransportIterator(grid);
    aIter->first();
    aIter->next();
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete a;
    delete b;
    delete t;
}
