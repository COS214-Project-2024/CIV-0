#include "doctest.h"
#include "entities/utility/powerplant/PowerPlantLevelTwoUpgrade.h"
#include "entities/utility/powerplant/PowerPlant.h"

TEST_SUITE("PowerPlantLevelTwoUpgrade Tests") {
    TEST_CASE("PowerPlantLevelTwoUpgrade constructor") {
        PowerPlant basePlant(500, 300, "P", 5, 10, 15, 20, 10, 1000, Size::MEDIUM, 10, 20, 120);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1000);
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade update()") {
        PowerPlant basePlant(400, 200, "P", 6, 12, 20, 25, 15, 2000, Size::LARGE, 5, 8, 100);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 800);
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade clone()") {
        PowerPlant basePlant(350, 150, "P", 4, 8, 12, 18, 12, 1500, Size::SMALL, 3, 7, 90);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        PowerPlantLevelTwoUpgrade* cloned = dynamic_cast<PowerPlantLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 700);

        delete clonedUpgrade;
    }

    TEST_CASE("PowerPlantLevelTwoUpgrade getOutput()") {
        PowerPlant basePlant(600, 400, "P", 7, 14, 18, 30, 18, 2500, Size::LARGE, 12, 16, 150);
        PowerPlantLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1200);
    }
}