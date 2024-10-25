#include "PopulationVisitor.h"
#include "entities/building/residential/ResidentialBuilding.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"

PopulationVisitor::PopulationVisitor()
    : totalPopulationCapacity(0), housePopulationCapacity(0), apartmentPopulationCapacity(0) {}

void PopulationVisitor::visit(City *city)
{
    for (auto &row : city->getGrid())
    {
        for (Entity *entity : row)
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
