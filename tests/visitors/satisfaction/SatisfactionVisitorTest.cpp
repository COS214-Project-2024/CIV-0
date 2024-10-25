#include "doctest.h"
#include "visitors/satisfaction/SatisfactionVisitor.h"
#include "city/City.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"
#include "utils/ConfigManager.h"

TEST_CASE("SatisfactionVisitorTest - Collect satisfaction from many residential buildings")
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

    city->addEntity(new House(smallHouseConfig, Size::SMALL, 0, 0));
    city->addEntity(new Apartment(largeApartmentConfig, Size::LARGE, 0, 1));
    city->addEntity(new House(mediumHouseConfig, Size::MEDIUM, 0, 2));
    city->addEntity(new Apartment(mediumApartmentConfig, Size::MEDIUM, 1, 0));
    city->addEntity(new House(largeHouseConfig, Size::LARGE, 1, 1));
    city->addEntity(new Apartment(smallApartmentConfig, Size::SMALL, 1, 2));
    city->addEntity(new House(smallHouseConfig, Size::SMALL, 2, 0));
    city->addEntity(new Apartment(mediumApartmentConfig, Size::MEDIUM, 2, 1));
    city->addEntity(new House(largeHouseConfig, Size::LARGE, 2, 2));

    // Create a SatisfactionVisitor instance
    SatisfactionVisitor satisfactionVisitor;

    // Let the visitor visit the city
    city->accept(satisfactionVisitor);

    // Calculate expected average satisfaction
    float expectedSatisfaction = 0;
    int residentialCount = 0;

    // Iterate over the grid manually to calculate expected satisfaction
    for (auto &row : city->getGrid())
    {
        for (Entity *entity : row)
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

    float expectedAverageSatisfaction = residentialCount > 0 ? expectedSatisfaction / residentialCount : 0;

    // Check the average satisfaction collected by the SatisfactionVisitor
    CHECK(satisfactionVisitor.getAverageSatisfaction() == expectedAverageSatisfaction);
    CHECK(satisfactionVisitor.getResidentialCount() == residentialCount);

    city->reset();
}

TEST_CASE("SatisfactionVisitorTest - Empty grid produces no satisfaction")
{
    // Create an empty city grid (all nullptrs)
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
