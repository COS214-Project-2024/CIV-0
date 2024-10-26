#include "doctest.h"
#include "factory/building/EconomicBuildingFactory.h"
#include "utils/EntityType.h"
TEST_CASE("EconomicBuildingFactoryTest test") {
    EconomicBuildingFactory economicBuildingFactory;
    Entity* entity = economicBuildingFactory.createSmallEntity(EntityType::FACTORY, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createMediumEntity(EntityType::FACTORY, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createLargeEntity(EntityType::FACTORY, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createSmallEntity(EntityType::SHOPPINGMALL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createMediumEntity(EntityType::SHOPPINGMALL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = economicBuildingFactory.createLargeEntity(EntityType::SHOPPINGMALL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    
}
