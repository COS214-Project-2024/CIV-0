#include "doctest.h"
#include "entities/utility/watersupply/WaterSupply.h"

TEST_SUITE("WaterSupply Tests") {
    TEST_CASE("Constructor Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(waterSupply.getXPosition() == 0);
        CHECK(waterSupply.getYPosition() == 0);
        CHECK(waterSupply.getWidth() == 5);
        CHECK(waterSupply.getHeight() == 5);
        CHECK(waterSupply.getRevenue() == 1000);
        CHECK(waterSupply.getOutput() == 20);
        CHECK(waterSupply.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        waterSupply.setXPosition(10);
        waterSupply.setYPosition(15);
        CHECK(waterSupply.getXPosition() == 10);
        CHECK(waterSupply.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        WaterSupply copiedWaterSupply(&waterSupply);
        CHECK(copiedWaterSupply.getXPosition() == waterSupply.getXPosition());
        CHECK(copiedWaterSupply.getYPosition() == waterSupply.getYPosition());
        CHECK(copiedWaterSupply.getWidth() == waterSupply.getWidth());
        CHECK(copiedWaterSupply.getHeight() == waterSupply.getHeight());
        CHECK(copiedWaterSupply.getRevenue() == waterSupply.getRevenue());
        CHECK(copiedWaterSupply.getOutput() == waterSupply.getOutput());
        CHECK(copiedWaterSupply.isBuilt() == waterSupply.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        WaterSupply* clonedWaterSupply = static_cast<WaterSupply*>(waterSupply.clone());
        REQUIRE(clonedWaterSupply != nullptr);
        CHECK(clonedWaterSupply->getXPosition() == waterSupply.getXPosition());
        CHECK(clonedWaterSupply->getYPosition() == waterSupply.getYPosition());
        CHECK(clonedWaterSupply->getWidth() == waterSupply.getWidth());
        CHECK(clonedWaterSupply->getHeight() == waterSupply.getHeight());
        CHECK(clonedWaterSupply->getRevenue() == waterSupply.getRevenue());
        CHECK(clonedWaterSupply->getOutput() == waterSupply.getOutput());
        CHECK(clonedWaterSupply->isBuilt() == waterSupply.isBuilt());
        delete clonedWaterSupply;
    }

    TEST_CASE("Update Method Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(waterSupply.isBuilt() == false);
        waterSupply.update();
        CHECK(waterSupply.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        waterSupply.setOutput(150);
        CHECK(waterSupply.getOutput() == 150);
    }

    TEST_CASE("Capacity Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(waterSupply.getRevenue() == 1000);
    }

    TEST_CASE("Dimensions Test") {
        WaterSupply waterSupply(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(waterSupply.getWidth() == 5);
        CHECK(waterSupply.getHeight() == 5);
    }
}