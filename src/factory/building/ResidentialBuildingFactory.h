#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"

/**
 * @class ResidentialBuildingFactory
 * @brief A factory class for creating residential buildings like houses and apartments.
 * 
 * This class inherits from EntityFactory and provides methods to create small, medium,
 * and large residential buildings of different types.
 */
class ResidentialBuildingFactory : public EntityFactory {
public:
    /**
     * @brief Constructor for the ResidentialBuildingFactory class.
     */
    ResidentialBuildingFactory();

    /**
     * @brief Destructor for the ResidentialBuildingFactory class.
     */
    ~ResidentialBuildingFactory();

    /**
     * @brief Creates a small residential building of the specified type at the given position.
     * 
     * @param type The type of residential building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a medium residential building of the specified type at the given position.
     * 
     * @param type The type of residential building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a large residential building of the specified type at the given position.
     * 
     * @param type The type of residential building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);

private:
    /**
     * @brief Creates a house of the specified size at the given position.
     * 
     * @param size The size of the house to create.
     * @param xPos The x-coordinate of the house's position.
     * @param yPos The y-coordinate of the house's position.
     * @return A pointer to the created Entity.
     */
    Entity* createHouse(Size size, int xPos, int yPos);

    /**
     * @brief Creates an apartment of the specified size at the given position.
     * 
     * @param size The size of the apartment to create.
     * @param xPos The x-coordinate of the apartment's position.
     * @param yPos The y-coordinate of the apartment's position.
     * @return A pointer to the created Entity.
     */
    Entity* createApartment(Size size, int xPos, int yPos);
};

#endif // RESIDENTIALBUILDINGFACTORY_H
