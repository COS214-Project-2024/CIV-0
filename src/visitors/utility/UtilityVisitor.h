#ifndef UTILITYVISITOR_H
#define UTILITYVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "entities/utility/base/Utility.h"

/**
 * @class UtilityVisitor
 * @brief Visitor class for collecting data on utility outputs and handling capacities in a city.
 */
class UtilityVisitor : public CityVisitor
{
private:
    int totalElectricity;      /**< Total electricity output from power plants. */
    int totalWater;            /**< Total water output from water supplies. */
    int totalSewageHandled;    /**< Total sewage capacity from sewage systems. */
    int totalWasteHandled;     /**< Total waste handling capacity from waste management facilities. */

public:
    /**
     * @brief Constructs a UtilityVisitor with zeroed utility values.
     */
    UtilityVisitor();

    /**
     * @brief Default destructor.
     */
    virtual ~UtilityVisitor();

    /**
     * @brief Visits a city to collect utility data from various utility entities.
     * @param city Pointer to the City object being visited.
     */
    void visit(City *city) override;

    /**
     * @brief Gets the total electricity output.
     * @return Total electricity generated by power plants.
     */
    int getTotalElectricity() const;

    /**
     * @brief Gets the total water output.
     * @return Total water supplied by water sources.
     */
    int getTotalWater() const;

    /**
     * @brief Gets the total sewage handling capacity.
     * @return Total sewage capacity from sewage systems.
     */
    int getTotalSewageHandled() const;

    /**
     * @brief Gets the total waste handling capacity.
     * @return Total waste handled by waste management facilities.
     */
    int getTotalWasteHandled() const;
};

#endif // UTILITYVISITOR_H