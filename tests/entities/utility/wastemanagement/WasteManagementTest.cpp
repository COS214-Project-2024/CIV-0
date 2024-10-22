#include "doctest.h"
#include "entities/utility/wastemanagement/WasteManagement.h"

TEST_SUITE("WasteManagement Tests") {
    TEST_CASE("Constructor Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(wasteManagement.getXPosition() == 0);
        CHECK(wasteManagement.getYPosition() == 0);
        CHECK(wasteManagement.getWidth() == 5);
        CHECK(wasteManagement.getHeight() == 5);
        CHECK(wasteManagement.getRevenue() == 1000);
        CHECK(wasteManagement.getOutput() == 20);
        CHECK(wasteManagement.isBuilt() == false);
    }

    TEST_CASE("Set Position Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        wasteManagement.setXPosition(10);
        wasteManagement.setYPosition(15);
        CHECK(wasteManagement.getXPosition() == 10);
        CHECK(wasteManagement.getYPosition() == 15);
    }

    TEST_CASE("Copy Constructor Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        WasteManagement copiedWasteManagement(&wasteManagement);
        CHECK(copiedWasteManagement.getXPosition() == wasteManagement.getXPosition());
        CHECK(copiedWasteManagement.getYPosition() == wasteManagement.getYPosition());
        CHECK(copiedWasteManagement.getWidth() == wasteManagement.getWidth());
        CHECK(copiedWasteManagement.getHeight() == wasteManagement.getHeight());
        CHECK(copiedWasteManagement.getRevenue() == wasteManagement.getRevenue());
        CHECK(copiedWasteManagement.getOutput() == wasteManagement.getOutput());
        CHECK(copiedWasteManagement.isBuilt() == wasteManagement.isBuilt());
    }

    TEST_CASE("Clone Method Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        WasteManagement* clonedWasteManagement = static_cast<WasteManagement*>(wasteManagement.clone());
        REQUIRE(clonedWasteManagement != nullptr);
        CHECK(clonedWasteManagement->getXPosition() == wasteManagement.getXPosition());
        CHECK(clonedWasteManagement->getYPosition() == wasteManagement.getYPosition());
        CHECK(clonedWasteManagement->getWidth() == wasteManagement.getWidth());
        CHECK(clonedWasteManagement->getHeight() == wasteManagement.getHeight());
        CHECK(clonedWasteManagement->getRevenue() == wasteManagement.getRevenue());
        CHECK(clonedWasteManagement->getOutput() == wasteManagement.getOutput());
        CHECK(clonedWasteManagement->isBuilt() == wasteManagement.isBuilt());
        delete clonedWasteManagement;
    }

    TEST_CASE("Update Method Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(wasteManagement.isBuilt() == false);
        wasteManagement.update();
        CHECK(wasteManagement.isBuilt() == true);
    }

    TEST_CASE("Set Output Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        wasteManagement.setOutput(150);
        CHECK(wasteManagement.getOutput() == 150);
    }

    TEST_CASE("Capacity Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(wasteManagement.getRevenue() == 1000);
    }

    TEST_CASE("Dimensions Test") {
        WasteManagement wasteManagement(100, 50, "S", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);
        CHECK(wasteManagement.getWidth() == 5);
        CHECK(wasteManagement.getHeight() == 5);
    }
}