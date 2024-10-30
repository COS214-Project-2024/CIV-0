#include "TaxCalculationVisitor.h"
#include <unordered_set>

TaxCalculationVisitor::TaxCalculationVisitor()
    : totalResidentialTax(0), totalEconomicTax(0) {}

TaxCalculationVisitor::~TaxCalculationVisitor() {}

void TaxCalculationVisitor::visit(City *city)
{
    std::unordered_set<Entity*> visitedEntities;  // Track unique entities
    std::vector<std::vector<Entity *>> &grid = city->getGrid();

    int residentialTaxRate = city->getResidentialTax();
    int economicTaxRate = city->getEconomicTax();

    for (const auto &row : grid)
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr && visitedEntities.insert(entity).second)
            {
                if (ResidentialBuilding *residential = dynamic_cast<ResidentialBuilding *>(entity))
                {
                    totalResidentialTax += (residential->getRevenue() * residentialTaxRate) / 100;
                }
                else if (EconomicBuilding *economic = dynamic_cast<EconomicBuilding *>(entity))
                {
                    totalEconomicTax += (economic->getRevenue() * economicTaxRate) / 100;
                }
            }
        }
    }
}
