#include "doctest.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/powerplant/PowerPlantLevelOneUpgrade.h"
#include "utils/ConfigManager.h"

TEST_SUITE("PowerPlant Tests")
{
    TEST_CASE("Constructor Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant powerPlant(ec, Size::SMALL, 0, 0);
        CHECK(powerPlant.getXPosition() == 0);
        CHECK(powerPlant.getYPosition() == 0);
        CHECK(powerPlant.getWidth() == ec.width);
        CHECK(powerPlant.getHeight() == ec.height);
        CHECK(powerPlant.getRevenue() == ec.revenue);
        CHECK(powerPlant.getCost() == ec.cost);
        CHECK(powerPlant.isBuilt() == false);
    }

    TEST_CASE("Set Position Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::MEDIUM);
        PowerPlant powerPlant(ec, Size::MEDIUM, 0, 0);
        powerPlant.setXPosition(10);
        powerPlant.setYPosition(15);
        CHECK(powerPlant.getXPosition() == 10);
        CHECK(powerPlant.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        PowerPlant copiedPowerPlant(&powerPlant);
        CHECK(copiedPowerPlant.getXPosition() == powerPlant.getXPosition());
        CHECK(copiedPowerPlant.getYPosition() == powerPlant.getYPosition());
        CHECK(copiedPowerPlant.getWidth() == powerPlant.getWidth());
        CHECK(copiedPowerPlant.getHeight() == powerPlant.getHeight());
        CHECK(copiedPowerPlant.getRevenue() == powerPlant.getRevenue());
        CHECK(copiedPowerPlant.getOutput() == powerPlant.getOutput());
        CHECK(copiedPowerPlant.getCost() == powerPlant.getCost());
        CHECK(copiedPowerPlant.isBuilt() == powerPlant.isBuilt());
    }

    TEST_CASE("Clone Method Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        PowerPlant *clonedPowerPlant = static_cast<PowerPlant *>(powerPlant.clone());
        REQUIRE(clonedPowerPlant != nullptr);
        CHECK(clonedPowerPlant->getXPosition() == powerPlant.getXPosition());
        CHECK(clonedPowerPlant->getYPosition() == powerPlant.getYPosition());
        CHECK(clonedPowerPlant->getWidth() == powerPlant.getWidth());
        CHECK(clonedPowerPlant->getHeight() == powerPlant.getHeight());
        CHECK(clonedPowerPlant->getRevenue() == powerPlant.getRevenue());
        CHECK(clonedPowerPlant->getOutput() == powerPlant.getOutput());
        CHECK(clonedPowerPlant->getCost() == powerPlant.getCost());
        CHECK(clonedPowerPlant->isBuilt() == powerPlant.isBuilt());
        delete clonedPowerPlant;
    }

    TEST_CASE("Update Method Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        CHECK(powerPlant.isBuilt() == false);

        // This simulates the game looping
        for (int i = 0; i < ec.buildTime; i++)
        {
            powerPlant.update();
        }

        CHECK(powerPlant.isBuilt() == true);
    }

    TEST_CASE("Output Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        powerPlant.setOutput(150);
        CHECK(powerPlant.getOutput() == 150);
    }

    TEST_CASE("Cost Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        CHECK(powerPlant.getCost() == ec.cost);
    }

    TEST_CASE("Revenue Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        CHECK(powerPlant.getRevenue() == ec.revenue);
    }

    TEST_CASE("Dimensions Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant powerPlant(ec, Size::LARGE, 0, 0);
        CHECK(powerPlant.getWidth() == ec.width);
        CHECK(powerPlant.getHeight() == ec.height);
    }

    TEST_CASE("isWithinEffectRadius Test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
        PowerPlant basePowerPlant(ec, Size::LARGE, 0, 0);

        SUBCASE("PowerPlant within radius")
        {
            PowerPlant nearbyPowerPlant(ec, Size::LARGE, 5, 5);
            CHECK(basePowerPlant.isWithinEffectRadius(&nearbyPowerPlant) == true);
        }

        SUBCASE("PowerPlant outside radius")
        {
            EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
            PowerPlant farPowerPlant(ec, Size::LARGE, 50, 50);
            CHECK(basePowerPlant.isWithinEffectRadius(&farPowerPlant) == false);
        }

        SUBCASE("PowerPlant exactly on border")
        {
            EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
            PowerPlant borderPowerPlant(ec, Size::LARGE, 42, 42);
            CHECK(basePowerPlant.isWithinEffectRadius(&borderPowerPlant) == false);
        }

        SUBCASE("PowerPlant partially overlaps with radius")
        {
            EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::LARGE);
            PowerPlant partialOverlapPowerPlant(ec, Size::LARGE, 41, 41);
            CHECK(basePowerPlant.isWithinEffectRadius(&partialOverlapPowerPlant) == false);
        }
    }

    TEST_CASE("Upgrade test")
    {
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);
        PowerPlant powerPlant(ec, Size::SMALL, 0, 0);
        Entity *upgradedEntity = powerPlant.upgrade();
        REQUIRE(upgradedEntity != nullptr);
        CHECK(dynamic_cast<PowerPlantLevelOneUpgrade *>(upgradedEntity) != nullptr);
        delete upgradedEntity;
    }
}