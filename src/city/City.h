#ifndef CITY_H
#define CITY_H

#include "entities/base/Entity.h"
#include "visitors/base/CityVisitor.h"
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

    City();
    ~City();

public:
    static City &instance();

    City(const City &) = delete;
    City &operator=(const City &) = delete;

    Entity *getEntity(int x, int y);
    std::vector<std::vector<Entity *>> &getGrid(); // Provide access to the grid

    // Accept method for the visitor pattern
    void accept(CityVisitor &visitor);
};

#endif // CITY_H
