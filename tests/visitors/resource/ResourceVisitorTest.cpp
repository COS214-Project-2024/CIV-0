#include "doctest.h"
#include "visitors/resource/ResourceVisitor.h"
#include "city/City.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"

TEST_CASE("ResourceVisitorTest - Collect resources from entities")
{
    // Create a city instance
    City *city = City::instance();

    // Mocking the city grid with different resource-producing entities
    std::vector<std::vector<Entity *>> mockGrid = {
        {new WoodProducer(EntityConfig(), Size::SMALL, 0, 0), nullptr, new ConcreteProducer(EntityConfig(), Size::MEDIUM, 0, 1)},
        {nullptr, new StoneProducer(EntityConfig(), Size::LARGE, 1, 0), nullptr},
        {new WoodProducer(EntityConfig(), Size::LARGE, 2, 0), new StoneProducer(EntityConfig(), Size::SMALL, 2, 1), nullptr}};

    // Assign this mock grid to the city
    city->getGrid() = mockGrid;

    // Create a ResourceVisitor instance
    ResourceVisitor resourceVisitor;

    // Let the visitor visit the city
    city->accept(resourceVisitor);

    // Check the totals collected by the ResourceVisitor
    // Each resource producer produces 20 units
    CHECK(resourceVisitor.getTotalWood() == 40);     // 2 wood producers * 20
    CHECK(resourceVisitor.getTotalConcrete() == 20); // 1 concrete producer * 20
    CHECK(resourceVisitor.getTotalStone() == 40);    // 2 stone producers * 20

    // Clean up the dynamically allocated entities
    for (auto &row : mockGrid)
    {
        for (Entity *entity : row)
        {
            delete entity; // Free each entity
        }
    }
}

TEST_CASE("ResourceVisitorTest - Empty grid produces no resources")
{
    // Create a city instance
    City *city = City::instance();

    // Create an empty city grid (all nullptrs)
    std::vector<std::vector<Entity *>> emptyGrid(3, std::vector<Entity *>(3, nullptr));

    // Assign the empty grid to the city
    city->getGrid() = emptyGrid;

    // Create a ResourceVisitor instance
    ResourceVisitor resourceVisitor;

    // Let the visitor visit the empty city
    city->accept(resourceVisitor);

    // Check that no resources were collected
    CHECK(resourceVisitor.getTotalWood() == 0);
    CHECK(resourceVisitor.getTotalConcrete() == 0);
    CHECK(resourceVisitor.getTotalStone() == 0);
}

TEST_CASE("ResourceVisitorTest - Single resource producer in grid")
{
    // Create a city instance
    City *city = City::instance();

    // Mocking the city grid with one wood producer
    std::vector<std::vector<Entity *>> mockGrid = {
        {nullptr, nullptr, nullptr},
        {nullptr, new WoodProducer(EntityConfig(), Size::MEDIUM, 1, 1), nullptr},
        {nullptr, nullptr, nullptr}};

    // Assign the grid to the city
    city->getGrid() = mockGrid;

    // Create a ResourceVisitor instance
    ResourceVisitor resourceVisitor;

    // Let the visitor visit the city
    city->accept(resourceVisitor);

    // Check the totals collected by the ResourceVisitor
    CHECK(resourceVisitor.getTotalWood() == 20);    // 1 wood producer * 20
    CHECK(resourceVisitor.getTotalConcrete() == 0); // No concrete producer
    CHECK(resourceVisitor.getTotalStone() == 0);    // No stone producer

    // Clean up the dynamically allocated entities
    for (auto &row : mockGrid)
    {
        for (Entity *entity : row)
        {
            delete entity; // Free each entity
        }
    }
}
