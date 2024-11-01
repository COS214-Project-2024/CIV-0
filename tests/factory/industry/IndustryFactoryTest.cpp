#include "doctest.h"
#include "factory/industry/IndustryFactory.h"
#include "utils/EntityType.h"
TEST_CASE("IndustryFactoryTest test") {
	IndustryFactory industryFactory;
	Entity* entity = industryFactory.createEntity(EntityType::CONCRETEPRODUCER, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::CONCRETEPRODUCER, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::CONCRETEPRODUCER, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::STONEPRODUCER, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::STONEPRODUCER, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::STONEPRODUCER, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::WOODPRODUCER, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::WOODPRODUCER, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = industryFactory.createEntity(EntityType::WOODPRODUCER, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
}