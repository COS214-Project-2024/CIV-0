
#ifndef SERVICEBUILDINGFACTORY_H
#define SERVICEBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"

/**
 * @class ServiceBuildingFactory
 * @brief A factory class for creating service buildings such as hospitals, police stations, and schools.
 * 
 * This class inherits from EntityFactory and provides methods for creating small, medium,
 * and large service buildings of different types.
 */
class ServiceBuildingFactory : public EntityFactory {
public:
    /**
     * @brief Constructor for the ServiceBuildingFactory class.
     */
    ServiceBuildingFactory();

    /**
     * @brief Destructor for the ServiceBuildingFactory class.
     */
    ~ServiceBuildingFactory();

    /**
     * @brief Creates a small service building of the specified type at the given position.
     * 
     * @param type The type of service building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos) override;

    /**
     * @brief Creates a medium service building of the specified type at the given position.
     * 
     * @param type The type of service building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos) override;

    /**
     * @brief Creates a large service building of the specified type at the given position.
     * 
     * @param type The type of service building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos) override;

private:
    /**
     * @brief Creates a hospital of the specified size at the given position.
     * 
     * @param size The size of the hospital to create.
     * @param xPos The x-coordinate of the hospital's position.
     * @param yPos The y-coordinate of the hospital's position.
     * @return A pointer to the created Entity.
     */
    Entity* createHospital(Size size, int xPos, int yPos);

    /**
     * @brief Creates a police station of the specified size at the given position.
     * 
     * @param size The size of the police station to create.
     * @param xPos The x-coordinate of the police station's position.
     * @param yPos The y-coordinate of the police station's position.
     * @return A pointer to the created Entity.
     */
    Entity* createPoliceStation(Size size, int xPos, int yPos);

    /**
     * @brief Creates a school of the specified size at the given position.
     * 
     * @param size The size of the school to create.
     * @param xPos The x-coordinate of the school's position.
     * @param yPos The y-coordinate of the school's position.
     * @return A pointer to the created Entity.
     */
    Entity* createSchool(Size size, int xPos, int yPos);
};

#endif // SERVICEBUILDINGFACTORY_H
