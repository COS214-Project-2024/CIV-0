#ifndef ECONOMICBUILDINGFACTORY_H
#define ECONOMICBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/economic/Factory.h"
#include "entities/building/economic/ShoppingMall.h"
#include "entities/building/economic/Office.h"

/**
 * @class EconomicBuildingFactory
 * @brief Factory class for creating economic buildings, including factories, shopping malls, and offices.
 * 
 * Inherits from EntityFactory and provides methods to create different-sized economic buildings 
 * (small, medium, and large) at specified coordinates.
 */
class EconomicBuildingFactory : public EntityFactory {
public:
    /**
     * @brief Default constructor for EconomicBuildingFactory.
     */
    EconomicBuildingFactory();

    /**
     * @brief Destructor for EconomicBuildingFactory.
     */
    ~EconomicBuildingFactory();

    /**
     * @brief Creates an economic building of the specified type and size at the given position.
     * 
     * @param type The type of economic building to create (e.g., Factory, ShoppingMall, Office).
     * @param size The size of the building (small, medium, or large).
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

private:
    /**
     * @brief Creates a factory of the specified size at the given position.
     * 
     * @param size The size of the factory (small, medium, or large).
     * @param xPos The x-coordinate for the factory's position.
     * @param yPos The y-coordinate for the factory's position.
     * @return A pointer to the created Factory entity.
     */
    Entity* createFactory(Size size, int xPos, int yPos);

    /**
     * @brief Creates a shopping mall of the specified size at the given position.
     * 
     * @param size The size of the shopping mall (small, medium, or large).
     * @param xPos The x-coordinate for the shopping mall's position.
     * @param yPos The y-coordinate for the shopping mall's position.
     * @return A pointer to the created ShoppingMall entity.
     */
    Entity* createShoppingMall(Size size, int xPos, int yPos);

    /**
     * @brief Creates an office building of the specified size at the given position.
     * 
     * @param size The size of the office (small, medium, or large).
     * @param xPos The x-coordinate for the office's position.
     * @param yPos The y-coordinate for the office's position.
     * @return A pointer to the created Office entity.
     */
    Entity* createOffice(Size size, int xPos, int yPos);
};

#endif // ECONOMICBUILDINGFACTORY_H
