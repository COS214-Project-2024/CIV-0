#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "entities/industry/base/Industry.h"
#include "iterators/industry/ConcreteProducerIterator.h"
#include "iterators/industry/StoneProducerIterator.h"
#include "iterators/industry/IndustryIterator.h"
#include "iterators/industry/WoodProducerIterator.h"
#include "city/City.h"
#include "factory/industry/IndustryFactory.h"
#include "visitors/resource/ResourceVisitor.h"
#include "visitors/tax/TaxCalculationVisitor.h"

class ResourceManager
{
public:
    /** @brief Construct a new Resource Manager object. */
    ResourceManager();
    
    /** @brief Destroy the Resource Manager object. */
    ~ResourceManager();
    
    /** 
     * @brief Build an industry of a specified type and size at given coordinates.
     * @param type Type of the industry to build.
     * @param size Size of the industry.
     * @param x X-coordinate for placement.
     * @param y Y-coordinate for placement.
     */
    void buildIndustry(EntityType type, Size size, int x, int y);
    
    /** @brief Calculate the total money made in the city. */
    int calculateMoneyMade();
    
    /** @brief Calculate the total wood produced in the city. */
    int calculateWoodMade();
    
    /** @brief Calculate the total stone produced in the city. */
    int calculateStoneMade();
    
    /** @brief Calculate the total concrete produced in the city. */
    int calculateConcreteMade();
    
    /** @brief Get all industry buildings in the city. */
    std::vector<Industry*> getAllIndustryBuildings();
    
    /** @brief Get all concrete producer industries. */
    std::vector<Industry*> getAllConcreteProducers();
    
    /** @brief Get all stone producer industries. */
    std::vector<Industry*> getAllStoneProducers();
    
    /** @brief Get all wood producer industries. */
    std::vector<Industry*> getAllWoodProducers();
    
    /** 
     * @brief Check if the city can afford an upgrade for a given industry.
     * @param industry Pointer to the industry to check.
     * @return true if the upgrade can be afforded; false otherwise.
     */
    bool canAffordUpgrade(Industry* industry);
    
    /** 
     * @brief Upgrade the specified industry if possible.
     * @param industry Reference to the industry to upgrade.
     * @return true if the upgrade was successful; false otherwise.
     */
    bool upgrade(Industry*& industry);
};

#endif // RESOURCEMANAGER_H