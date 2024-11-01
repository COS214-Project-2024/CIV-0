#include "doctest.h"
#include "factory/building/EconomicBuildingFactory.h"
#include "utils/EntityType.h"
TEST_CASE("EconomicBuildingFactoryTest test") {
    EconomicBuildingFactory economicBuildingFactory;
    Entity* entity = economicBuildingFactory.createEntity(EntityType::FACTORY,Size::SMALL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createEntity(EntityType::FACTORY,Size::MEDIUM, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createEntity(EntityType::FACTORY,Size::LARGE, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createEntity(EntityType::SHOPPINGMALL,Size::SMALL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createEntity(EntityType::SHOPPINGMALL,Size::MEDIUM, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createEntity(EntityType::SHOPPINGMALL,Size::LARGE, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    
}