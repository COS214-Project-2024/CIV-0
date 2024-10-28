#include "SatisfactionVisitor.h"
#include "entities/building/residential/ResidentialBuilding.h"

SatisfactionVisitor::SatisfactionVisitor() : totalSatisfaction(0), residentialCount(0) {}

void SatisfactionVisitor::visit(City *city)
{
    for (auto &row : city->getGrid())
    {
        for (Entity *entity : row)
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

float SatisfactionVisitor::getAverageSatisfaction() const
{
    // Return average satisfaction if we have residential buildings
    return residentialCount > 0 ? totalSatisfaction / residentialCount : 0;
}

int SatisfactionVisitor::getResidentialCount() const
{
    return residentialCount;
}
