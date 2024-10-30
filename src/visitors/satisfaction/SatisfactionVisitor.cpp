#include "SatisfactionVisitor.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include <unordered_set>

SatisfactionVisitor::SatisfactionVisitor() : totalSatisfaction(0), residentialCount(0) {}

void SatisfactionVisitor::visit(City *city)
{
    totalSatisfaction = 0;
    residentialCount = 0;
    std::unordered_set<Entity*> visitedEntities;  // Track unique entities
    std::vector<std::vector<Entity *>> &grid = city->getGrid();

    for (auto &row : city->getGrid())
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr && visitedEntities.insert(entity).second)
            {
                // Check if the entity is a ResidentialBuilding
                ResidentialBuilding *residential = dynamic_cast<ResidentialBuilding *>(entity);
                if (residential)
                {
                    // Accumulate satisfaction from residential buildings
                    residential->calculateSatisfaction(); // Ensure satisfaction is updated
                    totalSatisfaction += residential->getSatisfaction();
                    residentialCount++;
                }
            }
        }
    }
}

float SatisfactionVisitor::getAverageSatisfaction() const
{
    // Return average satisfaction if we have residential buildings
    return residentialCount > 0 ? totalSatisfaction / residentialCount : 0;
}

int SatisfactionVisitor::getResidentialCount() const
{
    return residentialCount;
}
