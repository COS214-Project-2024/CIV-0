#include "doctest.h"
#include "visitors/tax/TaxCalculationVisitor.h"
#include "city/City.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"
#include "entities/building/economic/Office.h"
#include "entities/building/economic/ShoppingMall.h"
#include "utils/ConfigManager.h"

TEST_CASE("TaxCalculationVisitorTest - Collect taxes from buildings using ConfigManager")
{
    // Create a city instance
    City *city = City::instance();

    // Set tax rates for the city using setters
    city->setResidentialTax(10); // 10% residential tax
    city->setEconomicTax(20);    // 20% economic tax

    // Use ConfigManager to get the expected revenue for the specific building types
    EntityConfig smallHouseConfig = ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL);
    EntityConfig largeApartmentConfig = ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::LARGE);
    EntityConfig mediumOfficeConfig = ConfigManager::getEntityConfig(EntityType::OFFICE, Size::MEDIUM);
    EntityConfig largeShoppingMallConfig = ConfigManager::getEntityConfig(EntityType::SHOPPINGMALL, Size::LARGE);

    // Mocking the city grid with different types of buildings (House, Apartment, Office, ShoppingMall)
    std::vector<std::vector<Entity *>> mockGrid = {
        {new House(smallHouseConfig, Size::SMALL, 0, 0), nullptr, new Office(mediumOfficeConfig, Size::MEDIUM, 0, 1)},
        {nullptr, new Apartment(largeApartmentConfig, Size::LARGE, 1, 0), nullptr},
        {new ShoppingMall(largeShoppingMallConfig, Size::LARGE, 2, 0), nullptr, nullptr}};

    // Assign this mock grid to the city
    city->getGrid() = mockGrid;

    // Create a TaxCalculationVisitor instance
    TaxCalculationVisitor taxVisitor;

    // Let the visitor visit the city
    city->accept(taxVisitor);

    // Calculate expected residential and economic taxes using ConfigManager:
    int expectedResidentialTax = (smallHouseConfig.revenue * city->getResidentialTax()) / 100 + (largeApartmentConfig.revenue * city->getResidentialTax()) / 100;

    int expectedEconomicTax = (mediumOfficeConfig.revenue * city->getEconomicTax()) / 100 + (largeShoppingMallConfig.revenue * city->getEconomicTax()) / 100;

    // Check the taxes collected by the TaxCalculationVisitor
    CHECK(taxVisitor.getTotalResidentialTax() == expectedResidentialTax);
    CHECK(taxVisitor.getTotalEconomicTax() == expectedEconomicTax);
    CHECK(taxVisitor.getTotalTax() == (expectedResidentialTax + expectedEconomicTax));

    // Clean up the dynamically allocated entities
    for (auto &row : mockGrid)
    {
        for (Entity *entity : row)
        {
            delete entity; // Free each entity
        }
    }
}

TEST_CASE("TaxCalculationVisitorTest - Empty grid produces no taxes using ConfigManager")
{
    // Create a city instance
    City *city = City::instance();

    // Create an empty city grid (all nullptrs)
    std::vector<std::vector<Entity *>> emptyGrid(3, std::vector<Entity *>(3, nullptr));

    // Assign the empty grid to the city
    city->getGrid() = emptyGrid;

    // Set tax rates for the city using setters
    city->setResidentialTax(10); // 10% residential tax
    city->setEconomicTax(20);    // 20% economic tax

    // Create a TaxCalculationVisitor instance
    TaxCalculationVisitor taxVisitor;

    // Let the visitor visit the city
    city->accept(taxVisitor);

    // Check that no taxes were collected
    CHECK(taxVisitor.getTotalResidentialTax() == 0);
    CHECK(taxVisitor.getTotalEconomicTax() == 0);
    CHECK(taxVisitor.getTotalTax() == 0);
}