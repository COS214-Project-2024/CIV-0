#include "doctest.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlant Tests") {
    TEST_CASE("Constructor Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(powerPlant.getXPosition() == 0);
        CHECK(powerPlant.getYPosition() == 0);
        CHECK(powerPlant.getWidth() == 8);
        CHECK(powerPlant.getHeight() == 8);
        CHECK(powerPlant.getRevenue() == 0);
        CHECK(powerPlant.getOutput() == 20);
        CHECK(powerPlant.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM), Size::MEDIUM, 0, 0);
        powerPlant.setXPosition(10);
        powerPlant.setYPosition(15);
        CHECK(powerPlant.getXPosition() == 10);
        CHECK(powerPlant.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        PowerPlant copiedPowerPlant(&powerPlant);
        CHECK(copiedPowerPlant.getXPosition() == powerPlant.getXPosition());
        CHECK(copiedPowerPlant.getYPosition() == powerPlant.getYPosition());
        CHECK(copiedPowerPlant.getWidth() == powerPlant.getWidth());
        CHECK(copiedPowerPlant.getHeight() == powerPlant.getHeight());
        CHECK(copiedPowerPlant.getRevenue() == powerPlant.getRevenue());
        CHECK(copiedPowerPlant.getOutput() == powerPlant.getOutput());
        CHECK(copiedPowerPlant.isBuilt() == powerPlant.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        PowerPlant* clonedPowerPlant = static_cast<PowerPlant*>(powerPlant.clone());
        REQUIRE(clonedPowerPlant != nullptr);
        CHECK(clonedPowerPlant->getXPosition() == powerPlant.getXPosition());
        CHECK(clonedPowerPlant->getYPosition() == powerPlant.getYPosition());
        CHECK(clonedPowerPlant->getWidth() == powerPlant.getWidth());
        CHECK(clonedPowerPlant->getHeight() == powerPlant.getHeight());
        CHECK(clonedPowerPlant->getRevenue() == powerPlant.getRevenue());
        CHECK(clonedPowerPlant->getOutput() == powerPlant.getOutput());
        CHECK(clonedPowerPlant->isBuilt() == powerPlant.isBuilt());
        delete clonedPowerPlant;
    }

    TEST_CASE("Update Method Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(powerPlant.isBuilt() == false);

        // This simulates the game looping
        while (!powerPlant.isBuilt()) {
            powerPlant.update();
        }
        
        CHECK(powerPlant.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        powerPlant.setOutput(150);
        CHECK(powerPlant.getOutput() == 150);
    }

    TEST_CASE("Revenue Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(powerPlant.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        PowerPlant powerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(powerPlant.getWidth() == 12);
        CHECK(powerPlant.getHeight() == 12);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        PowerPlant basePowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("PowerPlant within radius") {
            PowerPlant nearbyPowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 5, 5);
            CHECK(basePowerPlant.isWithinEffectRadius(&nearbyPowerPlant) == true);
        }

        SUBCASE("PowerPlant outside radius") {
            PowerPlant farPowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(basePowerPlant.isWithinEffectRadius(&farPowerPlant) == false);
        }

        SUBCASE("PowerPlant exactly on border") {
            PowerPlant borderPowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 42, 42);
            CHECK(basePowerPlant.isWithinEffectRadius(&borderPowerPlant) == false);
        }

        SUBCASE("PowerPlant partially overlaps with radius") {
            PowerPlant partialOverlapPowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE), Size::LARGE, 41, 41);
            CHECK(basePowerPlant.isWithinEffectRadius(&partialOverlapPowerPlant) == true);
        }
    }
}