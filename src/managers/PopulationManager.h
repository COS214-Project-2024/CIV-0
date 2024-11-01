/**
 * @file PopulationManager.h
 * @brief Manages population growth, capacity, and satisfaction for the City.
 */

#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "visitors/population/PopulationVisitor.h"
#include "visitors/satisfaction/SatisfactionVisitor.h"
#include "visitors/utility/UtilityVisitor.h"
#include "city/City.h"

/**
 * @class PopulationManager
 * @brief Responsible for managing the population growth, decrease, 
 * capacity calculations, and satisfaction levels within a City.
 */
class PopulationManager
{
private:
    int minimumIncrease; /**< Minimum population increase per growth cycle */
    int maximumIncrease; /**< Maximum population increase per growth cycle */

public:
    /**
     * @brief Constructs a PopulationManager with specified growth parameters.
     * @param minimumIncrease Minimum population increase per cycle.
     * @param maximumIncrease Maximum population increase per cycle.
     */
    PopulationManager(int minimumIncrease, int maximumIncrease);

    /**
     * @brief Destructor for PopulationManager.
     */
    ~PopulationManager();

    /**
     * @brief Calculates the population capacity of the City and sets it.
     */
    void calculatePopulationCapacity();

    /**
     * @brief Increases the City's population by a random value within 
     * the specified minimum and maximum range.
     */
    void growPopulation();

    /**
     * @brief Decreases the City's population by a random value within 
     * the specified minimum and maximum range.
     */
    void decreasePopulation();

    /**
     * @brief Calculates the satisfaction level of the City based on 
     * available resources and utilities, updating the City's satisfaction.
     */
    void calculateSatisfaction();
};

#endif // POPULATIONMANAGER_H
