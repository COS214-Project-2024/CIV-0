#include "ServiceBuildingFactory.h"

ServiceBuildingFactory::ServiceBuildingFactory() {}
ServiceBuildingFactory::~ServiceBuildingFactory() {}

Entity* ServiceBuildingFactory::createSmallEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
		case EntityType::HOSPITAL:
			return createHospital(Size::SMALL, xPos, yPos);
			break;
		case EntityType::POLICESTATION:
			return createPoliceStation(Size::SMALL, xPos, yPos);
			break;
		case EntityType::SCHOOL:
			return createSchool(Size::SMALL, xPos, yPos);
			break;
		default:
			return nullptr;
	}
}

Entity* ServiceBuildingFactory::createMediumEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
        case EntityType::HOSPITAL:
            return createHospital(Size::MEDIUM, xPos, yPos);
            break;
        case EntityType::POLICESTATION:
            return createPoliceStation(Size::MEDIUM, xPos, yPos);
            break;
        case EntityType::SCHOOL:
            return createSchool(Size::MEDIUM, xPos, yPos);
            break;
        default:
            return nullptr;
    }
}

Entity* ServiceBuildingFactory::createLargeEntity(EntityType type, int xPos, int yPos) {
	switch (type) {
        case EntityType::HOSPITAL:
            return createHospital(Size::LARGE, xPos, yPos);
            break;
        case EntityType::POLICESTATION:
            return createPoliceStation(Size::LARGE, xPos, yPos);
            break;
        case EntityType::SCHOOL:
            return createSchool(Size::LARGE, xPos, yPos);
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