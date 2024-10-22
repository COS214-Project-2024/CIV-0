#include "doctest.h"
#include "entities/utility/powerplant/PowerPlant.h"

TEST_SUITE("PowerPlant Tests") {
    TEST_CASE("Constructor Test") {
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(powerPlant.getXPosition() == 0);
        CHECK(powerPlant.getYPosition() == 0);
        CHECK(powerPlant.getWidth() == 5);
        CHECK(powerPlant.getHeight() == 5);
        CHECK(powerPlant.getRevenue() == 1000);
        CHECK(powerPlant.getOutput() == 20);
        CHECK(powerPlant.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        powerPlant.setXPosition(10);
        powerPlant.setYPosition(15);
        CHECK(powerPlant.getXPosition() == 10);
        CHECK(powerPlant.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
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
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
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
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(powerPlant.isBuilt() == false);
        powerPlant.update();
        CHECK(powerPlant.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        powerPlant.setOutput(150);
        CHECK(powerPlant.getOutput() == 150);
    }

    TEST_CASE("Revenue Test") {
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(powerPlant.getRevenue() == 1000);
    }

    TEST_CASE("Dimensions Test") {
        PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(powerPlant.getWidth() == 5);
        CHECK(powerPlant.getHeight() == 5);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        PowerPlant basePowerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        
        SUBCASE("PowerPlant within radius") {
            PowerPlant nearbyPowerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 5, 5, 1);
            CHECK(basePowerPlant.isWithinEffectRadius(&nearbyPowerPlant) == true);
        }

        SUBCASE("PowerPlant outside radius") {
            PowerPlant farPowerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 50, 50, 1);
            CHECK(basePowerPlant.isWithinEffectRadius(&farPowerPlant) == false);
        }

        SUBCASE("PowerPlant exactly on border") {
            PowerPlant borderPowerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 15, 15, 1);
            CHECK(basePowerPlant.isWithinEffectRadius(&borderPowerPlant) == false);
        }

        SUBCASE("PowerPlant partially overlaps with radius") {
            PowerPlant partialOverlapPowerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 9, 9, 1);
            CHECK(basePowerPlant.isWithinEffectRadius(&partialOverlapPowerPlant) == true);
        }
    }
}