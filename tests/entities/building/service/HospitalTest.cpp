#include "doctest.h"
#include "entities/building/service/Hospital.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Hospital Tests") {
    TEST_CASE("Constructor Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(hospital.getXPosition() == 0);
        CHECK(hospital.getYPosition() == 0);
        CHECK(hospital.getWidth() == 6);
        CHECK(hospital.getHeight() == 6);
        CHECK(hospital.getRevenue() == 10000);
        CHECK(hospital.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::MEDIUM), Size::MEDIUM, 0, 0);
        hospital.setXPosition(10);
        hospital.setYPosition(15);
        CHECK(hospital.getXPosition() == 10);
        CHECK(hospital.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 0, 0);
        Hospital copiedHospital(&hospital);
        CHECK(copiedHospital.getXPosition() == hospital.getXPosition());
        CHECK(copiedHospital.getYPosition() == hospital.getYPosition());
        CHECK(copiedHospital.getWidth() == hospital.getWidth());
        CHECK(copiedHospital.getHeight() == hospital.getHeight());
        CHECK(copiedHospital.getRevenue() == hospital.getRevenue());
        CHECK(copiedHospital.isBuilt() == hospital.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 0, 0);
        Hospital* clonedHospital = static_cast<Hospital*>(hospital.clone());
        REQUIRE(clonedHospital != nullptr);
        CHECK(clonedHospital->getXPosition() == hospital.getXPosition());
        CHECK(clonedHospital->getYPosition() == hospital.getYPosition());
        CHECK(clonedHospital->getWidth() == hospital.getWidth());
        CHECK(clonedHospital->getHeight() == hospital.getHeight());
        CHECK(clonedHospital->getRevenue() == hospital.getRevenue());
        CHECK(clonedHospital->isBuilt() == hospital.isBuilt());
        delete clonedHospital;
    }

    TEST_CASE("Update Method Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(hospital.isBuilt() == false);

        // This simulates the game looping
        while (!hospital.isBuilt()) {
            hospital.update();
        }
        
        CHECK(hospital.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(hospital.getRevenue() == 30000);
    }

    TEST_CASE("Dimensions Test") {
        Hospital hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(hospital.getWidth() == 10);
        CHECK(hospital.getHeight() == 10);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        Hospital baseHospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("Hospital within radius") {
            Hospital nearbyHospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 15, 15);
            CHECK(baseHospital.isWithinEffectRadius(&nearbyHospital) == true);
        }

        SUBCASE("Hospital outside radius") {
            Hospital farHospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseHospital.isWithinEffectRadius(&farHospital) == false);
        }

        SUBCASE("Hospital exactly on border") {
            Hospital borderHospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 30, 30);
            CHECK(baseHospital.isWithinEffectRadius(&borderHospital) == false);
        }

        SUBCASE("Hospital partially overlaps with radius") {
            Hospital partialOverlapHospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::LARGE), Size::LARGE, 29, 29);
            CHECK(baseHospital.isWithinEffectRadius(&partialOverlapHospital) == true);
        }
    }
}
