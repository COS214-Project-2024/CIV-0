
#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "factory/base/EntityFactory.h"
#include "entities/base/Entity.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/sewagesystem/SewageSystem.h"

/**
 * @class UtilityFactory
 * @brief A factory class for creating utility entities such as power plants, water supplies, waste management, and sewage systems.
 * 
 * This class inherits from EntityFactory and provides methods for creating small, medium,
 * and large utility entities of different types.
 */
class UtilityFactory : public EntityFactory {
public:
    /**
     * @brief Constructor for the UtilityFactory class.
     */
    UtilityFactory();

    /**
     * @brief Destructor for the UtilityFactory class.
     */
    ~UtilityFactory();

    /**
     * @brief Creates a small utility entity of the specified type at the given position.
     * 
     * @param type The type of utility entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a medium utility entity of the specified type at the given position.
     * 
     * @param type The type of utility entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);

    /**
     * @brief Creates a large utility entity of the specified type at the given position.
     * 
     * @param type The type of utility entity to create.
     * @param xPos The x-coordinate of the entity's position.
     * @param yPos The y-coordinate of the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);

private:
    /**
     * @brief Creates a power plant of the specified size at the given position.
     * 
     * @param size The size of the power plant to create.
     * @param xPos The x-coordinate of the power plant's position.
     * @param yPos The y-coordinate of the power plant's position.
     * @return A pointer to the created Entity.
     */
    Entity* createPowerPlant(Size size, int xPos, int yPos);

    /**
     * @brief Creates a water supply of the specified size at the given position.
     * 
     * @param size The size of the water supply to create.
     * @param xPos The x-coordinate of the water supply's position.
     * @param yPos The y-coordinate of the water supply's position.
     * @return A pointer to the created Entity.
     */
    Entity* createWaterSupply(Size size, int xPos, int yPos);

    /**
     * @brief Creates a waste management facility of the specified size at the given position.
     * 
     * @param size The size of the waste management facility to create.
     * @param xPos The x-coordinate of the waste management facility's position.
     * @param yPos The y-coordinate of the waste management facility's position.
     * @return A pointer to the created Entity.
     */
    Entity* createWasteManagement(Size size, int xPos, int yPos);

    /**
     * @brief Creates a sewage system of the specified size at the given position.
     * 
     * @param size The size of the sewage system to create.
     * @param xPos The x-coordinate of the sewage system's position.
     * @param yPos The y-coordinate of the sewage system's position.
     * @return A pointer to the created Entity.
     */
    Entity* createSewageSystem(Size size, int xPos, int yPos);
};

#endif // UTILITYFACTORY_H
