#include "doctest.h"
#include "entities/building/service/School.h"
#include "utils/ConfigManager.h"

TEST_SUITE("School Tests") {
    TEST_CASE("Constructor Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 0, 0);
        CHECK(school.getXPosition() == 0);
        CHECK(school.getYPosition() == 0);
        CHECK(school.getWidth() == 4);
        CHECK(school.getHeight() == 4);
        CHECK(school.getRevenue() == 2500);
        CHECK(school.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::MEDIUM), Size::MEDIUM, 0, 0);
        school.setXPosition(10);
        school.setYPosition(15);
        CHECK(school.getXPosition() == 10);
        CHECK(school.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 0, 0);
        School copiedSchool(&school);
        CHECK(copiedSchool.getXPosition() == school.getXPosition());
        CHECK(copiedSchool.getYPosition() == school.getYPosition());
        CHECK(copiedSchool.getWidth() == school.getWidth());
        CHECK(copiedSchool.getHeight() == school.getHeight());
        CHECK(copiedSchool.getRevenue() == school.getRevenue());
        CHECK(copiedSchool.isBuilt() == school.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 0, 0);
        School* clonedSchool = static_cast<School*>(school.clone());
        REQUIRE(clonedSchool != nullptr);
        CHECK(clonedSchool->getXPosition() == school.getXPosition());
        CHECK(clonedSchool->getYPosition() == school.getYPosition());
        CHECK(clonedSchool->getWidth() == school.getWidth());
        CHECK(clonedSchool->getHeight() == school.getHeight());
        CHECK(clonedSchool->getRevenue() == school.getRevenue());
        CHECK(clonedSchool->isBuilt() == school.isBuilt());
        delete clonedSchool;
    }

    TEST_CASE("Update Method Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(school.isBuilt() == false);

        // This simulates the game looping
        while (!school.isBuilt()) {
            school.update();
        }
        
        CHECK(school.isBuilt() == true);
    }

    TEST_CASE("Revenue Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(school.getRevenue() == 7500);
    }

    TEST_CASE("Dimensions Test") {
        School school(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 0, 0);
        CHECK(school.getWidth() == 8);
        CHECK(school.getHeight() == 8);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        School baseSchool(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 0, 0);
        
        SUBCASE("School within radius") {
            School nearbySchool(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 15, 15);
            CHECK(baseSchool.isWithinEffectRadius(&nearbySchool) == true);
        }

        SUBCASE("School outside radius") {
            School farSchool(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 50, 50);
            CHECK(baseSchool.isWithinEffectRadius(&farSchool) == false);
        }

        SUBCASE("School exactly on border") {
            School borderSchool(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 23, 23);
            CHECK(baseSchool.isWithinEffectRadius(&borderSchool) == false);
        }

        SUBCASE("School partially overlaps with radius") {
            School partialOverlapSchool(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::LARGE), Size::LARGE, 22, 22);
            CHECK(baseSchool.isWithinEffectRadius(&partialOverlapSchool) == true);
        }
    }
}