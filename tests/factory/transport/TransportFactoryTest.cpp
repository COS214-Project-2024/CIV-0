
#include "doctest.h"
#include "factory/transport/TransportFactory.h"
#include "utils/EntityType.h"
TEST_CASE("TransportFactoryTest test") {
    TransportFactory transportFactory;
    Entity* entity = transportFactory.createSmallEntity(EntityType::BUSSTOP, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createMediumEntity(EntityType::BUSSTOP, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createLargeEntity(EntityType::BUSSTOP, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createSmallEntity(EntityType::TRAINSTATION, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createMediumEntity(EntityType::TRAINSTATION, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createLargeEntity(EntityType::TRAINSTATION, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createSmallEntity(EntityType::AIRPORT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createMediumEntity(EntityType::AIRPORT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
    entity = transportFactory.createLargeEntity(EntityType::AIRPORT, 0, 0);
    CHECK(entity != nullptr);
    CHECK(entity->getXPosition() == 0);
    CHECK(entity->getYPosition() == 0);
    delete entity;
}

