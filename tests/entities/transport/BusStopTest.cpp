#include "doctest.h"
#include "entities/transport/BusStop.h"
#include "utils/ConfigManager.h"

TEST_SUITE("BusStop Tests") {
    TEST_CASE("Constructor Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(busStop.getXPosition() == 0);
        CHECK(busStop.getYPosition() == 0);
        CHECK(busStop.getWidth() == 1);
        CHECK(busStop.getHeight() == 1);
        CHECK(busStop.getRevenue() == 0);
        // CHECK(busStop.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::MEDIUM), Size::MEDIUM, 0, 0);
        busStop.setXPosition(10);
        busStop.setYPosition(15);
        CHECK(busStop.getXPosition() == 10);
        CHECK(busStop.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
        BusStop copiedBusStop(&busStop);
        CHECK(copiedBusStop.getXPosition() == busStop.getXPosition());
        CHECK(copiedBusStop.getYPosition() == busStop.getYPosition());
        CHECK(copiedBusStop.getWidth() == busStop.getWidth());
        CHECK(copiedBusStop.getHeight() == busStop.getHeight());
        CHECK(copiedBusStop.getRevenue() == busStop.getRevenue());
        CHECK(copiedBusStop.isBuilt() == busStop.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
        BusStop* clonedBusStop = static_cast<BusStop*>(busStop.clone());
        REQUIRE(clonedBusStop != nullptr);
        CHECK(clonedBusStop->getXPosition() == busStop.getXPosition());
        CHECK(clonedBusStop->getYPosition() == busStop.getYPosition());
        CHECK(clonedBusStop->getWidth() == busStop.getWidth());
        CHECK(clonedBusStop->getHeight() == busStop.getHeight());
        CHECK(clonedBusStop->getRevenue() == busStop.getRevenue());
        CHECK(clonedBusStop->isBuilt() == busStop.isBuilt());
        delete clonedBusStop;
    }

    TEST_CASE("Update Method Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
        // CHECK(busStop.isBuilt() == false);

        // This simulates the game looping
        // while (!busStop.isBuilt()) {
            busStop.update();
        // }
        
        CHECK(busStop.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(busStop.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        BusStop busStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(busStop.getWidth() == 1);
        CHECK(busStop.getHeight() == 1);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        BusStop baseBusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("BusStop within radius") {
            BusStop nearbyBusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 0, 0);
            CHECK(baseBusStop.isWithinEffectRadius(&nearbyBusStop) == true);
        }

        SUBCASE("BusStop outside radius") {
            BusStop farBusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseBusStop.isWithinEffectRadius(&farBusStop) == false);
        }

        // SUBCASE("BusStop exactly on border") {
        //     BusStop borderBusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 42, 42);
        //     CHECK(baseBusStop.isWithinEffectRadius(&borderBusStop) == false);
        // }

        // SUBCASE("BusStop partially overlaps with radius") {
        //     BusStop partialOverlapBusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 41, 41);
        //     CHECK(baseBusStop.isWithinEffectRadius(&partialOverlapBusStop) == true);
        // }
    }
}
