#include "doctest.h"
#include "visitors/satisfaction/SatisfactionVisitor.h"
#include "city/City.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"
#include "utils/ConfigManager.h"
#include <unordered_set>

TEST_CASE("SatisfactionVisitorTest - Collect satisfaction from unique residential buildings")
{
    // Create a city instance
    City *city = City::instance();

    // Use ConfigManager to get configurations for different building types
    EntityConfig smallHouseConfig = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL);
    EntityConfig mediumHouseConfig = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::MEDIUM);
    EntityConfig largeHouseConfig = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::LARGE);

    EntityConfig smallApartmentConfig = ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::SMALL);
    EntityConfig mediumApartmentConfig = ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::MEDIUM);
    EntityConfig largeApartmentConfig = ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::LARGE);

    city->addEntity(new House(smallHouseConfig, Size::SMALL, 0, 10));
    city->addEntity(new Apartment(largeApartmentConfig, Size::LARGE, 10, 11));
    city->addEntity(new House(mediumHouseConfig, Size::MEDIUM, 20, 22));
    city->addEntity(new Apartment(mediumApartmentConfig, Size::MEDIUM, 31, 30));
    city->addEntity(new House(largeHouseConfig, Size::LARGE, 41, 41));
    city->addEntity(new Apartment(smallApartmentConfig, Size::SMALL, 1, 32));
    city->addEntity(new House(smallHouseConfig, Size::SMALL, 2, 20));
    city->addEntity(new Apartment(mediumApartmentConfig, Size::MEDIUM, 2, 11));
    city->addEntity(new House(largeHouseConfig, Size::LARGE, 22, 42));

    // Create a SatisfactionVisitor instance
    SatisfactionVisitor satisfactionVisitor;

    // Let the visitor visit the city
    city->accept(satisfactionVisitor);

    // Calculate expected average satisfaction using a set to avoid duplicates
    float expectedSatisfaction = 0;
    int residentialCount = 0;
    std::unordered_set<Entity*> uniqueEntities;

    // Iterate over the grid to calculate expected satisfaction from unique entities
    for (auto &row : city->getGrid())
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr && uniqueEntities.insert(entity).second)
            {
                ResidentialBuilding *residential = dynamic_cast<ResidentialBuilding *>(entity);
                if (residential)
                {
                    residential->calculateSatisfaction();
                    expectedSatisfaction += residential->getSatisfaction();
                    residentialCount++;
                }
            }
        }
    }

    float expectedAverageSatisfaction = residentialCount > 0 ? expectedSatisfaction / residentialCount : 0;

    // Check the average satisfaction collected by the SatisfactionVisitor
    CHECK(satisfactionVisitor.getAverageSatisfaction() == doctest::Approx(expectedAverageSatisfaction));
    CHECK(satisfactionVisitor.getResidentialCount() == residentialCount);

    city->reset();
}

TEST_CASE("SatisfactionVisitorTest - Empty grid produces no satisfaction")
{
    // Create an empty city instance
    City *city = City::instance();

    // Create a SatisfactionVisitor instance
    SatisfactionVisitor satisfactionVisitor;

    // Let the visitor visit the empty city
    city->accept(satisfactionVisitor);

    // Check that no satisfaction was collected
    CHECK(satisfactionVisitor.getAverageSatisfaction() == 0);
    CHECK(satisfactionVisitor.getResidentialCount() == 0);

    city->reset();
}
