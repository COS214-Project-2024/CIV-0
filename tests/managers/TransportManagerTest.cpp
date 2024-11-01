#include "doctest.h"
#include "managers/TransportManager.h"
#include "city/City.h"
#include "entities/road/Road.h"
#include "entities/transport/BusStop.h"
#include "utils/ConfigManager.h"

TEST_CASE("TransportManagerTest buildRoad with sufficient resources") {
    City* city = City::instance();
    city->reset();
    city->setMoney(10000);   // Set sufficient resources
    city->setWood(1000);
    city->setStone(1000);
    city->setConcrete(1000);

    TransportManager tm;
    CHECK(tm.canAffordRoad() == true);
    CHECK(tm.buildRoad(5, 5) == true); // Attempt to build road
    CHECK(dynamic_cast<Road*>(city->getEntity(5, 5)) != nullptr); // Verify road added to City
}

TEST_CASE("TransportManagerTest buildRoad with insufficient resources") {
    City* city = City::instance();
    city->reset();
    city->setMoney(0);    // Set insufficient resources
    city->setWood(0);
    city->setStone(0);
    city->setConcrete(0);

    TransportManager tm;
    CHECK(tm.canAffordRoad() == false);
    CHECK(tm.buildRoad(5, 5) == false); // Attempt to build road
    CHECK(city->getEntity(5, 5) == nullptr); // Ensure no road was added
}

TEST_CASE("TransportManagerTest buildPublicTransit with sufficient resources") {
    City* city = City::instance();
    city->reset();
    city->setMoney(10000);   // Set sufficient resources
    city->setWood(1000);
    city->setStone(1000);
    city->setConcrete(1000);

    TransportManager tm;
    CHECK(tm.canAffordPublicTransit(EntityType::BUSSTOP, Size::SMALL) == true);
    CHECK(tm.buildPublicTransit(EntityType::BUSSTOP, Size::SMALL, 3, 3) == true);
    CHECK(dynamic_cast<BusStop*>(city->getEntity(3, 3)) != nullptr); // Verify bus station added
}

TEST_CASE("TransportManagerTest buildPublicTransit with insufficient resources") {
    City* city = City::instance();
    city->reset();
    city->setMoney(0);    // Set insufficient resources
    city->setWood(0);
    city->setStone(0);
    city->setConcrete(0);

    TransportManager tm;
    CHECK(tm.canAffordPublicTransit(EntityType::BUSSTOP, Size::SMALL) == false);
    CHECK(tm.buildPublicTransit(EntityType::BUSSTOP, Size::SMALL, 3, 3) == false);
    CHECK(city->getEntity(3, 3) == nullptr); // Ensure no bus station was added
}
