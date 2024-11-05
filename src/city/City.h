/**
 * @file City.h
 * @brief Manages city entities and resources in the simulation.
 */

#ifndef CITY_H
#define CITY_H

#include "visitors/base/CityVisitor.h"
#include <vector>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time
#include "policies/water/WaterPolicy.h"
#include "policies/electricity/ElectricityPolicy.h"
#include "utils/PolicyType.h"

class Entity;
class Iterator;

/**
 * @class City
 * @brief Singleton class that represents and manages a simulated city with entities, resources, and policies.
 */
class City
{
private:
    std::vector<std::vector<Entity *>> grid; ///< 2D grid representing the layout of entities in the city.
    int width;                               ///< Width of the city grid.
    int height;                              ///< Height of the city grid.
    float satisfaction;                      ///< Overall satisfaction level of the city's population.
    int money;                               ///< Available money resource for the city.
    int wood;                                ///< Available wood resource for the city.
    int stone;                               ///< Available stone resource for the city.
    int concrete;                            ///< Available concrete resource for the city.
    int populationCapacity;                  ///< Total capacity for housing population in the city.
    int population;                          ///< Current population count.
    int electricityProduction;               ///< Current electricity production level.
    int electricityConsumption;              ///< Current electricity consumption level.
    int waterProduction;                     ///< Current water production level.
    int waterConsumption;                    ///< Current water consumption level.
    int wasteProduction;                     ///< Current waste production level.
    int wasteConsumption;                    ///< Current waste consumption level.
    int sewageProduction;                    ///< Current sewage production level.
    int sewageConsumption;                   ///< Current sewage consumption level.
    int residentialTax;                      ///< Residential tax rate.
    int economicTax;                         ///< Economic tax rate.
    std::string cityName;                    ///< The name of the city

    City();  ///< Private constructor for singleton pattern.
    ~City(); ///< Private destructor for singleton pattern.

    WaterPolicy *waterPolicy = nullptr;             ///< Pointer to the current water policy.
    ElectricityPolicy *electricityPolicy = nullptr; ///< Pointer to the current electricity policy.

public:
    /**
     * @brief Returns a pointer to the singleton instance of City.
     * @return A pointer to the City instance.
     */
    static City *instance();

    City(const City &) = delete;            ///< Deleted copy constructor for singleton pattern.
    City &operator=(const City &) = delete; ///< Deleted assignment operator for singleton pattern.

    /**
     * @brief Retrieves an entity at specified coordinates.
     * @param x X-coordinate on the grid.
     * @param y Y-coordinate on the grid.
     * @return Pointer to the Entity at the coordinates, or nullptr if empty.
     */
    Entity *getEntity(int x, int y);

    /**
     * @brief Adds an entity to the city grid.
     * @param entity Pointer to the Entity to be added.
     */
    void addEntity(Entity *entity);

    /**
     * @brief Provides access to the city grid.
     * @return A reference to the 2D grid of entities.
     */
    std::vector<std::vector<Entity *>> &getGrid();

    /**
     * @brief Deletes an entity at the specified coordinates.
     * @param x X-coordinate of the entity.
     * @param y Y-coordinate of the entity.
     */
    void deleteEntity(int x, int y);

    /**
     * @brief Accepts a visitor for the city (Visitor Pattern).
     * @param visitor The CityVisitor object.
     */
    void accept(CityVisitor &visitor);

    // Getters for city properties
    int getWidth() const;
    int getHeight() const;
    float getSatisfaction() const;
    int getMoney() const;
    int getWood() const;
    int getStone() const;
    int getConcrete() const;
    int getPopulationCapacity() const;
    int getPopulation() const;
    int getElectricityProduction() const;
    int getElectricityConsumption() const;
    int getWaterProduction() const;
    int getWaterConsumption() const;
    int getWasteProduction() const;
    int getWasteConsumption() const;
    int getSewageProduction() const;
    int getSewageConsumption() const;
    int getResidentialTax() const;
    int getEconomicTax() const;
    std::string getCityName() const;

    /**
     * @brief Gets the current water usage policy.
     * @return Pointer to the current water policy.
     */
    WaterPolicy *getWaterPolicy() const;

    /**
     * @brief Gets the current electricity usage policy.
     * @return Pointer to the current electricity policy.
     */
    ElectricityPolicy *getElectricityPolicy() const;

    // Setters for city properties
    void setWidth(int width);
    void setHeight(int height);
    void setSatisfaction(float satisfaction);
    void setMoney(int money);
    void setWood(int wood);
    void setStone(int stone);
    void setConcrete(int concrete);
    void setPopulationCapacity(int populationCapacity);
    void setPopulation(int population);
    void setElectricityProduction(int electricityProduction);
    void setElectricityConsumption(int electricityConsumption);
    void setWaterProduction(int waterProduction);
    void setWaterConsumption(int waterConsumption);
    void setWasteProduction(int wasteProduction);
    void setWasteConsumption(int wasteConsumption);
    void setSewageProduction(int sewageProduction);
    void setSewageConsumption(int sewageConsumption);
    void setResidentialTax(int residentialTax);
    void setEconomicTax(int economicTax);
    void setCityName(std::string name);

    /**
     * @brief Sets the water usage policy for the city.
     * @param policyType The type of water policy to enact.
     */
    void setWaterPolicy(PolicyType policyType);

    /**
     * @brief Sets the electricity usage policy for the city.
     * @param policyType The type of electricity policy to enact.
     */
    void setElectricityPolicy(PolicyType policyType);

    /**
     * @brief Resets the city with current or specified dimensions.
     * @param width Width of the new grid.
     * @param height Height of the new grid.
     */
    void reset(int width, int height);
    void reset();

    /**
     * @brief Creates various iterators for the city.
     * @param unique If true, creates unique iterators.
     * @return A pointer to the created iterator.
     */
    Iterator *createCityIterator(bool unique);
    Iterator *createBuildingIterator(bool unique);
    Iterator *createUtilityIterator(bool unique);
    Iterator *createIndustryIterator(bool unique);
    Iterator *createRoadIterator(bool unique);
    Iterator *createTransportIterator(bool unique);
    Iterator *createEconomicBuildingIterator(bool unique);
    Iterator *createResidentialBuildingIterator(bool unique);
    Iterator *createServiceBuildingIterator(bool unique);
    Iterator *createAmenityIterator(bool unique);
    Iterator *createPowerPlantIterator(bool unique);
    Iterator *createWaterSupplyIterator(bool unique);
    Iterator *createWasteManagementIterator(bool unique);
    Iterator *createSewageSystemIterator(bool unique);
    Iterator *createConcreteProducerIterator(bool unique);
    Iterator *createStoneProducerIterator(bool unique);
    Iterator *createWoodProducerIterator(bool unique);

    /**
     * @brief Creates a road entity at a random position within the city grid.
     */
    void createRandomRoad();

    /**
     * @brief Displays the city layout on the console.
     */
    void displayCity() const;
};

#endif // CITY_H