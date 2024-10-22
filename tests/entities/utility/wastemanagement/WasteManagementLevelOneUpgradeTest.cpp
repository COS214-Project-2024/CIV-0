#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagementLevelOneUpgrade.h"
#include "entities/utility/wastemanagement/WasteManagement.h"

TEST_SUITE("WasteManagementLevelOneUpgrade Tests") {
    TEST_CASE("WasteManagementLevelOneUpgrade constructor") {
        WasteManagement basePlant(500, 300, "P", 5, 10, 15, 20, 10, 1000, Size::MEDIUM, 10, 20, 120);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1000);
    }

    TEST_CASE("WasteManagementLevelOneUpgrade update()") {
        WasteManagement basePlant(400, 200, "P", 6, 12, 20, 25, 15, 2000, Size::LARGE, 5, 8, 100);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 800);
    }

    TEST_CASE("WasteManagementLevelOneUpgrade clone()") {
        WasteManagement basePlant(350, 150, "P", 4, 8, 12, 18, 12, 1500, Size::SMALL, 3, 7, 90);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        WasteManagementLevelOneUpgrade* cloned = dynamic_cast<WasteManagementLevelOneUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 700);

        delete clonedUpgrade;
    }

    TEST_CASE("WasteManagementLevelOneUpgrade getOutput()") {
        WasteManagement basePlant(600, 400, "P", 7, 14, 18, 30, 18, 2500, Size::LARGE, 12, 16, 150);
        WasteManagementLevelOneUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 1200);
    }
}