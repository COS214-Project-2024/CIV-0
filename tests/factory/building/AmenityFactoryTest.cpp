#include "doctest.h"
#include "factory/building/AmenityFactory.h"
#include "utils/EntityType.h"
TEST_CASE("AmenityFactoryTest test") {
    AmenityFactory amenityFactory;
    Entity* entity = amenityFactory.createSmallEntity(EntityType::PARK, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createMediumEntity(EntityType::PARK, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createLargeEntity(EntityType::PARK, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createSmallEntity(EntityType::THEATER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createMediumEntity(EntityType::THEATER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createLargeEntity(EntityType::THEATER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createSmallEntity(EntityType::MONUMENT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createMediumEntity(EntityType::MONUMENT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = amenityFactory.createLargeEntity(EntityType::MONUMENT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
}
