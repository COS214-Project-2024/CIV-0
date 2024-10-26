#ifndef TAXCALCULATIONVISITOR_H
#define TAXCALCULATIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/building/economic/EconomicBuilding.h"

class TaxCalculationVisitor : public CityVisitor
{
private:
    int totalResidentialTax;
    int totalEconomicTax;

public:
    TaxCalculationVisitor();
    ~TaxCalculationVisitor();

    // Override the visit method
    void visit(City *city) override;

    int getTotalResidentialTax() const { return totalResidentialTax; }
    int getTotalEconomicTax() const { return totalEconomicTax; }
    int getTotalTax() const { return totalResidentialTax + totalEconomicTax; }
};

#endif // TAXCALCULATIONVISITOR_H
