#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

TEST_SUITE("SewageSystemLevelTwoUpgrade Tests") {
    TEST_CASE("SewageSystemLevelTwoUpgrade constructor") {
        SewageSystem basePlant(500, 300, "P", 5, 10, 15, 20, 10, 1000, Size::MEDIUM, 10, 20, 120);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1000);
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade update()") {
        SewageSystem basePlant(400, 200, "P", 6, 12, 20, 25, 15, 2000, Size::LARGE, 5, 8, 100);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 800);
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade clone()") {
        SewageSystem basePlant(350, 150, "P", 4, 8, 12, 18, 12, 1500, Size::SMALL, 3, 7, 90);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        SewageSystemLevelTwoUpgrade* cloned = dynamic_cast<SewageSystemLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 700);

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade getOutput()") {
        SewageSystem basePlant(600, 400, "P", 7, 14, 18, 30, 18, 2500, Size::LARGE, 12, 16, 150);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1200);
    }
}