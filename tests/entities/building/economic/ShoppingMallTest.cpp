#include "doctest.h"
#include "entities/building/economic/ShoppingMall.h"
#include "utils/ConfigManager.h"

TEST_SUITE("ShoppingMall Tests") {
    TEST_CASE("Constructor Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(mall.getXPosition() == 0);
        CHECK(mall.getYPosition() == 0);
        CHECK(mall.getWidth() == 5);
        CHECK(mall.getHeight() == 5);
        CHECK(mall.getRevenue() == 8000);
        CHECK(mall.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::MEDIUM), Size::MEDIUM, 0, 0);
        mall.setXPosition(10);
        mall.setYPosition(15);
        CHECK(mall.getXPosition() == 10);
        CHECK(mall.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 0, 0);
        ShoppingMall copiedShoppingMall(&mall);
        CHECK(copiedShoppingMall.getXPosition() == mall.getXPosition());
        CHECK(copiedShoppingMall.getYPosition() == mall.getYPosition());
        CHECK(copiedShoppingMall.getWidth() == mall.getWidth());
        CHECK(copiedShoppingMall.getHeight() == mall.getHeight());
        CHECK(copiedShoppingMall.getRevenue() == mall.getRevenue());
        CHECK(copiedShoppingMall.isBuilt() == mall.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 0, 0);
        ShoppingMall* clonedShoppingMall = static_cast<ShoppingMall*>(mall.clone());
        REQUIRE(clonedShoppingMall != nullptr);
        CHECK(clonedShoppingMall->getXPosition() == mall.getXPosition());
        CHECK(clonedShoppingMall->getYPosition() == mall.getYPosition());
        CHECK(clonedShoppingMall->getWidth() == mall.getWidth());
        CHECK(clonedShoppingMall->getHeight() == mall.getHeight());
        CHECK(clonedShoppingMall->getRevenue() == mall.getRevenue());
        CHECK(clonedShoppingMall->isBuilt() == mall.isBuilt());
        delete clonedShoppingMall;
    }

    TEST_CASE("Update Method Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(mall.isBuilt() == false);

        // This simulates the game looping
        while (!mall.isBuilt()) {
            mall.update();
        }
        
        CHECK(mall.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(mall.getRevenue() == 30000);
    }

    TEST_CASE("Dimensions Test") {
        ShoppingMall mall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(mall.getWidth() == 10);
        CHECK(mall.getHeight() == 10);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        ShoppingMall baseShoppingMall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("ShoppingMall within radius") {
            ShoppingMall nearbyShoppingMall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 15, 15);
            CHECK(baseShoppingMall.isWithinEffectRadius(&nearbyShoppingMall) == true);
        }

        SUBCASE("ShoppingMall outside radius") {
            ShoppingMall farShoppingMall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseShoppingMall.isWithinEffectRadius(&farShoppingMall) == false);
        }

        SUBCASE("ShoppingMall exactly on border") {
            ShoppingMall borderShoppingMall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 25, 25);
            CHECK(baseShoppingMall.isWithinEffectRadius(&borderShoppingMall) == false);
        }

        SUBCASE("ShoppingMall partially overlaps with radius") {
            ShoppingMall partialOverlapShoppingMall(ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE), Size::LARGE, 24, 24);
            CHECK(baseShoppingMall.isWithinEffectRadius(&partialOverlapShoppingMall) == true);
        }
    }
}
