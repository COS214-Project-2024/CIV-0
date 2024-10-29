#include "doctest.h"
#include "entities/transport/BusStop.h"
#include "entities/building/residential/House.h"

TEST_CASE("Testing BusStop constructor and clone")
{
    Entity* a1 = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    
    // CHECK(a1->getXPosition() == 10);
    // CHECK(a1->getYPosition() == 20);
    // CHECK(a1->getRevenue() == 1000);
    // CHECK(a1->getWidth() == 5);
    // CHECK(a1->getHeight() == 5);

    Entity* cloneBusStop = a1->clone();
    // CHECK(cloneBusStop->getXPosition() == 10);
    // CHECK(cloneBusStop->getYPosition() == 20);
    // CHECK(cloneBusStop->getRevenue() == 1000);

    delete cloneBusStop;
    delete a1;
}

TEST_CASE("Testing BusStop update")
{
    BusStop* busStop = new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    House* house = new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    busStop->subscribe(house);

    busStop->update();
    
    CHECK(house->getSatisfaction() <= 100);

    delete busStop;
    delete house;
}

TEST_CASE("Testing BusStop subscribe and unsubscribe")
{
    BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 10, 10);
    House rb(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    // CHECK(busStop.subscribe(&rb) == true);
    // CHECK(busStop.subscribe(&rb) == false);

    // CHECK(busStop.unsubscribe(&rb) == true);
    // CHECK(busStop.unsubscribe(&rb) == false);
}
