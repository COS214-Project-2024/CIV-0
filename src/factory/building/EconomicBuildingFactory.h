
#ifndef ECONOMICBUILDINGFACTORY_H
#define ECONOMICBUILDINGFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/building/economic/Factory.h"
#include "entities/building/economic/ShoppingMall.h"
#include "entities/building/economic/Office.h"

/**
 * @class EconomicBuildingFactory
 * @brief A factory class for creating economic buildings such as factories and shopping malls.
 * 
 * This class inherits from the EntityFactory base class and provides methods
 * for creating small, medium, and large instances of economic buildings.
 */
class EconomicBuildingFactory : public EntityFactory {
public:
    /**
     * @brief Constructor for the EconomicBuildingFactory class.
     */
    EconomicBuildingFactory();

    /**
     * @brief Destructor for the EconomicBuildingFactory class.
     */
    ~EconomicBuildingFactory();

    /**
     * @brief Creates a small economic building of the specified type at the given position.
     * 
     * @param type The type of economic building to create.
     * @param xPos The x-coordinate of the building's position.
     * @param yPos The y-coordinate of the building's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type,Size size, int xPos, int yPos);

private:
    /**
     * @brief Creates a factory of the specified size at the given position.
     * 
     * @param size The size of the factory to create.
     * @param xPos The x-coordinate of the factory's position.
     * @param yPos The y-coordinate of the factory's position.
     * @return A pointer to the created Entity.
     */
    Entity* createFactory(Size size, int xPos, int yPos);

    /**
     * @brief Creates a shopping mall of the specified size at the given position.
     * 
     * @param size The size of the shopping mall to create.
     * @param xPos The x-coordinate of the mall's position.
     * @param yPos The y-coordinate of the mall's position.
     * @return A pointer to the created Entity.
     */
    Entity* createShoppingMall(Size size, int xPos, int yPos);
    Entity* createOffice(Size size, int xPos, int yPos);
};

#endif // ECONOMICBUILDINGFACTORY_H

