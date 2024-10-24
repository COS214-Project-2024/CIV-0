#include "doctest.h"
#include "entities/building/economic/Factory.h"
#include "utils/ConfigManager.h"

TEST_SUITE("Factory Tests") {
    TEST_CASE("Constructor Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(factory.getXPosition() == 0);
        CHECK(factory.getYPosition() == 0);
        CHECK(factory.getWidth() == 4);
        CHECK(factory.getHeight() == 4);
        CHECK(factory.getRevenue() == 3000);
        CHECK(factory.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::MEDIUM), Size::MEDIUM, 0, 0);
        factory.setXPosition(10);
        factory.setYPosition(15);
        CHECK(factory.getXPosition() == 10);
        CHECK(factory.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 0, 0);
        Factory copiedFactory(&factory);
        CHECK(copiedFactory.getXPosition() == factory.getXPosition());
        CHECK(copiedFactory.getYPosition() == factory.getYPosition());
        CHECK(copiedFactory.getWidth() == factory.getWidth());
        CHECK(copiedFactory.getHeight() == factory.getHeight());
        CHECK(copiedFactory.getRevenue() == factory.getRevenue());
        CHECK(copiedFactory.isBuilt() == factory.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 0, 0);
        Factory* clonedFactory = static_cast<Factory*>(factory.clone());
        REQUIRE(clonedFactory != nullptr);
        CHECK(clonedFactory->getXPosition() == factory.getXPosition());
        CHECK(clonedFactory->getYPosition() == factory.getYPosition());
        CHECK(clonedFactory->getWidth() == factory.getWidth());
        CHECK(clonedFactory->getHeight() == factory.getHeight());
        CHECK(clonedFactory->getRevenue() == factory.getRevenue());
        CHECK(clonedFactory->isBuilt() == factory.isBuilt());
        delete clonedFactory;
    }

    TEST_CASE("Update Method Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(factory.isBuilt() == false);

        // This simulates the game looping
        while (!factory.isBuilt()) {
            factory.update();
        }
        
        CHECK(factory.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(factory.getRevenue() == 10000);
    }

    TEST_CASE("Dimensions Test") {
        Factory factory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(factory.getWidth() == 8);
        CHECK(factory.getHeight() == 8);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        Factory baseFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("Factory within radius") {
            Factory nearbyFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 10, 10);
            CHECK(baseFactory.isWithinEffectRadius(&nearbyFactory) == true);
        }

        SUBCASE("Factory outside radius") {
            Factory farFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseFactory.isWithinEffectRadius(&farFactory) == false);
        }

        SUBCASE("Factory exactly on border") {
            Factory borderFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 28, 28);
            CHECK(baseFactory.isWithinEffectRadius(&borderFactory) == false);
        }

        SUBCASE("Factory partially overlaps with radius") {
            Factory partialOverlapFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, Size::LARGE), Size::LARGE, 27, 27);
            CHECK(baseFactory.isWithinEffectRadius(&partialOverlapFactory) == true);
        }
    }
}