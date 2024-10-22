#include "doctest.h"
#include "entities/utility/watersupply/WaterSupplyLevelTwoUpgrade.h"
#include "entities/utility/watersupply/WaterSupply.h"

TEST_SUITE("WaterSupplyLevelTwoUpgrade Tests") {
    TEST_CASE("WaterSupplyLevelTwoUpgrade constructor") {
        WaterSupply basePlant(500, 300, "P", 5, 10, 15, 20, 10, 1000, Size::MEDIUM, 10, 20, 120);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1000);
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade update()") {
        WaterSupply basePlant(400, 200, "P", 6, 12, 20, 25, 15, 2000, Size::LARGE, 5, 8, 100);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 800);
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade clone()") {
        WaterSupply basePlant(350, 150, "P", 4, 8, 12, 18, 12, 1500, Size::SMALL, 3, 7, 90);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WaterSupplyLevelTwoUpgrade* cloned = dynamic_cast<WaterSupplyLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 700);

        delete clonedUpgrade;
    }

    TEST_CASE("WaterSupplyLevelTwoUpgrade getOutput()") {
        WaterSupply basePlant(600, 400, "P", 7, 14, 18, 30, 18, 2500, Size::LARGE, 12, 16, 150);
        WaterSupplyLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1200);
    }
}