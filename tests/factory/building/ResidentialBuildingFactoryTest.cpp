#include "doctest.h"
#include "factory/building/ResidentialBuildingFactory.h"
#include "utils/EntityType.h"
TEST_CASE("ResidentialBuildingFactoryTest test") {
    ResidentialBuildingFactory residentialBuildingFactory;
    Entity* entity = residentialBuildingFactory.createSmallEntity(EntityType::HOUSE, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = residentialBuildingFactory.createMediumEntity(EntityType::HOUSE, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = residentialBuildingFactory.createLargeEntity(EntityType::HOUSE, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = residentialBuildingFactory.createSmallEntity(EntityType::APARTMENT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = residentialBuildingFactory.createMediumEntity(EntityType::APARTMENT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = residentialBuildingFactory.createLargeEntity(EntityType::APARTMENT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
}
