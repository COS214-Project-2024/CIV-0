#include "City.h"
#include "entities/base/Entity.h"
#include <algorithm> // for std::fill

City::City() : width(50), height(50), // Set default values
               satisfaction(0), money(0), wood(0), stone(0), concrete(0),
               populationCapacity(0), population(0), electricityProduction(0),
               electricityConsumption(0), waterProduction(0), waterConsumption(0),
               residentialTax(0), economicTax(0)
{
    // Initialize grid with default width and height
    grid.resize(height, std::vector<Entity *>(width, nullptr));
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

void City::reset()
{
    // Reset scalar properties to default values
    satisfaction = 0.0f;
    money = 0;
    wood = 0;
    stone = 0;
    concrete = 0;
    populationCapacity = 0;
    population = 0;
    electricityProduction = 0;
    electricityConsumption = 0;
    waterProduction = 0;
    waterConsumption = 0;
    residentialTax = 0;
    economicTax = 0;

    // Safely delete and nullify all entities in the grid
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (grid[i][j]!=nullptr)
            {
                delete grid[i][j];    // Free memory
                grid[i][j] = nullptr; // Set to nullptr to avoid double-deletion
            }
        }
    }

    // Resize and reinitialize grid with nullptr entities
    grid.clear();
    grid.resize(height, std::vector<Entity *>(width, nullptr));
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
    if (x >= 0 && x < width && y >= 0 && y < height && grid[x][y]!=nullptr)
    {
        delete grid[x][y];
    }
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