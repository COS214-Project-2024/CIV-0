#include "PopulationVisitor.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"
#include <unordered_set>

PopulationVisitor::PopulationVisitor()
    : totalPopulationCapacity(0), housePopulationCapacity(0), apartmentPopulationCapacity(0) {}

void PopulationVisitor::visit(City *city)
{
    totalWaterConsumption = 0;
    totalElectricityConsumption = 0;
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
                    totalPopulationCapacity += residential->getCapacity();

                    // Check for specific residential building types
                    if (dynamic_cast<House *>(residential))
                    {
                        housePopulationCapacity += residential->getCapacity();
                    }
                    else if (dynamic_cast<Apartment *>(residential))
                    {
                        apartmentPopulationCapacity += residential->getCapacity();
                    }
                }

                // Check if the entity is an Entity
                Entity *theEntity = dynamic_cast<Entity *>(entity);
                if(theEntity)
                {
                    totalWaterConsumption += theEntity->getWaterConsumption();
                    totalElectricityConsumption += theEntity->getElectricityConsumption();
                }
            }
        }
    }
}

int PopulationVisitor::getTotalPopulationCapacity() const
{
    return totalPopulationCapacity;
}

int PopulationVisitor::getHousePopulationCapacity() const
{
    return housePopulationCapacity;
}

int PopulationVisitor::getApartmentPopulationCapacity() const
{
    return apartmentPopulationCapacity;
}


int PopulationVisitor::getTotalWaterConsumption() const
{
    return totalWaterConsumption;
}

int PopulationVisitor::getTotalElectricityConsumption() const
{
    return totalElectricityConsumption;
}
