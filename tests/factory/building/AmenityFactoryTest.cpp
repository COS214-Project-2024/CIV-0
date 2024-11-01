#include "doctest.h"
#include "factory/building/AmenityFactory.h"
#include "utils/EntityType.h"
TEST_CASE("AmenityFactoryTest test") {
	AmenityFactory amenityFactory;
	Entity* entity = amenityFactory.createEntity(EntityType::PARK, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::PARK, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::PARK, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::THEATER, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::THEATER, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::THEATER, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::MONUMENT, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::MONUMENT, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = amenityFactory.createEntity(EntityType::MONUMENT, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
}
