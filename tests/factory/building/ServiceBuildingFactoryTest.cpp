#include "doctest.h"
#include "factory/building/ServiceBuildingFactory.h"
#include "utils/EntityType.h"
TEST_CASE("ServiceBuildingFactoryTest test") {
    ServiceBuildingFactory serviceBuildingFactory;
    Entity* entity = serviceBuildingFactory.createSmallEntity(EntityType::HOSPITAL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createMediumEntity(EntityType::HOSPITAL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createLargeEntity(EntityType::HOSPITAL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createSmallEntity(EntityType::POLICESTATION, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createMediumEntity(EntityType::POLICESTATION, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createLargeEntity(EntityType::POLICESTATION, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createSmallEntity(EntityType::SCHOOL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createMediumEntity(EntityType::SCHOOL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = serviceBuildingFactory.createLargeEntity(EntityType::SCHOOL, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    

}
