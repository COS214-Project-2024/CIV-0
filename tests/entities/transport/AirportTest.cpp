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

    delete a1;
    delete cloneAirport;
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

TEST_CASE("Testing Airport subscribe and unsubscribe") {
    Airport* airport = new Airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 10, 10);
    House* house = new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    // Subscribe house to airport
    airport->subscribe(house);
    
    // Verify that house is in the observers list of airport
    CHECK(airport->getObservers().size() == 1);
    CHECK(airport->getObservers()[0] == house);
    
    // Subscribe airport to house
    house->subscribe(airport);
    
    // Verify that airport is in the observers list of house
    CHECK(house->getObservers().size() == 1);
    CHECK(house->getObservers()[0] == airport);
    
    // Unsubscribe house from airport
    airport->unsubscribe(house);
    
    // Verify that house is no longer in the observers list of airport
    CHECK(airport->getObservers().size() == 0);
    
    // Unsubscribe airport from house
    house->unsubscribe(airport);
    
    // Verify that airport is no longer in the observers list of house
    CHECK(house->getObservers().size() == 0);

    delete airport;
    delete house;
}