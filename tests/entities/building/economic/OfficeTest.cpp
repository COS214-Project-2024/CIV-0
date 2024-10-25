#include "doctest.h"
#include "entities/building/economic/Office.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Office Tests") {
    TEST_CASE("Constructor Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(office.getXPosition() == 0);
        CHECK(office.getYPosition() == 0);
        CHECK(office.getWidth() == 3);
        CHECK(office.getHeight() == 3);
        CHECK(office.getRevenue() == 2000);
        CHECK(office.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::MEDIUM), Size::MEDIUM, 0, 0);
        office.setXPosition(10);
        office.setYPosition(15);
        CHECK(office.getXPosition() == 10);
        CHECK(office.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 0, 0);
        Office copiedOffice(&office);
        CHECK(copiedOffice.getXPosition() == office.getXPosition());
        CHECK(copiedOffice.getYPosition() == office.getYPosition());
        CHECK(copiedOffice.getWidth() == office.getWidth());
        CHECK(copiedOffice.getHeight() == office.getHeight());
        CHECK(copiedOffice.getRevenue() == office.getRevenue());
        CHECK(copiedOffice.isBuilt() == office.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 0, 0);
        Office* clonedOffice = static_cast<Office*>(office.clone());
        REQUIRE(clonedOffice != nullptr);
        CHECK(clonedOffice->getXPosition() == office.getXPosition());
        CHECK(clonedOffice->getYPosition() == office.getYPosition());
        CHECK(clonedOffice->getWidth() == office.getWidth());
        CHECK(clonedOffice->getHeight() == office.getHeight());
        CHECK(clonedOffice->getRevenue() == office.getRevenue());
        CHECK(clonedOffice->isBuilt() == office.isBuilt());
        delete clonedOffice;
    }

    TEST_CASE("Update Method Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(office.isBuilt() == false);

        // This simulates the game looping
        while (!office.isBuilt()) {
            office.update();
        }
        
        CHECK(office.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(office.getRevenue() == 6000);
    }

    TEST_CASE("Dimensions Test") {
        Office office(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(office.getWidth() == 5);
        CHECK(office.getHeight() == 5);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        Office baseOffice(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("Office within radius") {
            Office nearbyOffice(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 10, 10);
            CHECK(baseOffice.isWithinEffectRadius(&nearbyOffice) == true);
        }

        SUBCASE("Office outside radius") {
            Office farOffice(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseOffice.isWithinEffectRadius(&farOffice) == false);
        }

        SUBCASE("Office exactly on border") {
            Office borderOffice(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 15, 15);
            CHECK(baseOffice.isWithinEffectRadius(&borderOffice) == false);
        }

        SUBCASE("Office partially overlaps with radius") {
            Office partialOverlapOffice(ConfigManager::getEntityConfig(EntityType::OFFICE, Size::LARGE), Size::LARGE, 14, 14);
            CHECK(baseOffice.isWithinEffectRadius(&partialOverlapOffice) == true);
        }
    }
}