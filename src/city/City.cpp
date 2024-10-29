#include "City.h"
#include "entities/base/Entity.h"
#include "iterators/city/CityIterator.h"
#include "entities/road/Road.h"
#include <algorithm> // for std::fill

City::City() : width(50), height(50), // Set default values
               satisfaction(0), money(10000), wood(1000), steel(1000), concrete(1000),
               populationCapacity(0), population(0), electricityProduction(0),
               electricityConsumption(0), waterProduction(0), waterConsumption(0),
               residentialTax(0), economicTax(0)
{
    // Initialize grid with default width and height
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    grid.resize(height, std::vector<Entity *>(width, nullptr));
    createRandomRoad();
}

City::~City()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (grid[i][j])
                delete grid[i][j];
        }
    }
}

void City::reset(int newWidth, int newHeight)
{
    // Reset scalar properties to default values
    satisfaction = 100.0f;
    money = 10000;
    wood = 1000;
    steel = 1000;
    concrete = 1000;
    populationCapacity = 0;
    population = 0;
    electricityProduction = 0;
    electricityConsumption = 0;
    waterProduction = 0;
    waterConsumption = 0;
    residentialTax = 0;
    economicTax = 0;

    // Delete existing entities and clear the grid
    for (auto &row : grid)
    {
        for (auto &entity : row)
        {
            delete entity;
            entity = nullptr;
        }
    }

    // Resize grid based on new dimensions
    width = newWidth;
    height = newHeight;
    grid.clear();
    grid.resize(height, std::vector<Entity *>(width, nullptr));

    createRandomRoad(); // Create a new random road upon reset
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

// Implement the accept method
void City::accept(CityVisitor &visitor)
{
    visitor.visit(this); // Passing the City object to the visitor
}

void City::addEntity(Entity *entity)
{
    int x = entity->getXPosition();
    int y = entity->getYPosition();
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        grid[x][y] = entity;
    }
}

CityIterator City::createIterator()
{
    return CityIterator(grid); // Pass the grid to the iterator
}

void City::createRandomRoad()
{
    int x = rand() % width;  // Random x coordinate within grid bounds
    int y = rand() % height; // Random y coordinate within grid bounds

    // Delete any existing entity at the random position
    if (grid[y][x] != nullptr)
    {
        delete grid[y][x];
    }

    grid[y][x] = new Road(ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL), Size::SMALL, x, y); // Place a new Road entity at the random position
}

// Getters
int City::getWidth() const { return width; }
int City::getHeight() const { return height; }
float City::getSatisfaction() const { return satisfaction; }
int City::getMoney() const { return money; }
int City::getWood() const { return wood; }
int City::getSteel() const { return steel; }
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

// Setters
void City::setWidth(int width) { this->width = width; }
void City::setHeight(int height) { this->height = height; }
void City::setSatisfaction(float satisfaction) { this->satisfaction = satisfaction; }
void City::setMoney(int money) { this->money = money; }
void City::setWood(int wood) { this->wood = wood; }
void City::setSteel(int steel) { this->steel = steel; }
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