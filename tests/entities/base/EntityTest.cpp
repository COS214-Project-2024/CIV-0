#include "doctest.h"
#include "entities/base/Entity.h"
#include "entities/building/residential/House.h"
#include "entities/building/economic/Factory.h"
#include "city/City.h"

// Mock Size for testing
Size testSize = Size::MEDIUM;

TEST_CASE("Entity basic properties and state initialization") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 1, 1);
    CHECK(resBuilding.getXPosition() == 1);
    CHECK(resBuilding.getYPosition() == 1);
    CHECK(resBuilding.isBuilt() == false);  // Starts in construction if buildTime > 0

    Factory factoryBuilding(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 2, 2);
    CHECK(factoryBuilding.getXPosition() == 2);
    CHECK(factoryBuilding.getYPosition() == 2);
}

TEST_CASE("Entity clone and copy constructor") {
    House originalBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 1, 1);
    originalBuilding.setCapacity(200);

    Entity* clonedBuilding = originalBuilding.clone();
    CHECK(clonedBuilding != &originalBuilding);  // Check that they are not the same instance

    House* clonedResBuilding = dynamic_cast<House*>(clonedBuilding);
    REQUIRE(clonedResBuilding != nullptr);
    CHECK(clonedResBuilding->getCapacity() == 200);
    CHECK(clonedResBuilding->getXPosition() == 1);
    CHECK(clonedResBuilding->getYPosition() == 1);
    
    delete clonedBuilding;
}

TEST_CASE("Effect radius and within effect radius check") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 5, 5);
    Factory nearbyFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 6, 6);

    CHECK(resBuilding.isWithinEffectRadius(&nearbyFactory) == true);

    Factory distantFactory(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 20, 20);
    CHECK(resBuilding.isWithinEffectRadius(&distantFactory) == false);
}

TEST_CASE("State transitions and observer pattern") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 3, 3);
    Factory factoryBuilding(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 4, 4);

    // Observer subscription test
    resBuilding.subscribe(&factoryBuilding);
    CHECK(resBuilding.getObservers().size() == 1);

    // Update factory state and check House effect
    factoryBuilding.update(); // This would call updateFactory on resBuilding
    resBuilding.calculateSatisfaction();

    // Unsubscribe and check
    resBuilding.unsubscribe(&factoryBuilding);
    CHECK(resBuilding.getObservers().empty() == true);
}

TEST_CASE("Entity satisfaction calculation") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 1, 1);
    CHECK(resBuilding.getSatisfaction() == 100);

    Factory factoryBuilding(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 2, 2);
    resBuilding.updateFactory(&factoryBuilding);
    resBuilding.calculateSatisfaction();

    // Check that satisfaction is bounded by 0 and 100
    resBuilding.reset();
    CHECK(resBuilding.getSatisfaction() == 100);
    resBuilding.calculateSatisfaction();
    CHECK(resBuilding.getSatisfaction() <= 100);
}

TEST_CASE("Build state transition") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 2, 2);
    CHECK(resBuilding.isBuilt() == false);  // Starts under construction

    resBuilding.updateBuildState();
    CHECK(resBuilding.isBuilt() == false);  // Still under construction if buildTime > 1
    
    // Simulate enough updates to transition to Built state
    for (int i = 0; i < ConfigManager::getEntityConfig(EntityType::HOUSE, testSize).buildTime; i++) {
        resBuilding.updateBuildState();
    }
    CHECK(resBuilding.isBuilt() == true);  // Transitioned to built
}

TEST_CASE("House - capacity and satisfaction interaction") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 5, 5);
    resBuilding.setCapacity(300);
    CHECK(resBuilding.getCapacity() == 300);
}

TEST_CASE("Test Observer Pattern - residential notifications") {
    City* cityInstance = City::instance();
    cityInstance->addEntity(new House(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 1, 1));

    Factory factoryBuilding(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 2, 2);
    CHECK(factoryBuilding.getObservers().size() > 0);  // Nearby House should be subscribed

    // Placing residential buildings and checking subscriptions
    House nearbyResidential(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 3, 3);
    factoryBuilding.subscribeToAllResidentialInRadius();
    CHECK(factoryBuilding.getObservers().size() > 0);  // Checks observer pattern effectiveness
}

TEST_CASE("Unsubscribe from all buildings") {
    House resBuilding(ConfigManager::getEntityConfig(EntityType::HOUSE, testSize), testSize, 1, 1);
    Factory factoryBuilding(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 1, 1);

    resBuilding.subscribe(&factoryBuilding);
    CHECK(resBuilding.getObservers().size() == 1);

    resBuilding.unsubscribeFromAllBuildings();
    CHECK(resBuilding.getObservers().empty() == true);
}

TEST_CASE("Symbol and basic properties") {
    Factory factoryBuilding(ConfigManager::getEntityConfig(EntityType::FACTORY, testSize), testSize, 3, 3);
    CHECK(factoryBuilding.getXPosition() == 3);
    CHECK(factoryBuilding.getYPosition() == 3);
    CHECK(factoryBuilding.getWidth() == ConfigManager::getEntityConfig(EntityType::FACTORY, testSize).width);
    CHECK(factoryBuilding.getHeight() == ConfigManager::getEntityConfig(EntityType::FACTORY, testSize).height);

    factoryBuilding.setSymbol("F");
    CHECK(factoryBuilding.getSymbol() == "F");
}
