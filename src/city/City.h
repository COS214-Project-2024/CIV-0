#ifndef CITY_H
#define CITY_H

#include "entities/base/Entity.h"
#include <vector>

class City
{
private:
    std::vector<std::vector<Entity*>> grid;
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
    Entity* getEntity(int x, int y);
};

#endif // CITY_H
