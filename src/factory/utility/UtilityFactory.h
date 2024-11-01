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
 * @brief Factory class to create utility entities such as power plants, water supplies, 
 *        waste management facilities, and sewage systems.
 * 
 * Inherits from EntityFactory and provides methods to create different-sized utility entities.
 * Supports creating small, medium, and large facilities, placing them at specified positions.
 */
class UtilityFactory : public EntityFactory {
public:
    /**
     * @brief Default constructor for UtilityFactory.
     */
    UtilityFactory();

    /**
     * @brief Destructor for UtilityFactory.
     */
    ~UtilityFactory();

    /**
     * @brief Creates a utility entity of a specified type and size at a specified position.
     * 
     * @param type The type of utility entity to create (e.g., power plant, water supply).
     * @param size The size of the entity to create (small, medium, or large).
     * @param xPos The x-coordinate for the entity's position.
     * @param yPos The y-coordinate for the entity's position.
     * @return A pointer to the created Entity.
     */
    virtual Entity* createEntity(EntityType type, Size size, int xPos, int yPos);

private:
    /**
     * @brief Creates a power plant of the specified size at a given position.
     * 
     * @param size Size of the power plant (small, medium, or large).
     * @param xPos X-coordinate for the power plant's position.
     * @param yPos Y-coordinate for the power plant's position.
     * @return A pointer to the created PowerPlant entity.
     */
    Entity* createPowerPlant(Size size, int xPos, int yPos);

    /**
     * @brief Creates a water supply of the specified size at a given position.
     * 
     * @param size Size of the water supply (small, medium, or large).
     * @param xPos X-coordinate for the water supply's position.
     * @param yPos Y-coordinate for the water supply's position.
     * @return A pointer to the created WaterSupply entity.
     */
    Entity* createWaterSupply(Size size, int xPos, int yPos);

    /**
     * @brief Creates a waste management facility of the specified size at a given position.
     * 
     * @param size Size of the waste management facility (small, medium, or large).
     * @param xPos X-coordinate for the waste management facility's position.
     * @param yPos Y-coordinate for the waste management facility's position.
     * @return A pointer to the created WasteManagement entity.
     */
    Entity* createWasteManagement(Size size, int xPos, int yPos);

    /**
     * @brief Creates a sewage system of the specified size at a given position.
     * 
     * @param size Size of the sewage system (small, medium, or large).
     * @param xPos X-coordinate for the sewage system's position.
     * @param yPos Y-coordinate for the sewage system's position.
     * @return A pointer to the created SewageSystem entity.
     */
    Entity* createSewageSystem(Size size, int xPos, int yPos);
};

#endif // UTILITYFACTORY_H
