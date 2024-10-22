#include "doctest.h"
#include "entities/transport/Airport.h"
#include "entities/building/residential/House.h"

TEST_CASE("Testing Airport constructor and clone")
{
    Entity* a1 = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    
    // CHECK(a1->getXPosition() == 10);
    // CHECK(a1->getYPosition() == 20);
    // CHECK(a1->getRevenue() == 1000);
    // CHECK(a1->getWidth() == 5);
    // CHECK(a1->getHeight() == 5);

    Entity* cloneAirport = a1->clone();
    // CHECK(cloneAirport->getXPosition() == 10);
    // CHECK(cloneAirport->getYPosition() == 20);
    // CHECK(cloneAirport->getRevenue() == 1000);

    delete cloneAirport;
    delete a1;
}

TEST_CASE("Testing Airport update")
{
    Airport* airport = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    House* house = new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    airport->subscribe(house);

    airport->update();
    
    CHECK(house->getSatisfaction() <= 100);

    delete airport;
    delete house;
}

TEST_CASE("Testing Airport subscribe and unsubscribe")
{
    Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    House rb(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    CHECK(airport.subscribe(&rb) == true);
    CHECK(airport.subscribe(&rb) == false);

    CHECK(airport.unsubscribe(&rb) == true);
    CHECK(airport.unsubscribe(&rb) == false);
}