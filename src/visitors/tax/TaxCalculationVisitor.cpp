#include "TaxCalculationVisitor.h"

TaxCalculationVisitor::TaxCalculationVisitor()
    : totalResidentialTax(0), totalEconomicTax(0) {}

TaxCalculationVisitor::~TaxCalculationVisitor() {}

void TaxCalculationVisitor::visit(City *city)
{
    std::vector<std::vector<Entity *>> &grid = city->getGrid();

    // Get the tax rates from the city
    int residentialTaxRate = city->getResidentialTax();
    int economicTaxRate = city->getEconomicTax();

    // Loop through the grid to collect taxes
    for (const auto &row : grid)
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr)
            {
                // Check if the entity is a ResidentialBuilding
                if (ResidentialBuilding *residential = dynamic_cast<ResidentialBuilding *>(entity))
                {
                    totalResidentialTax += (residential->getRevenue() * residentialTaxRate) / 100;
                }
                // Check if the entity is an EconomicBuilding
                else if (EconomicBuilding *economic = dynamic_cast<EconomicBuilding *>(entity))
                {
                    totalEconomicTax += (economic->getRevenue() * economicTaxRate) / 100;
                }
            }
        }
    }
}
