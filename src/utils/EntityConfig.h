#ifndef ENTITYCONFIG_H
#define ENTITYCONFIG_H

#include "Cost.h"
#include "EntityType.h" // Include EntityType
#include "Size.h"       // Include Size
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
  EntityType entityType; // Add entity type
  Size size;             // Add size

  // Default constructor
  EntityConfig()
      : cost(), electricityConsumption(0), waterConsumption(0), symbol(""),
        effectRadius(0), localEffectStrength(0), globalEffectStrength(0),
        width(1), height(1), revenue(0), buildTime(0),
        entityType(EntityType::UNKNOWN), size(Size::SMALL) {}

  // Constructor to initialize all properties, including entityType and size
  EntityConfig(const Cost &cost, int electricity, int water, const std::string &symbol,
               int radius, int localEffect, int globalEffect, int width, int height,
               int revenue, int buildTime, EntityType entityType, Size size)
      : cost(cost), electricityConsumption(electricity), waterConsumption(water), symbol(symbol),
        effectRadius(radius), localEffectStrength(localEffect), globalEffectStrength(globalEffect),
        width(width), height(height), revenue(revenue), buildTime(buildTime),
        entityType(entityType), size(size) {}
};

#endif // ENTITYCONFIG_H
