#include "ResourceVisitor.h"
#include "city/City.h"
#include <unordered_set>

ResourceVisitor::ResourceVisitor()
    : totalWood(0), totalConcrete(0), totalStone(0) {}

ResourceVisitor::~ResourceVisitor() {}

void ResourceVisitor::visit(City *city)
{
    totalWood = 0;
    totalStone = 0;
    totalConcrete = 0;
    
    std::unordered_set<Entity*> visitedEntities;  // Track unique entities
    std::vector<std::vector<Entity *>> &grid = city->getGrid();

    // Iterate over the grid and dynamically cast entities
    for (const auto &row : grid)
    {
        for (Entity *entity : row)
        {
            if (entity != nullptr && visitedEntities.insert(entity).second)
            {
                // Dynamic cast to ConcreteProducer
                if (ConcreteProducer *concreteProducer = dynamic_cast<ConcreteProducer *>(entity))
                {
                    totalConcrete += concreteProducer->getOutput();
                }
                // Dynamic cast to StoneProducer
                else if (StoneProducer *stoneProducer = dynamic_cast<StoneProducer *>(entity))
                {
                    totalStone += stoneProducer->getOutput();
                }
                // Dynamic cast to WoodProducer
                else if (WoodProducer *woodProducer = dynamic_cast<WoodProducer *>(entity))
                {
                    totalWood += woodProducer->getOutput();
                }
            }
        }
    }
}