#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

TEST_SUITE("SewageSystemLevelTwoUpgrade Tests") {
    // TEST_CASE("SewageSystemLevelTwoUpgrade constructor") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelTwoUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1000);
    // }

    // TEST_CASE("SewageSystemLevelTwoUpgrade update()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelTwoUpgrade upgrade(&basePlant);

    //     upgrade.update();
    //     CHECK(upgrade.getOutput() == 800);
    // }

    // TEST_CASE("SewageSystemLevelTwoUpgrade clone()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelTwoUpgrade upgrade(&basePlant);

    //     Entity* clonedUpgrade = upgrade.clone();
    //     SewageSystemLevelTwoUpgrade* cloned = dynamic_cast<SewageSystemLevelTwoUpgrade*>(clonedUpgrade);
        
    //     REQUIRE(cloned != nullptr);
    //     CHECK(cloned->getOutput() == 700);

    //     delete clonedUpgrade;
    // }

    // TEST_CASE("SewageSystemLevelTwoUpgrade getOutput()") {
    //     SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    //     SewageSystemLevelTwoUpgrade upgrade(&basePlant);

    //     CHECK(upgrade.getOutput() == 1200);
    // }
}