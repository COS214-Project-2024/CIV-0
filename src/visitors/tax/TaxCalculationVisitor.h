#ifndef TAXCALCULATIONVISITOR_H
#define TAXCALCULATIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/building/economic/EconomicBuilding.h"

/**
 * @brief Visitor that calculates total tax from residential and economic buildings in a city.
 */
class TaxCalculationVisitor : public CityVisitor
{
private:
    int totalResidentialTax; /**< Accumulated tax from residential buildings */
    int totalEconomicTax;    /**< Accumulated tax from economic buildings */

public:
    /**
     * @brief Constructs a TaxCalculationVisitor with zeroed tax values.
     */
    TaxCalculationVisitor();

    /**
     * @brief Default destructor.
     */
    ~TaxCalculationVisitor();

    /**
     * @brief Visits a city to calculate tax from buildings.
     * @param city Pointer to the City object being visited.
     */
    void visit(City *city) override;

    /**
     * @brief Gets the total tax from residential buildings.
     * @return Total residential tax.
     */
    int getTotalResidentialTax() const { return totalResidentialTax; }

    /**
     * @brief Gets the total tax from economic buildings.
     * @return Total economic tax.
     */
    int getTotalEconomicTax() const { return totalEconomicTax; }

    /**
     * @brief Gets the combined tax from residential and economic buildings.
     * @return Sum of residential and economic taxes.
     */
    int getTotalTax() const { return totalResidentialTax + totalEconomicTax; }
};

#endif // TAXCALCULATIONVISITOR_H