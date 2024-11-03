
#include "doctest.h"
#include "factory/utility/UtilityFactory.h"
#include "utils/EntityType.h"
TEST_CASE("UtilityFactoryTest test") {
	UtilityFactory utilityFactory;
	Entity* entity = utilityFactory.createEntity(EntityType::POWERPLANT, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::POWERPLANT, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::POWERPLANT, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);

	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::WATERSUPPLY, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::WATERSUPPLY, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::WATERSUPPLY, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::WASTEMANAGEMENT, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::WASTEMANAGEMENT, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::WASTEMANAGEMENT, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::SEWAGESYSTEM, Size::SMALL, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::SEWAGESYSTEM, Size::MEDIUM, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
	entity = utilityFactory.createEntity(EntityType::SEWAGESYSTEM, Size::LARGE, 0, 0);
	CHECK(entity != nullptr);
	CHECK(entity->getXPosition() == 0);
	CHECK(entity->getYPosition() == 0);
	delete entity;
}
