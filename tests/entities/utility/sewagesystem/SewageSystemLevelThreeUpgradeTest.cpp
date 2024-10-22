#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelThreeUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

TEST_SUITE("SewageSystemLevelThreeUpgrade Tests") {
    // TEST_CASE("SewageSystemLevelThreeUpgrade constructor") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("SewageSystemLevelThreeUpgrade update()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelThreeUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("SewageSystemLevelThreeUpgrade clone()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelThreeUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     SewageSystemLevelThreeUpgrade* cloned = dynamic_cast<SewageSystemLevelThreeUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("SewageSystemLevelThreeUpgrade getOutput()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelThreeUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}