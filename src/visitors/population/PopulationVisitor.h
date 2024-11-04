#ifndef POPULATIONVISITOR_H
#define POPULATIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"

/**
 * @brief Visitor that calculates population and resource capacities in a city.
 */
class PopulationVisitor : public CityVisitor
{
private:
    int totalPopulationCapacity;     /**< Total capacity across all buildings */
    int totalWaterConsumption;       /**< Total water consumption of the city */
    int totalElectricityConsumption; /**< Total electricity consumption of the city */
    int housePopulationCapacity;     /**< Population capacity of houses */
    int apartmentPopulationCapacity; /**< Population capacity of apartments */

public:
    /**
     * @brief Constructs a PopulationVisitor with zeroed capacity and consumption values.
     */
    PopulationVisitor();

    /**
     * @brief Default destructor.
     */
    ~PopulationVisitor() {}

    /**
     * @brief Visits a city to calculate population and resource data.
     * @param city Pointer to the City object being visited.
     */
    void visit(City *city) override;

    /**
     * @brief Gets the total population capacity.
     * @return Total population capacity of all buildings.
     */
    int getTotalPopulationCapacity() const;

    /**
     * @brief Gets the total population capacity for houses.
     * @return Population capacity specific to houses.
     */
    int getHousePopulationCapacity() const;

    /**
     * @brief Gets the total water consumption.
     * @return Total water consumption in the city.
     */
    int getTotalWaterConsumption() const;

    /**
     * @brief Gets the total electricity consumption.
     * @return Total electricity consumption in the city.
     */
    int getTotalElectricityConsumption() const;

    /**
     * @brief Gets the total population capacity for apartments.
     * @return Population capacity specific to apartments.
     */
    int getApartmentPopulationCapacity() const;
};

#endif // POPULATIONVISITOR_H