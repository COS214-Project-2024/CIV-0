
#include "doctest.h"
#include "factory/building/ServiceBuildingFactory.h"
#include "utils/EntityType.h"
TEST_CASE("ServiceBuildingFactoryTest test") {
	ServiceBuildingFactory serviceBuildingFactory;
	Entity* entity = serviceBuildingFactory.createEntity(EntityType::HOSPITAL, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::HOSPITAL, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::HOSPITAL, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::POLICESTATION, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::POLICESTATION, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::POLICESTATION, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::SCHOOL, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::SCHOOL, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = serviceBuildingFactory.createEntity(EntityType::SCHOOL, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
}
