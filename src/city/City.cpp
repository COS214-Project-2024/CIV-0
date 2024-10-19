#include "City.h"

City::City() {}
City::~City() {}

City &City::instance()
{
    static City instance; //Singleton instance
    return instance;
}