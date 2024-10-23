#include "City.h"

City::City() {}
City::~City() {}

City &City::instance()
{
    static City instance; // Singleton instance
    return instance;
}

std::vector<std::vector<Entity *>> &City::getGrid()
{
    return grid;
}

// Implement the accept method
void City::accept(CityVisitor &visitor)
{
    visitor.visit(this); // Passing the City object to the visitor
}