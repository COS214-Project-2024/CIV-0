#include "doctest.h"
#include "factory/industry/IndustryFactory.h"
#include "utils/EntityType.h"
TEST_CASE("IndustryFactoryTest test"){
    IndustryFactory industryFactory;
    Entity* entity = industryFactory.createSmallEntity(EntityType::CONCRETEPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createMediumEntity(EntityType::CONCRETEPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createLargeEntity(EntityType::CONCRETEPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createSmallEntity(EntityType::STONEPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createMediumEntity(EntityType::STONEPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createLargeEntity(EntityType::STONEPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createSmallEntity(EntityType::WOODPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createMediumEntity(EntityType::WOODPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = industryFactory.createLargeEntity(EntityType::WOODPRODUCER, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
}