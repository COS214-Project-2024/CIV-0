#include "doctest.h"
#include "visitors/population/PopulationVisitor.h"
#include "city/City.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"
#include "utils/ConfigManager.h"
#include <unordered_set>

TEST_CASE("PopulationVisitorTest - Collect population capacity from unique residential buildings")
{
    // Create a city instance
    City *city = City::instance();

    // Use ConfigManager to get configurations for different building types
    EntityConfig smallHouseConfig = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL);
    EntityConfig largeHouseConfig = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::LARGE);
    EntityConfig smallApartmentConfig = ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::SMALL);
    EntityConfig largeApartmentConfig = ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::LARGE);

    city->addEntity(new House(smallHouseConfig, Size::SMALL, 5, 5));
    city->addEntity(new Apartment(largeApartmentConfig, Size::LARGE, 10, 10));
    city->addEntity(new House(largeHouseConfig, Size::LARGE, 10, 20));
    city->addEntity(new Apartment(smallApartmentConfig, Size::SMALL, 30, 30));

    // Create a PopulationVisitor instance
    PopulationVisitor populationVisitor;

    // Let the visitor visit the city
    city->accept(populationVisitor);

    // Calculate expected total population capacities using a set to avoid duplicates
    int expectedTotalCapacity = 0;
    int expectedHouseCapacity = 0;
    int expectedApartmentCapacity = 0;
    std::unordered_set<Entity*> uniqueEntities;

    for (auto &row : city->getGrid())
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr && uniqueEntities.insert(entity).second)
            {
                ResidentialBuilding *residential = dynamic_cast<ResidentialBuilding *>(entity);
                if (residential)
                {
                    int capacity = residential->getCapacity();
                    expectedTotalCapacity += capacity;

                    if (dynamic_cast<House *>(residential))
                    {
                        expectedHouseCapacity += capacity;
                    }
                    else if (dynamic_cast<Apartment *>(residential))
                    {
                        expectedApartmentCapacity += capacity;
                    }
                }
            }
        }
    }

    // Check the totals collected by the PopulationVisitor
    CHECK(populationVisitor.getTotalPopulationCapacity() == expectedTotalCapacity);
    CHECK(populationVisitor.getHousePopulationCapacity() == expectedHouseCapacity);
    CHECK(populationVisitor.getApartmentPopulationCapacity() == expectedApartmentCapacity);

    city->reset();
}

TEST_CASE("PopulationVisitorTest - Empty grid produces no population capacity")
{
    // Create an empty city instance
    City *city = City::instance();

    // Create a PopulationVisitor instance
    PopulationVisitor populationVisitor;

    // Let the visitor visit the empty city
    city->accept(populationVisitor);

    // Check that no population capacity was collected
    CHECK(populationVisitor.getTotalPopulationCapacity() == 0);
    CHECK(populationVisitor.getHousePopulationCapacity() == 0);
    CHECK(populationVisitor.getApartmentPopulationCapacity() == 0);

    city->reset();
}
