#include "doctest.h"
#include "entities/road/Road.h" 

// Mock EntityConfig and Size classes if not available
class EntityConfig {
public:
    int electricityConsumption;
    int waterConsumption;
    std::string symbol;
    int effectRadius;
    int localEffectStrength;
    int globalEffectStrength;
    int revenue;
    
    EntityConfig(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int revenue)
        : electricityConsumption(electricity), waterConsumption(water), symbol(symbol),
          effectRadius(radius), localEffectStrength(localEffect), globalEffectStrength(globalEffect), revenue(revenue) {}
};

class Size {
public:
    int width, height;
    Size(int w, int h) : width(w), height(h) {}
};

/**
 * @brief Test the constructor of the Road class.
 * 
 * This test verifies that the Road constructor initializes the object
 * with the expected attributes, including position, size, and revenue.
 */
TEST_CASE("Test Road Constructor") {
    EntityConfig ec(50, 30, "R", 10, 5, 3, 100);
    Size size(5, 5);
    Road road(ec, size, 0, 0);

    CHECK(road.getXPosition() == 0);
    CHECK(road.getYPosition() == 0);
    CHECK(road.getRevenue() == ec.revenue);
    CHECK(road.getWidth() == size.width);
    CHECK(road.getHeight() == size.height);
}

/**
 * @brief Test the update function of the Road class.
 * 
 * This test ensures that calling update on the Road object does not change
 * any of its attributes, as the update method is defined as a no-op.
 */
TEST_CASE("Test Road Update Function") {
    EntityConfig ec(50, 30, "R", 10, 5, 3, 100);
    Size size(5, 5);
    Road road(ec, size, 0, 0);

    road.update(); // Call update, which should have no effect
    CHECK(road.getRevenue() == ec.revenue); // Ensure revenue remains the same
}

/**
 * @brief Test the cloning function of the Road class.
 * 
 * This test verifies that the clone method creates a new Road object
 * with identical attributes but a separate memory address.
 */
TEST_CASE("Test Road Cloning") {
    EntityConfig ec(50, 30, "R", 10, 5, 3, 100);
    Size size(5, 5);
    Road road(ec, size, 0, 0);

    Entity* clonedRoad = road.clone();

    // Verify that the cloned object is not null and has identical attributes
    CHECK(clonedRoad != nullptr);
    CHECK(clonedRoad->getXPosition() == road.getXPosition());
    CHECK(clonedRoad->getYPosition() == road.getYPosition());
    CHECK(clonedRoad->getWidth() == road.getWidth());
    CHECK(clonedRoad->getHeight() == road.getHeight());
    CHECK(clonedRoad->getRevenue() == road.getRevenue());

    delete clonedRoad; // Clean up cloned object
}