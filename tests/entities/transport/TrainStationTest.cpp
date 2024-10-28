#include "doctest.h"
#include "entities/transport/TrainStation.h"
#include "utils/ConfigManager.h"

TEST_SUITE("TrainStation Tests") {
    TEST_CASE("Constructor Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(trainstation.getXPosition() == 0);
        CHECK(trainstation.getYPosition() == 0);
        CHECK(trainstation.getWidth() == 1);
        CHECK(trainstation.getHeight() == 1);
        CHECK(trainstation.getRevenue() == 0);
        // CHECK(trainstation.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::MEDIUM), Size::MEDIUM, 0, 0);
        trainstation.setXPosition(10);
        trainstation.setYPosition(15);
        CHECK(trainstation.getXPosition() == 10);
        CHECK(trainstation.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
        TrainStation copiedTrainStation(&trainstation);
        CHECK(copiedTrainStation.getXPosition() == trainstation.getXPosition());
        CHECK(copiedTrainStation.getYPosition() == trainstation.getYPosition());
        CHECK(copiedTrainStation.getWidth() == trainstation.getWidth());
        CHECK(copiedTrainStation.getHeight() == trainstation.getHeight());
        CHECK(copiedTrainStation.getRevenue() == trainstation.getRevenue());
        CHECK(copiedTrainStation.isBuilt() == trainstation.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
        TrainStation* clonedTrainStation = static_cast<TrainStation*>(trainstation.clone());
        REQUIRE(clonedTrainStation != nullptr);
        CHECK(clonedTrainStation->getXPosition() == trainstation.getXPosition());
        CHECK(clonedTrainStation->getYPosition() == trainstation.getYPosition());
        CHECK(clonedTrainStation->getWidth() == trainstation.getWidth());
        CHECK(clonedTrainStation->getHeight() == trainstation.getHeight());
        CHECK(clonedTrainStation->getRevenue() == trainstation.getRevenue());
        CHECK(clonedTrainStation->isBuilt() == trainstation.isBuilt());
        delete clonedTrainStation;
    }

    TEST_CASE("Update Method Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
        // CHECK(trainstation.isBuilt() == false);

        // This simulates the game looping
        // while (!trainstation.isBuilt()) {
            trainstation.update();
        // }
        
        CHECK(trainstation.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(trainstation.getRevenue() == 0);
    }

    TEST_CASE("Dimensions Test") {
        TrainStation trainstation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(trainstation.getWidth() == 1);
        CHECK(trainstation.getHeight() == 1);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        TrainStation baseTrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("TrainStation within radius") {
            TrainStation nearbyTrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 0, 0);
            CHECK(baseTrainStation.isWithinEffectRadius(&nearbyTrainStation) == true);
        }

        SUBCASE("TrainStation outside radius") {
            TrainStation farTrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseTrainStation.isWithinEffectRadius(&farTrainStation) == false);
        }

        // SUBCASE("TrainStation exactly on border") {
        //     TrainStation borderTrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 42, 42);
        //     CHECK(baseTrainStation.isWithinEffectRadius(&borderTrainStation) == false);
        // }

        // SUBCASE("TrainStation partially overlaps with radius") {
        //     TrainStation partialOverlapTrainStation(ConfigManager::getEntityConfig(EntityType::TRAINSTATION, Size::LARGE), Size::LARGE, 41, 41);
        //     CHECK(baseTrainStation.isWithinEffectRadius(&partialOverlapTrainStation) == true);
        // }
    }
}
