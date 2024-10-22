#include "doctest.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

TEST_SUITE("SewageSystem Tests") {
    TEST_CASE("Constructor Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(sewageSystem.getXPosition() == 0);
        CHECK(sewageSystem.getYPosition() == 0);
        CHECK(sewageSystem.getWidth() == 5);
        CHECK(sewageSystem.getHeight() == 5);
        CHECK(sewageSystem.getRevenue() == 1000);
        CHECK(sewageSystem.getOutput() == 20);
        CHECK(sewageSystem.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        sewageSystem.setXPosition(10);
        sewageSystem.setYPosition(15);
        CHECK(sewageSystem.getXPosition() == 10);
        CHECK(sewageSystem.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        SewageSystem copiedSewageSystem(&sewageSystem);
        CHECK(copiedSewageSystem.getXPosition() == sewageSystem.getXPosition());
        CHECK(copiedSewageSystem.getYPosition() == sewageSystem.getYPosition());
        CHECK(copiedSewageSystem.getWidth() == sewageSystem.getWidth());
        CHECK(copiedSewageSystem.getHeight() == sewageSystem.getHeight());
        CHECK(copiedSewageSystem.getRevenue() == sewageSystem.getRevenue());
        CHECK(copiedSewageSystem.getOutput() == sewageSystem.getOutput());
        CHECK(copiedSewageSystem.isBuilt() == sewageSystem.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        SewageSystem* clonedSewageSystem = static_cast<SewageSystem*>(sewageSystem.clone());
        REQUIRE(clonedSewageSystem != nullptr);
        CHECK(clonedSewageSystem->getXPosition() == sewageSystem.getXPosition());
        CHECK(clonedSewageSystem->getYPosition() == sewageSystem.getYPosition());
        CHECK(clonedSewageSystem->getWidth() == sewageSystem.getWidth());
        CHECK(clonedSewageSystem->getHeight() == sewageSystem.getHeight());
        CHECK(clonedSewageSystem->getRevenue() == sewageSystem.getRevenue());
        CHECK(clonedSewageSystem->getOutput() == sewageSystem.getOutput());
        CHECK(clonedSewageSystem->isBuilt() == sewageSystem.isBuilt());
        delete clonedSewageSystem;
    }

    TEST_CASE("Update Method Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(sewageSystem.isBuilt() == false);
        sewageSystem.update();
        CHECK(sewageSystem.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        sewageSystem.setOutput(150);
        CHECK(sewageSystem.getOutput() == 150);
    }

    TEST_CASE("Capacity Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(sewageSystem.getRevenue() == 1000);
    }

    TEST_CASE("Dimensions Test") {
        SewageSystem sewageSystem(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(sewageSystem.getWidth() == 5);
        CHECK(sewageSystem.getHeight() == 5);
    }

    TEST_CASE("isWithinEffectRadius Test") {
        SewageSystem baseSewageSystem(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        
        SUBCASE("SewageSystem within radius") {
            SewageSystem nearbySewageSystem(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 5, 5, 1);
            CHECK(baseSewageSystem.isWithinEffectRadius(&nearbySewageSystem) == true);
        }

        SUBCASE("SewageSystem outside radius") {
            SewageSystem farSewageSystem(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 50, 50, 1);
            CHECK(baseSewageSystem.isWithinEffectRadius(&farSewageSystem) == false);
        }

        SUBCASE("SewageSystem exactly on border") {
            SewageSystem borderSewageSystem(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 15, 15, 1);
            CHECK(baseSewageSystem.isWithinEffectRadius(&borderSewageSystem) == false);
        }

        SUBCASE("SewageSystem partially overlaps with radius") {
            SewageSystem partialOverlapSewageSystem(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 9, 9, 1);
            CHECK(baseSewageSystem.isWithinEffectRadius(&partialOverlapSewageSystem) == true);
        }
    }
}