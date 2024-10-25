#ifndef CITY_H
#define CITY_H

#include "visitors/base/CityVisitor.h"
#include <vector>

class Entity;

class City
{
private:
    std::vector<std::vector<Entity *>> grid;
    int width;
    int height;
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

    Entity *getEntity(int x, int y);
    void addEntity(Entity *entity);
    std::vector<std::vector<Entity *>> &getGrid(); // Provide access to the grid

    // Getters for tax rates
    int getResidentialTax() const; // Get residential tax rate
    int getEconomicTax() const;    // Get economic tax rate

    // Setters for tax rates
    void setResidentialTax(int taxRate); // Set residential tax rate
    void setEconomicTax(int taxRate);    // Set economic tax rate

    // Accept method for the visitor pattern
    void accept(CityVisitor &visitor);

    int getWidth();
    int getHeight();

    void reset();
};

#endif // CITY_H
