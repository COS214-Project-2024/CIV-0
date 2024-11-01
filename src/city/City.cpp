#include "City.h"
#include "entities/base/Entity.h"
#include "iterators/city/CityIterator.h"
#include "iterators/building/amenity/AmenityIterator.h"
#include "iterators/building/residential/ResidentialBuildingIterator.h"
#include "iterators/building/economic/EconomicBuildingIterator.h"
#include "iterators/building/service/ServiceBuildingIterator.h"
#include "iterators/building/BuildingIterator.h"
#include "iterators/building/BuildingIterator.h"
#include "iterators/industry/IndustryIterator.h"
#include "iterators/industry/ConcreteProducerIterator.h"
#include "iterators/industry/StoneProducerIterator.h"
#include "iterators/industry/WoodProducerIterator.h"
#include "iterators/road/RoadIterator.h"
#include "iterators/transport/TransportIterator.h"
#include "iterators/utility/UtilityIterator.h"
#include "iterators/utility/SewageSystemIterator.h"
#include "iterators/utility/PowerPlantIterator.h"
#include "iterators/utility/WasteManagementIterator.h"
#include "iterators/utility/WaterSupplyIterator.h"
#include "entities/road/Road.h"
#include "entities/road/Road.h"
#include <iostream>
#include <algorithm> // for std::fill
#include "policies/water/LowWaterPolicy.h"
#include "policies/water/NormalWaterPolicy.h"
#include "policies/water/HighWaterPolicy.h"
#include "policies/electricity/LowElectricityPolicy.h"
#include "policies/electricity/NormalElectricityPolicy.h"
#include "policies/electricity/HighElectricityPolicy.h"

City::City() : width(50), height(50), // Set default values
               satisfaction(0), money(500), wood(500), stone(500), concrete(500),
               populationCapacity(0), population(0), electricityProduction(0),
               electricityConsumption(0), waterProduction(0), waterConsumption(0),
               residentialTax(25), economicTax(25)
{
    // Initialize grid with default width and height
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    grid.resize(height, std::vector<Entity *>(width, nullptr));
}

City::~City()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j] != nullptr)
            {
                // delete grid[i][j];    // Free memory
                deleteEntity(i, j);
                grid[i][j] = nullptr; // Set to nullptr to avoid double-deletion
            }
        }
    }

    if (waterPolicy != nullptr)
    {
        delete waterPolicy;
        waterPolicy = nullptr;
    }

    if (electricityPolicy != nullptr)
    {
        delete electricityPolicy;
        electricityPolicy = nullptr;
    }
}

void City::reset(int newWidth, int newHeight)
{
    // Reset scalar properties to default values
    satisfaction = 100.0f;
    money = 200000;
    wood = 200000;
    stone = 200000;
    concrete = 200000;
    populationCapacity = 0;
    population = 0;
    electricityProduction = 0;
    electricityConsumption = 0;
    waterProduction = 0;
    waterConsumption = 0;
    residentialTax = 25;
    economicTax = 25;

    // Delete existing entities and clear the grid
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (grid[i][j] != nullptr)
            {
                // delete grid[i][j];    // Free memory
                deleteEntity(i, j);
                grid[i][j] = nullptr; // Set to nullptr to avoid double-deletion
            }
        }
    }

    if (waterPolicy != nullptr)
    {
        delete waterPolicy;
        waterPolicy = nullptr;
    }

    if (electricityPolicy != nullptr)
    {
        delete electricityPolicy;
        electricityPolicy = nullptr;
    }

    // Resize grid based on new dimensions
    width = newWidth;
    height = newHeight;
    grid.clear();
    grid.resize(height, std::vector<Entity *>(width, nullptr));
}

void City::reset()
{
    reset(width, height); // Use current dimensions to reset
}

/**
 * @brief Returns a pointer to the singleton instance of City.
 * @return A pointer to the City instance.
 */
City *City::instance()
{
    // Correct singleton pattern implementation with a static object
    static City instance; // Static instance of City
    return &instance;     // Return the address of the static instance
}

std::vector<std::vector<Entity *>> &City::getGrid()
{
    return grid;
}

Entity *City::getEntity(int x, int y)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        return grid[x][y];
    }
    return nullptr; // Return nullptr if coordinates are out of bounds
}

void City::deleteEntity(int x, int y)
{
    if (x >= 0 && x < width && y >= 0 && y < height && grid[x][y] != nullptr)
    {
        Entity *e = getEntity(x, y);

        for (int i = e->getXPosition(); i < e->getXPosition() + e->getWidth(); i++)
        {
            for (int j = e->getYPosition() - e->getHeight() + 1; j <= e->getYPosition(); j++)
            {
                grid[i][j] = nullptr;
            }
        }

        delete e;
    }
}

// Implement the accept method
void City::accept(CityVisitor &visitor)
{
    visitor.visit(this); // Passing the City object to the visitor
}

// NOTE - THIS DOES NOT CHECK IF IT IS OVERLAPPING WITH ANOTHER ENTITY
void City::addEntity(Entity *entity)
{
    int x = entity->getXPosition();
    int y = entity->getYPosition();

    if (x >= 0 && x + entity->getWidth() <= width && y - entity->getHeight() + 1 >= 0 && y < height)
    {
        for (int i = x; i < x + entity->getWidth(); i++)
        {
            for (int j = y - entity->getHeight() + 1; j <= y; j++)
            {
                grid[i][j] = entity;
            }
        }
    }
}

void City::displayCity() const
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            Entity *entity = grid[x][y];
            if (entity != nullptr)
            {
                std::cout << entity->getSymbol() << " ";
            }
            else
            {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

void City::createRandomRoad()
{
    int x = rand() % width;  // Random x coordinate within grid bounds
    int y = rand() % height; // Random y coordinate within grid bounds

    // Delete any existing entity at the random position
    if (grid[x][y] != nullptr)
    {
        delete grid[x][y];
    }

    grid[x][y] = new Road(ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL), Size::SMALL, x, y); // Place a new Road entity at the random position
}
// Getters
int City::getWidth() const { return width; }
int City::getHeight() const { return height; }
float City::getSatisfaction() const { return satisfaction; }
int City::getMoney() const { return money; }
int City::getWood() const { return wood; }
int City::getStone() const { return stone; }
int City::getConcrete() const { return concrete; }
int City::getPopulationCapacity() const { return populationCapacity; }
int City::getPopulation() const { return population; }
int City::getElectricityProduction() const { return electricityProduction; }
int City::getElectricityConsumption() const { return electricityConsumption; }
int City::getWaterProduction() const { return waterProduction; }
int City::getWaterConsumption() const { return waterConsumption; }
int City::getWasteProduction() const { return wasteProduction; }
int City::getWasteConsumption() const { return wasteConsumption; }
int City::getSewageProduction() const { return sewageProduction; }
int City::getSewageConsumption() const { return sewageConsumption; }
int City::getResidentialTax() const { return residentialTax; }
int City::getEconomicTax() const { return economicTax; }
/**
 * @brief Retrieves the current water usage policy for the city.
 *
 * @return Pointer to the current WaterPolicy.
 */
WaterPolicy *City::getWaterPolicy() const
{
    return waterPolicy;
}

/**
 * @brief Retrieves the current electricity usage policy for the city.
 *
 * @return Pointer to the current ElectricityPolicy.
 */
ElectricityPolicy *City::getElectricityPolicy() const
{
    return electricityPolicy;
}

// Setters
void City::setWidth(int width) { this->width = width; }
void City::setHeight(int height) { this->height = height; }
void City::setSatisfaction(float satisfaction) { this->satisfaction = satisfaction; }
void City::setMoney(int money) { this->money = money; }
void City::setWood(int wood) { this->wood = wood; }
void City::setStone(int stone) { this->stone = stone; }
void City::setConcrete(int concrete) { this->concrete = concrete; }
void City::setPopulationCapacity(int populationCapacity) { this->populationCapacity = populationCapacity; }
void City::setPopulation(int population) { this->population = population; }
void City::setElectricityProduction(int electricityProduction) { this->electricityProduction = electricityProduction; }
void City::setElectricityConsumption(int electricityConsumption) { this->electricityConsumption = electricityConsumption; }
void City::setWaterProduction(int waterProduction) { this->waterProduction = waterProduction; }
void City::setWaterConsumption(int waterConsumption) { this->waterConsumption = waterConsumption; }
void City::setWasteProduction(int wasteProduction) { this->wasteProduction = wasteProduction; }
void City::setWasteConsumption(int wasteConsumption) { this->wasteConsumption = wasteConsumption; }
void City::setSewageProduction(int sewageProduction) { this->sewageProduction = sewageProduction; }
void City::setSewageConsumption(int sewageConsumption) { this->sewageConsumption = sewageConsumption; }
void City::setResidentialTax(int residentialTax) { this->residentialTax = residentialTax; }
void City::setEconomicTax(int economicTax) { this->economicTax = economicTax; }
/**
 * @brief Sets the water usage policy for the city.
 *
 * @param policyType The type of water policy to enact.
 */
void City::setWaterPolicy(PolicyType policyType)
{
    if (waterPolicy != nullptr)
    {
        delete waterPolicy;
    }

    if (policyType == PolicyType::LOW_WATER_POLICY)
    {
        waterPolicy = new LowWaterPolicy();
    }
    else if (policyType == PolicyType::NORMAL_WATER_POLICY)
    {
        waterPolicy = new NormalWaterPolicy();
    }
    else if (policyType == PolicyType::HIGH_WATER_POLICY)
    {
        waterPolicy = new HighWaterPolicy();
    }
}

/**
 * @brief Sets the electricity usage policy for the city.
 *
 * @param policyType The type of electricity policy to enact.
 */
void City::setElectricityPolicy(PolicyType policyType)
{
    if (electricityPolicy != nullptr)
    {
        delete electricityPolicy;
    }

    if (policyType == PolicyType::LOW_ELECTRICITY_POLICY)
    {
        electricityPolicy = new LowElectricityPolicy();
    }
    else if (policyType == PolicyType::NORMAL_ELECTRICITY_POLICY)
    {
        electricityPolicy = new NormalElectricityPolicy();
    }
    else if (policyType == PolicyType::HIGH_ELECTRICITY_POLICY)
    {
        electricityPolicy = new HighElectricityPolicy();
    }
}

Iterator *City::createCityIterator(bool unique)
{
    return new CityIterator(grid, unique);
}

Iterator *City::createBuildingIterator(bool unique)
{
    return new BuildingIterator(this->grid);
}

Iterator *City::createUtilityIterator(bool unique)
{
    return new UtilityIterator(this->grid);
}

Iterator *City::createRoadIterator(bool unique)
{
    return new RoadIterator(this->grid);
}

Iterator *City::createTransportIterator(bool unique)
{
    return new TransportIterator(this->grid);
}

Iterator *City::createEconomicBuildingIterator(bool unique)
{
    return new EconomicBuildingIterator(this->grid);
}

Iterator *City::createResidentialBuildingIterator(bool unique)
{
    return new ResidentialBuildingIterator(this->grid);
}

Iterator *City::createServiceBuildingIterator(bool unique)
{
    return new ServiceBuildingIterator(this->grid);
}

Iterator *City::createAmenityIterator(bool unique)
{
    return new AmenityIterator(this->grid);
}

Iterator *City::createPowerPlantIterator(bool unique)
{
    return new PowerPlantIterator(this->grid);
}

Iterator *City::createWaterSupplyIterator(bool unique)
{
    return new WaterSupplyIterator(this->grid);
}

Iterator *City::createWasteManagementIterator(bool unique)
{
    return new WasteManagementIterator(this->grid);
}

Iterator *City::createSewageSystemIterator(bool unique)
{
    return new SewageSystemIterator(this->grid);
}

Iterator *City::createConcreteProducerIterator(bool unique)
{
    return new ConcreteProducerIterator(this->grid);
}

Iterator *City::createStoneProducerIterator(bool unique)
{
    return new StoneProducerIterator(this->grid);
}

Iterator *City::createWoodProducerIterator(bool unique)
{
    return new WoodProducerIterator(this->grid);
}
