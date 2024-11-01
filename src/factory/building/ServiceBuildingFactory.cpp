
#include "ServiceBuildingFactory.h"

ServiceBuildingFactory::ServiceBuildingFactory() {}
ServiceBuildingFactory::~ServiceBuildingFactory() {}

Entity* ServiceBuildingFactory::createEntity(EntityType type, Size size, int xPos, int yPos) {
	switch (type) {
		case EntityType::HOSPITAL:
			return createHospital(size, xPos, yPos);
			break;
		case EntityType::POLICESTATION:
			return createPoliceStation(size, xPos, yPos);
			break;
		case EntityType::SCHOOL:
			return createSchool(size, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* ServiceBuildingFactory::createHospital(Size size, int xPos, int yPos) {
	return new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, size), size, xPos, yPos);
}

Entity* ServiceBuildingFactory::createPoliceStation(Size size, int xPos, int yPos) {
	return new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, size), size, xPos, yPos);
}

Entity* ServiceBuildingFactory::createSchool(Size size, int xPos, int yPos) {
	return new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, size), size, xPos, yPos);
}

