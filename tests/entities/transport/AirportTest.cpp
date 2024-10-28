#include "doctest.h"
#include "entities/transport/Airport.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Airport Tests") {
    TEST_CASE("Constructor Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(airport.getXPosition() == 0);
        CHECK(airport.getYPosition() == 0);
        CHECK(airport.getWidth() == 1);
        CHECK(airport.getHeight() == 1);
        CHECK(airport.getRevenue() == 0);
        // CHECK(airport.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::MEDIUM), Size::MEDIUM, 0, 0);
        airport.setXPosition(10);
        airport.setYPosition(15);
        CHECK(airport.getXPosition() == 10);
        CHECK(airport.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
        Airport copiedAirport(&airport);
        CHECK(copiedAirport.getXPosition() == airport.getXPosition());
        CHECK(copiedAirport.getYPosition() == airport.getYPosition());
        CHECK(copiedAirport.getWidth() == airport.getWidth());
        CHECK(copiedAirport.getHeight() == airport.getHeight());
        CHECK(copiedAirport.getRevenue() == airport.getRevenue());
        CHECK(copiedAirport.isBuilt() == airport.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
        Airport* clonedAirport = static_cast<Airport*>(airport.clone());
        REQUIRE(clonedAirport != nullptr);
        CHECK(clonedAirport->getXPosition() == airport.getXPosition());
        CHECK(clonedAirport->getYPosition() == airport.getYPosition());
        CHECK(clonedAirport->getWidth() == airport.getWidth());
        CHECK(clonedAirport->getHeight() == airport.getHeight());
        CHECK(clonedAirport->getRevenue() == airport.getRevenue());
        CHECK(clonedAirport->isBuilt() == airport.isBuilt());
        delete clonedAirport;
    }

    TEST_CASE("Update Method Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
        // CHECK(airport.isBuilt() == false);

        // This simulates the game looping
        // while (!airport.isBuilt()) {
            airport.update();
        // }
        
        CHECK(airport.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(airport.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        Airport airport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(airport.getWidth() == 1);
        CHECK(airport.getHeight() == 1);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        Airport baseAirport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("Airport within radius") {
            Airport nearbyAirport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 0, 0);
            CHECK(baseAirport.isWithinEffectRadius(&nearbyAirport) == true);
        }

        SUBCASE("Airport outside radius") {
            Airport farAirport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseAirport.isWithinEffectRadius(&farAirport) == false);
        }

        // SUBCASE("Airport exactly on border") {
        //     Airport borderAirport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 42, 42);
        //     CHECK(baseAirport.isWithinEffectRadius(&borderAirport) == false);
        // }

        // SUBCASE("Airport partially overlaps with radius") {
        //     Airport partialOverlapAirport(ConfigManager::getEntityConfig(EntityType::AIRPORT, Size::LARGE), Size::LARGE, 41, 41);
        //     CHECK(baseAirport.isWithinEffectRadius(&partialOverlapAirport) == true);
        // }
    }
}
