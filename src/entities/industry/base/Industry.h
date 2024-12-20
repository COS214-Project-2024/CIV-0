#ifndef INDUSTRY_H
#define INDUSTRY_H

#include "entities/base/Entity.h"
#include "entities/building/residential/ResidentialBuilding.h"

/**
 * @class Industry
 * @brief Represents an industrial entity within the game.
 *
 * The Industry class is responsible for managing properties specific to
 * industrial entities, such as production output. Derived classes are expected
 * to implement the `update` and `clone` methods for specific industrial behavior.
 */
class Industry : public Entity
{
private:
    int output; ///< Production output of the industrial entity.
    Cost cost; ///< Cost structure for the industrial entity.
public:
    /**
     * @brief Constructs an Industry entity with specified attributes.
     *
     * @param ec Configuration settings for the entity.
     * @param size Size of the industrial entity.
     * @param xPos X-coordinate position of the entity.
     * @param yPos Y-coordinate position of the entity.
     */
    Industry(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the Industry class.
     *
     * Creates a new Industry entity by copying the attributes of an existing Industry.
     *
     * @param industry Pointer to the Industry object to be copied.
     */
    Industry(Industry *industry);

    /**
     * @brief Virtual destructor for the Industry class.
     */
    virtual ~Industry();

    /**
     * @brief Updates the state of the industry entity.
     *
     * This function must be implemented in derived classes.
     */
    virtual void update() = 0;

    /**
     * @brief Creates a clone of the industry entity.
     *
     * This function must be implemented in derived classes.
     *
     * @return A pointer to the cloned Industry entity.
     */
    virtual Entity *clone() = 0;

    /**
     * @brief Gets the production output of the industry.
     *
     * @return The production output value.
     */
    virtual int getOutput();

    /**
     * @brief Sets the production output of the industry.
     *
     * @param output The new output value.
     */
    void setOutput(int output);

    /**
     * @brief Gets the current level of the industry.
     *
     * @return The level of the industry (default implementation returns 0).
     */
    virtual int getLevel();

    /**
     * @brief Gets the cost of an upgrade.
     *
     * @return Cost struct of various costs for upgrade.
     */
    virtual Cost getCost();

    /**
     * @brief Upgrades the current industry to the next level.
     *
     * @return A pointer to the upgraded industry instance, or nullptr if already at maximum level.
     */
    virtual Entity* upgrade() = 0;
};

#endif // INDUSTRY_H