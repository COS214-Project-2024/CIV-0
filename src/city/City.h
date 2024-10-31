#ifndef CITY_H
#define CITY_H

#include "visitors/base/CityVisitor.h"
#include <vector>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time

class Entity;
class CityIterator;

class City
{
private:
    std::vector<std::vector<Entity *>> grid;
    int width;
    int height;
    float satisfaction;
    int money;
    int wood;
    int stone;
    int concrete;
    int populationCapacity;
    int population;
    int electricityProduction;
    int electricityConsumption;
    int waterProduction;
    int waterConsumption;
    int wasteProduction;
    int wasteConsumption;
    int sewageProduction;
    int sewageConsumption;
    int residentialTax;
    int economicTax;

    // Private constructor and destructor to enforce the singleton pattern
    City();
    ~City();

    /**
     * @brief Creates a road entity at a random position within the city grid.
     */
    void createRandomRoad();

public:
    /**
     * @brief Returns a pointer to the singleton instance of City.
     * @return A pointer to the City instance.
     */
    static City *instance();

    // Deleted copy constructor and assignment operator to enforce singleton pattern
    City(const City &) = delete;
    City &operator=(const City &) = delete;

    Entity *getEntity(int x, int y);
    void addEntity(Entity *entity);
    std::vector<std::vector<Entity *>> &getGrid(); // Provide access to the grid

    void deleteEntity(int x, int y);

    // Accept method for the visitor pattern
    void accept(CityVisitor &visitor);

    // Getters
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

    // Setters
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

    void reset();
    void reset(int width, int height);

    CityIterator createIterator();

    /**
     * @brief Generates a random city layout with roads and buildings.
     */
    void generateRandomCity();
};

#endif // CITY_H
