#ifndef CITY_H
#define CITY_H

#include "entities/base/Entity.h"
#include <vector>

class City
{
private:
    std::vector<std::vector<Entity *>> grid;
    float satisfaction;
    int money;
    int wood;
    int steel;
    int concrete;
    int populationCapacity;
    int population;
    int electricityProduction;
    int electricityConsumption;
    int waterProduction;
    int waterConsumption;
    int residentialTax;
    int economicTax;

    // Private constructor and destructor to enforce the singleton pattern
    City();
    ~City();

public:
    /**
     * @brief Returns a pointer to the singleton instance of City.
     * @return A pointer to the City instance.
     */
    static City *instance();

    // Deleted copy constructor and assignment operator to enforce singleton pattern
    City(const City &) = delete;
    City &operator=(const City &) = delete;

    // Example getter for an entity in the city grid
    Entity *getEntity(int x, int y);
};

#endif // CITY_H
