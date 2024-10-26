#ifndef UTILITYVISITOR_H
#define UTILITYVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "entities/utility/base/Utility.h"

/**
 * @class UtilityVisitor
 * @brief Visitor class to collect utility outputs and handling capacities from various utility entities in the city.
 */
class UtilityVisitor : public CityVisitor
{
private:
    int totalElectricity;
    int totalWater;
    int totalSewageHandled; // Specifically for sewage systems
    int totalWasteHandled;  // Specifically for waste management

public:
    UtilityVisitor();
    virtual ~UtilityVisitor();

    void visit(City *city) override;

    // Getters for the collected utility data
    int getTotalElectricity() const;
    int getTotalWater() const;
    int getTotalSewageHandled() const;
    int getTotalWasteHandled() const;
};

#endif // UTILITYVISITOR_H
