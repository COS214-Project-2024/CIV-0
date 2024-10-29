#include "UtilityVisitor.h"
#include "city/City.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include <unordered_set>

UtilityVisitor::UtilityVisitor() : totalElectricity(0), totalWater(0), totalSewageHandled(0), totalWasteHandled(0) {}

UtilityVisitor::~UtilityVisitor() {}

void UtilityVisitor::visit(City *city)
{
    std::unordered_set<Entity*> visitedEntities;  // Track unique entities
    std::vector<std::vector<Entity *>> &grid = city->getGrid();

    // Iterate over the city grid to visit all utility entities
    for (auto &row : grid)
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr && visitedEntities.insert(entity).second)
            {
                if (Utility *utility = dynamic_cast<Utility *>(entity))
                {
                    // Collect output based on utility type
                    if (dynamic_cast<PowerPlant *>(utility))
                    {
                        totalElectricity += utility->getOutput();
                    }
                    else if (dynamic_cast<WaterSupply *>(utility))
                    {
                        totalWater += utility->getOutput();
                    }
                    else if (SewageSystem *sewageSystem = dynamic_cast<SewageSystem *>(utility))
                    {
                        totalSewageHandled += sewageSystem->getOutput(); // Get sewage handling capacity
                    }
                    else if (WasteManagement *wasteManagement = dynamic_cast<WasteManagement *>(utility))
                    {
                        totalWasteHandled += wasteManagement->getOutput(); // Get waste handling capacity
                    }
                }
            }
        }
    }
}

// Getters
int UtilityVisitor::getTotalElectricity() const { return totalElectricity; }
int UtilityVisitor::getTotalWater() const { return totalWater; }
int UtilityVisitor::getTotalSewageHandled() const { return totalSewageHandled; }
int UtilityVisitor::getTotalWasteHandled() const { return totalWasteHandled; }
