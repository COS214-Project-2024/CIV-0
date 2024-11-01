#ifndef SERVICEBUILDINGFACTORY_H
#define SERVICEBUILDINGFACTORY_H

#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"
#include "factory/base/EntityFactory.h"

/**
 * @class ServiceBuildingFactory
 * @brief Factory class for creating service buildings such as hospitals, police stations, and schools.
 *
 * Inherits from EntityFactory and provides methods to create various-sized service buildings 
 * (small, medium, and large) of different types, positioned at specified coordinates.
 */
class ServiceBuildingFactory : public EntityFactory {
   public:
    /**
     * @brief Default constructor for ServiceBuildingFactory.
     */
    ServiceBuildingFactory();

    /**
     * @brief Destructor for ServiceBuildingFactory.
     */
    ~ServiceBuildingFactory();

    /**
     * @brief Creates a service building of the specified type and size at the given position.
     *
     * @param type The type of service building to create (e.g., Hospital, PoliceStation, School).
     * @param size The size of the service building (small, medium, or large).
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos) override;

   private:
    /**
     * @brief Creates a hospital of the specified size at the given position.
     *
     * @param size Size of the hospital (small, medium, or large).
     * @param xPos X-coordinate for the hospital's position.
     * @param yPos Y-coordinate for the hospital's position.
     * @return A pointer to the created Hospital entity.
     */
    Entity* createHospital(Size size, int xPos, int yPos);

    /**
     * @brief Creates a police station of the specified size at the given position.
     *
     * @param size Size of the police station (small, medium, or large).
     * @param xPos X-coordinate for the police station's position.
     * @param yPos Y-coordinate for the police station's position.
     * @return A pointer to the created PoliceStation entity.
     */
    Entity* createPoliceStation(Size size, int xPos, int yPos);

    /**
     * @brief Creates a school of the specified size at the given position.
     *
     * @param size Size of the school (small, medium, or large).
     * @param xPos X-coordinate for the school's position.
     * @param yPos Y-coordinate for the school's position.
     * @return A pointer to the created School entity.
     */
    Entity* createSchool(Size size, int xPos, int yPos);
};

#endif // SERVICEBUILDINGFACTORY_H
