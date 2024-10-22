#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

TEST_SUITE("SewageSystemLevelThreeUpgrade Tests") {
    TEST_CASE("SewageSystemLevelThreeUpgrade constructor") {
        SewageSystem basePlant(500, 300, "P", 5, 10, 15, 20, 10, 1000, Size::MEDIUM, 10, 20, 120);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1000);
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade update()") {
        SewageSystem basePlant(400, 200, "P", 6, 12, 20, 25, 15, 2000, Size::LARGE, 5, 8, 100);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 800);
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade clone()") {
        SewageSystem basePlant(350, 150, "P", 4, 8, 12, 18, 12, 1500, Size::SMALL, 3, 7, 90);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        SewageSystemLevelThreeUpgrade* cloned = dynamic_cast<SewageSystemLevelThreeUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 700);

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelThreeUpgrade getOutput()") {
        SewageSystem basePlant(600, 400, "P", 7, 14, 18, 30, 18, 2500, Size::LARGE, 12, 16, 150);
        SewageSystemLevelThreeUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1200);
    }
}