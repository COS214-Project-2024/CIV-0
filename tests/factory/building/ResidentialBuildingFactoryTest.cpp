
#include "doctest.h"
#include "factory/building/ResidentialBuildingFactory.h"
#include "utils/EntityType.h"
TEST_CASE("ResidentialBuildingFactoryTest test") {
	ResidentialBuildingFactory residentialBuildingFactory;
	Entity* entity = residentialBuildingFactory.createEntity(EntityType::HOUSE, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = residentialBuildingFactory.createEntity(EntityType::HOUSE, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = residentialBuildingFactory.createEntity(EntityType::HOUSE, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = residentialBuildingFactory.createEntity(EntityType::APARTMENT, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = residentialBuildingFactory.createEntity(EntityType::APARTMENT, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = residentialBuildingFactory.createEntity(EntityType::APARTMENT, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
}
