#include "doctest.h"
#include "managers/PopulationManager.h"
#include "city/City.h"
#include "entities/building/residential/House.h"

TEST_CASE("PopulationManager Calculate Population Capacity Test") {
    PopulationManager pm(5, 15);
    City* c = City::instance();
    CHECK(c->getPopulationCapacity() == 0);
    c->addEntity(new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 3, 3));
    pm.calculatePopulationCapacity();
    CHECK(c->getPopulationCapacity() == 2);

    c->addEntity(new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 31, 13));
    c->addEntity(new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 23, 23));

    pm.calculatePopulationCapacity();
    CHECK(c->getPopulationCapacity() == 6);

    pm.calculateSatisfaction();
    CHECK(c->getSatisfaction() <= 100);
    CHECK(c->getSatisfaction() >= 0);
    CHECK(c->getElectricityProduction() == 0);
    CHECK(c->getWaterProduction() == 0);
    CHECK(c->getWasteProduction() == 0);
    CHECK(c->getSewageProduction() == 0);
    CHECK(c->getElectricityConsumption() == 6);
    CHECK(c->getWaterConsumption() == 3);

    c->reset();
}

TEST_CASE("PopulationManager Grow Population Test") {
    City* c = City::instance();
    int initialPopulation = c->getPopulation();
    
    PopulationManager pm(5, 15);
    pm.growPopulation();

    int newPopulation = c->getPopulation();
    CHECK(newPopulation > initialPopulation); // Check if population increased
    CHECK(newPopulation <= initialPopulation + 15); // Within expected range
    CHECK(newPopulation >= initialPopulation + 5);
}

TEST_CASE("PopulationManager Decrease Population Test") {
    City* c = City::instance();
    c->setPopulation(100);  // Set initial population for test
    
    PopulationManager pm(5, 15);
    pm.decreasePopulation();

    int decreasedPopulation = c->getPopulation();
    CHECK(decreasedPopulation < 100); // Check if population decreased
    CHECK(decreasedPopulation >= 100 - 15); // Within expected range
    CHECK(decreasedPopulation <= 100 - 5);
    c->reset();
}

TEST_CASE("PopulationManager Calculate Satisfaction Test") {
    PopulationManager pm(5, 15);
    pm.calculateSatisfaction();
    City* c = City::instance();

    // Assuming SatisfactionVisitor and UtilityVisitor set known values
    CHECK(c->getSatisfaction() <= 100);
    CHECK(c->getSatisfaction() >= 0);
    CHECK(c->getElectricityProduction() == 0);
    CHECK(c->getWaterProduction() == 0);
    CHECK(c->getWasteProduction() == 0);
    CHECK(c->getSewageProduction() == 0);
    CHECK(c->getElectricityConsumption() == 0);
    CHECK(c->getWaterConsumption() == 0);

    c->reset();
}
