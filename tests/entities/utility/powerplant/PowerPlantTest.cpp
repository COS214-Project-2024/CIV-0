#include "doctest.h"
#include "entities/utility/powerplant/PowerPlant.h"

TEST_CASE("PowerPlantTest test") {
    // Test constructor with parameters
    PowerPlant powerPlant(100, 50, "P", 10, 5, 15, 5, 5, 1000, Size::LARGE, 0, 0, 1);

    CHECK(powerPlant.getXPosition() == 0);
    CHECK(powerPlant.getYPosition() == 0);
    powerPlant.setXPosition(10);
    powerPlant.setYPosition(15);
    CHECK(powerPlant.getXPosition() == 10);
    CHECK(powerPlant.getYPosition() == 15);

    CHECK(powerPlant.getWidth() == 5);
    CHECK(powerPlant.getHeight() == 5);
    CHECK(powerPlant.getRevenue() == 1000);
    CHECK(powerPlant.getOutput() == 20);

    CHECK(powerPlant.isBuilt() == false);

    // Test copy constructor
    PowerPlant* copiedPowerPlant = new PowerPlant(powerPlant);
    CHECK(copiedPowerPlant != nullptr);
    CHECK(copiedPowerPlant->getXPosition() == powerPlant.getXPosition());
    CHECK(copiedPowerPlant->getYPosition() == powerPlant.getYPosition());
    CHECK(copiedPowerPlant->getWidth() == powerPlant.getWidth());
    CHECK(copiedPowerPlant->getHeight() == powerPlant.getHeight());
    CHECK(copiedPowerPlant->getRevenue() == powerPlant.getRevenue());
    CHECK(copiedPowerPlant->getOutput() == powerPlant.getOutput());
    CHECK(copiedPowerPlant->isBuilt() == false);

    delete copiedPowerPlant;

    // Test clone method
    PowerPlant* clonedPowerPlant = static_cast<PowerPlant*>(powerPlant.clone());
    CHECK(clonedPowerPlant != nullptr);
    CHECK(clonedPowerPlant->getXPosition() == powerPlant.getXPosition());
    CHECK(clonedPowerPlant->getYPosition() == powerPlant.getYPosition());
    CHECK(clonedPowerPlant->getWidth() == powerPlant.getWidth());
    CHECK(clonedPowerPlant->getHeight() == powerPlant.getHeight());
    CHECK(clonedPowerPlant->getRevenue() == powerPlant.getRevenue());
    CHECK(clonedPowerPlant->getOutput() == powerPlant.getOutput());
    CHECK(clonedPowerPlant->isBuilt() == false);

    delete clonedPowerPlant;

    // Test update method
    powerPlant.update();
    CHECK(powerPlant.isBuilt() == true);

    // Test setters
    powerPlant.setOutput(150);
    CHECK(powerPlant.getOutput() == 150);
}
