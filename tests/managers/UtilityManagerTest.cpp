#include "doctest.h"
#include "managers/UtilityManager.h"
#include "city/City.h"
#include "utils/EntityType.h"
#include "utils/Size.h"
#include <vector>

TEST_SUITE("UtilityManager") {
    void resetCity() {
        City::instance()->reset();
    }

    TEST_CASE("UtilityManager can build different utility types") {
        resetCity();
        UtilityManager manager;

        SUBCASE("Build a small PowerPlant") {
            manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 10, 10);
            std::vector<Utility*> utilities = manager.getAllPowerPlants();
            CHECK(utilities.size() == 1);
            //CHECK(City::instance()->getElectricityProduction() == 20);
        }

        SUBCASE("Build a small SewageSystem facility") {
            manager.buildUtility(EntityType::SEWAGESYSTEM, Size::SMALL, 40, 10);
            std::vector<Utility*> utilities = manager.getAllSewageSystems();
            CHECK(utilities.size() == 1);
            //CHECK(City::instance()->getSewageConsumption() == 20);
        }

        SUBCASE("Build a medium WasteManagement facility") {
            manager.buildUtility(EntityType::WASTEMANAGEMENT, Size::MEDIUM, 10, 30);
            std::vector<Utility*> utilities = manager.getAllWasteManagements();
            CHECK(utilities.size() == 1);
            //CHECK(City::instance()->getWasteConsumption() == 20);
        }

        SUBCASE("Build a large WaterSupply") {
            manager.buildUtility(EntityType::WATERSUPPLY, Size::LARGE, 20, 30);
            std::vector<Utility*> utilities = manager.getAllWaterSupplies();
            CHECK(utilities.size() == 1);
            //CHECK(City::instance()->getWaterProduction() == 20);
        }

        SUBCASE("Building an invalid utility type does not add to the city") {
            manager.buildUtility(EntityType::BUSSTOP, Size::SMALL, 20, 20);
            std::vector<Utility*> utilities = manager.getAllUtilities();
            CHECK(utilities.empty());
        }

        SUBCASE("All together") {
            manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 10, 10);
            manager.buildUtility(EntityType::SEWAGESYSTEM, Size::SMALL, 40, 10);
            manager.buildUtility(EntityType::WASTEMANAGEMENT, Size::MEDIUM, 10, 30);
            manager.buildUtility(EntityType::WATERSUPPLY, Size::LARGE, 20, 30);
            manager.buildUtility(EntityType::BUSSTOP, Size::SMALL, 20, 20);
            std::vector<Utility*> utilities = manager.getAllUtilities();
            CHECK(utilities.size() == 4);
        }
    }

    TEST_CASE("UtilityManager calculates production and consumption correctly") {
        resetCity();
        UtilityManager manager;

        manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 20, 20);
        manager.buildUtility(EntityType::WATERSUPPLY, Size::SMALL, 40, 40);
        manager.buildUtility(EntityType::WASTEMANAGEMENT, Size::SMALL, 0, 30);
        manager.buildUtility(EntityType::SEWAGESYSTEM, Size::SMALL, 20, 40);

        manager.getElectricityProduction();
        manager.getWaterProduction();
        manager.getWasteProduction();
        manager.getSewageProduction();

        manager.getElectricityConsumption();
        manager.getWaterConsumption();
        manager.getWasteConsumption();
        manager.getSewageConsumption();

        CHECK(manager.getElectricityProduction() == City::instance()->getElectricityProduction());
        CHECK(manager.getWaterProduction() == City::instance()->getWaterProduction());
        CHECK(manager.getWasteProduction() == City::instance()->getWasteProduction());
        CHECK(manager.getSewageProduction() == City::instance()->getSewageProduction());

        CHECK(manager.getElectricityConsumption() == City::instance()->getElectricityConsumption());
        CHECK(manager.getWaterConsumption() == City::instance()->getWaterConsumption());
        CHECK(manager.getWasteConsumption() == City::instance()->getWasteConsumption());
        CHECK(manager.getSewageConsumption() == City::instance()->getSewageConsumption());
        resetCity();
    }

    TEST_CASE("UtilityManager upgrades utilities if affordable") {
        resetCity();
        UtilityManager manager;

        SUBCASE("Power Plant - Affordable") {
            City::instance()->setMoney(4000);
            City::instance()->setWood(1200);
            City::instance()->setStone(800);
            City::instance()->setConcrete(500);
            manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 20, 20);

            Utility* powerPlant = manager.getAllPowerPlants().front();
            REQUIRE(powerPlant != nullptr);
            CHECK(manager.upgrade(powerPlant));
        }

        SUBCASE("Power Plant - Not Affordable") {
            City::instance()->setMoney(1000);
            City::instance()->setWood(200);
            City::instance()->setStone(100);
            City::instance()->setConcrete(50);
            manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 20, 20);

            Utility* powerPlant = manager.getAllPowerPlants().front();
            REQUIRE(powerPlant != nullptr);
            CHECK_FALSE(manager.upgrade(powerPlant));
        }

        SUBCASE("Water Supply - Affordable") {
            City::instance()->setMoney(2500);
            City::instance()->setWood(900);
            City::instance()->setStone(400);
            City::instance()->setConcrete(300);
            manager.buildUtility(EntityType::WATERSUPPLY, Size::SMALL, 20, 20);

            Utility* waterSupply = manager.getAllWaterSupplies().front();
            REQUIRE(waterSupply != nullptr);
            CHECK(manager.upgrade(waterSupply));
        }

        SUBCASE("Water Supply - Not Affordable") {
            City::instance()->setMoney(1000);
            City::instance()->setWood(500);
            City::instance()->setStone(200);
            City::instance()->setConcrete(100);
            manager.buildUtility(EntityType::WATERSUPPLY, Size::SMALL, 20, 20);

            Utility* waterSupply = manager.getAllWaterSupplies().front();
            REQUIRE(waterSupply != nullptr);
            CHECK_FALSE(manager.upgrade(waterSupply));
        }

        SUBCASE("Waste Management - Affordable") {
            City::instance()->setMoney(1200);
            City::instance()->setWood(600);
            City::instance()->setStone(300);
            City::instance()->setConcrete(200);
            manager.buildUtility(EntityType::WASTEMANAGEMENT, Size::SMALL, 20, 20);

            Utility* wasteManagement = manager.getAllWasteManagements().front();
            REQUIRE(wasteManagement != nullptr);
            CHECK(manager.upgrade(wasteManagement));
        }

        SUBCASE("Waste Management - Not Affordable") {
            City::instance()->setMoney(500);
            City::instance()->setWood(200);
            City::instance()->setStone(100);
            City::instance()->setConcrete(50);
            manager.buildUtility(EntityType::WASTEMANAGEMENT, Size::SMALL, 20, 20);

            Utility* wasteManagement = manager.getAllWasteManagements().front();
            REQUIRE(wasteManagement != nullptr);
            CHECK_FALSE(manager.upgrade(wasteManagement));
        }

        SUBCASE("Sewage System - Affordable") {
            City::instance()->setMoney(1500);
            City::instance()->setWood(800);
            City::instance()->setStone(400);
            City::instance()->setConcrete(300);
            manager.buildUtility(EntityType::SEWAGESYSTEM, Size::SMALL, 20, 20);
            
            Utility* sewageSystem = manager.getAllSewageSystems().front();
            REQUIRE(sewageSystem != nullptr);
            CHECK(manager.upgrade(sewageSystem));
        }

        SUBCASE("Sewage System - Not Affordable") {
            City::instance()->setMoney(800);
            City::instance()->setWood(300);
            City::instance()->setStone(100);
            City::instance()->setConcrete(50);
            manager.buildUtility(EntityType::SEWAGESYSTEM, Size::SMALL, 20, 20);

            Utility* sewageSystem = manager.getAllSewageSystems().front();
            REQUIRE(sewageSystem != nullptr);
            CHECK_FALSE(manager.upgrade(sewageSystem));
        }
    }

    TEST_CASE("Power Plant Upgrades") {
        resetCity();
        UtilityManager manager;

        City::instance()->setMoney(40000);
        City::instance()->setWood(12000);
        City::instance()->setStone(8000);
        City::instance()->setConcrete(5000);

        // Building multiple power plants
        manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 1, 6);
        manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 20, 20);
        manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 10, 10);

        Utility* powerPlant = manager.getAllPowerPlants().front();
        REQUIRE(powerPlant != nullptr);

        CHECK(manager.upgrade(powerPlant));         // Expecting this to return true
        CHECK(manager.upgrade(powerPlant));         // Expecting this to return true
        CHECK(manager.upgrade(powerPlant));         // Expecting this to return true
        CHECK_FALSE(manager.upgrade(powerPlant));   // Expecting this to return false
        CHECK_FALSE(manager.upgrade(powerPlant));   // Expecting this to return false
        resetCity();
    }

    TEST_CASE("Test upgrade cost subtraction") {
        resetCity();
        UtilityManager manager;
        EntityConfig ec = ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL);

        City::instance()->setMoney((ec.cost.moneyCost*2)*1.5);
        City::instance()->setWood((ec.cost.woodCost*2)*1.5);
        City::instance()->setStone((ec.cost.stoneCost*2)*1.5);
        City::instance()->setConcrete((ec.cost.concreteCost*2)*1.5);
        manager.buildUtility(EntityType::POWERPLANT, Size::SMALL, 20, 20);

        Utility* powerPlant = manager.getAllPowerPlants().front();
        REQUIRE(powerPlant != nullptr);
        CHECK(manager.upgrade(powerPlant)); // We can afford this upgrade

        CHECK(City::instance()->getMoney() == (ec.cost.moneyCost*2)*0.5);
        CHECK(City::instance()->getWood() == (ec.cost.woodCost*2)*0.5);
        CHECK(City::instance()->getStone() == (ec.cost.stoneCost*2)*0.5);
        CHECK(City::instance()->getConcrete() == (ec.cost.concreteCost*2)*0.5);

        REQUIRE(powerPlant != nullptr);
        CHECK_FALSE(manager.upgrade(powerPlant)); // We cant afford this upgrade
        resetCity();
    }
}