#ifndef ENTITYCONFIG_H
#define ENTITYCONFIG_H

#include "Cost.h"
#include <string>

struct EntityConfig
{
    Cost cost;
    int electricityConsumption;
    int waterConsumption;
    std::string symbol;
    int effectRadius;
    int localEffectStrength;
    int globalEffectStrength;
    int width;
    int height;
    int revenue;
    int buildTime;

    // Default constructor
    EntityConfig()
        : cost(), electricityConsumption(0), waterConsumption(0), symbol(""),
          effectRadius(0), localEffectStrength(0), globalEffectStrength(0),
          width(1), height(1), revenue(0), buildTime(0) {}

    // Constructor to initialize all properties
    EntityConfig(const Cost &cost, int electricity = 0, int water = 0, const std::string &symbol = "",
                 int radius = 0, int localEffect = 0, int globalEffect = 0, int width = 1, int height = 1, int revenue = 0, int buildTime = 0)
        : cost(cost), electricityConsumption(electricity), waterConsumption(water), symbol(symbol),
          effectRadius(radius), localEffectStrength(localEffect), globalEffectStrength(globalEffect),
          width(width), height(height), revenue(revenue), buildTime(buildTime) {}
};

#endif // ENTITYCONFIG_H
