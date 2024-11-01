#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"

/**
 * @class ResidentialBuildingFactory
 * @brief Factory class for creating residential buildings, including houses and apartments.
 * 
 * Inherits from EntityFactory and provides methods to create various-sized residential
 * buildings (small, medium, and large) of different types at specified positions.
 */
class ResidentialBuildingFactory : public EntityFactory {
public:
    /**
     * @brief Default constructor for ResidentialBuildingFactory.
     */
    ResidentialBuildingFactory();

    /**
     * @brief Destructor for ResidentialBuildingFactory.
     */
    ~ResidentialBuildingFactory();

    /**
     * @brief Creates a residential building of a specified type and size at the given coordinates.
     * 
     * @param type Type of residential building to create (e.g., House, Apartment).
     * @param size Size of the building (small, medium, or large).
     * @param xPos X-coordinate for the building's position.
     * @param yPos Y-coordinate for the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

private:
    /**
     * @brief Creates a house of the specified size at a given position.
     * 
     * @param size Size of the house (small, medium, or large).
     * @param xPos X-coordinate for the house's position.
     * @param yPos Y-coordinate for the house's position.
     * @return A pointer to the created House entity.
     */
    Entity* createHouse(Size size, int xPos, int yPos);

    /**
     * @brief Creates an apartment of the specified size at a given position.
     * 
     * @param size Size of the apartment (small, medium, or large).
     * @param xPos X-coordinate for the apartment's position.
     * @param yPos Y-coordinate for the apartment's position.
     * @return A pointer to the created Apartment entity.
     */
    Entity* createApartment(Size size, int xPos, int yPos);
};

#endif // RESIDENTIALBUILDINGFACTORY_H
