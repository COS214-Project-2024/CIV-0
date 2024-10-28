#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystemLevelTwoUpgrade.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "utils/ConfigManager.h"

TEST_SUITE("SewageSystemLevelTwoUpgrade Tests") {
    TEST_CASE("SewageSystemLevelTwoUpgrade constructor") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 4);
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade update()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::MEDIUM), Size::MEDIUM, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        upgrade.update();
        CHECK(upgrade.getOutput() == 20 * 4);
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade clone()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::LARGE), Size::LARGE, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        Entity* clonedUpgrade = upgrade.clone();
        SewageSystemLevelTwoUpgrade* cloned = dynamic_cast<SewageSystemLevelTwoUpgrade*>(clonedUpgrade);
        
        REQUIRE(cloned != nullptr);
        CHECK(cloned->getOutput() == 20 * 4);

        delete clonedUpgrade;
    }

    TEST_CASE("SewageSystemLevelTwoUpgrade getOutput()") {
        SewageSystem basePlant(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
        SewageSystemLevelTwoUpgrade upgrade(&basePlant);

        CHECK(upgrade.getOutput() == 20 * 4);
    }
}
