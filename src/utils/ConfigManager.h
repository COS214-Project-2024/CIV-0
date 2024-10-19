#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <map>
#include "EntityType.h"
#include "Size.h"
#include "EntityConfig.h"
#include "SatisfactionConfig.h"

class ConfigManager
{
public:
    // Public static method to get the entity configuration for a given type and size
    static EntityConfig getEntityConfig(EntityType entityType, Size size)
    {
        static ConfigManager instance;
        auto key = std::make_pair(entityType, size);
        return instance.entityConfigTable.at(key); // Use `at` to safely access the map
    }

private:
    std::map<std::pair<EntityType, Size>, EntityConfig> entityConfigTable;
    std::map<EntityType, SatisfactionConfig> satisfactionConfigTable;

    // Private constructor to initialize the configurations
    ConfigManager()
    {
        initializeEntityConfig();
        initializeSatisfactionConfig();
    }

    // Method to initialize the configuration map with reasonable values for each entity
    void initializeEntityConfig()
    {
        // EntityConfig(Cost(money, wood, stone, concrete), electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, buildTime)

        // Houses
        entityConfigTable.emplace(std::make_pair(EntityType::HOUSE, Size::SMALL), EntityConfig(Cost(100, 50, 20, 10), 2, 1, "H", 3, 5, 1, 2, 2, 500, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::HOUSE, Size::MEDIUM), EntityConfig(Cost(200, 80, 30, 20), 5, 2, "H", 5, 10, 2, 3, 3, 1000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::HOUSE, Size::LARGE), EntityConfig(Cost(300, 120, 50, 30), 7, 3, "H", 7, 15, 3, 4, 4, 1500, 3));

        // Apartments
        entityConfigTable.emplace(std::make_pair(EntityType::APARTMENT, Size::SMALL), EntityConfig(Cost(150, 70, 40, 15), 3, 1, "A", 4, 6, 2, 3, 3, 600, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::APARTMENT, Size::MEDIUM), EntityConfig(Cost(300, 140, 60, 30), 6, 3, "A", 6, 12, 4, 4, 4, 1200, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::APARTMENT, Size::LARGE), EntityConfig(Cost(450, 210, 90, 45), 9, 4, "A", 9, 18, 6, 5, 5, 1800, 3));

        // Factories
        entityConfigTable.emplace(std::make_pair(EntityType::FACTORY, Size::SMALL), EntityConfig(Cost(500, 200, 100, 50), 20, 10, "F", 10, -5, -10, 4, 4, 3000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::FACTORY, Size::MEDIUM), EntityConfig(Cost(700, 300, 150, 80), 30, 15, "F", 15, -10, -15, 6, 6, 5000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::FACTORY, Size::LARGE), EntityConfig(Cost(1000, 400, 200, 100), 50, 20, "F", 20, -20, -25, 8, 8, 10000, 3));

        // Offices
        entityConfigTable.emplace(std::make_pair(EntityType::OFFICE, Size::SMALL), EntityConfig(Cost(400, 100, 60, 20), 10, 4, "O", 5, 5, 2, 3, 3, 2000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::OFFICE, Size::MEDIUM), EntityConfig(Cost(600, 150, 90, 30), 20, 8, "O", 7, 10, 4, 4, 4, 4000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::OFFICE, Size::LARGE), EntityConfig(Cost(900, 250, 120, 40), 30, 12, "O", 10, 15, 6, 5, 5, 6000, 3));

        // Shopping Malls
        entityConfigTable.emplace(std::make_pair(EntityType::SHOPPINGMALL, Size::SMALL), EntityConfig(Cost(800, 300, 150, 100), 40, 25, "M", 8, 15, 10, 5, 5, 8000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::SHOPPINGMALL, Size::MEDIUM), EntityConfig(Cost(1500, 500, 300, 200), 60, 35, "M", 12, 20, 15, 8, 8, 15000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::SHOPPINGMALL, Size::LARGE), EntityConfig(Cost(3000, 1000, 500, 400), 100, 50, "M", 15, 30, 20, 10, 10, 30000, 3));

        // Schools
        entityConfigTable.emplace(std::make_pair(EntityType::SCHOOL, Size::SMALL), EntityConfig(Cost(600, 200, 80, 50), 10, 5, "S", 6, 8, 4, 4, 4, 2500, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::SCHOOL, Size::MEDIUM), EntityConfig(Cost(1200, 400, 160, 100), 20, 10, "S", 10, 12, 6, 6, 6, 5000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::SCHOOL, Size::LARGE), EntityConfig(Cost(1800, 600, 240, 150), 30, 15, "S", 15, 18, 8, 8, 8, 7500, 3));

        // Hospitals
        entityConfigTable.emplace(std::make_pair(EntityType::HOSPITAL, Size::SMALL), EntityConfig(Cost(1000, 400, 200, 150), 25, 10, "H", 8, 10, 6, 6, 6, 10000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::HOSPITAL, Size::MEDIUM), EntityConfig(Cost(2000, 600, 300, 200), 35, 15, "H", 12, 15, 10, 8, 8, 15000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::HOSPITAL, Size::LARGE), EntityConfig(Cost(4000, 1000, 500, 300), 50, 20, "H", 20, 25, 15, 10, 10, 30000, 3));

        // Police Stations
        entityConfigTable.emplace(std::make_pair(EntityType::POLICESTATION, Size::SMALL), EntityConfig(Cost(700, 250, 120, 70), 8, 5, "P", 6, 10, 4, 4, 4, 4000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::POLICESTATION, Size::MEDIUM), EntityConfig(Cost(1200, 400, 200, 100), 12, 7, "P", 10, 15, 6, 6, 6, 6000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::POLICESTATION, Size::LARGE), EntityConfig(Cost(2000, 600, 300, 150), 18, 10, "P", 15, 20, 8, 8, 8, 10000, 3));

        // Parks
        entityConfigTable.emplace(std::make_pair(EntityType::PARK, Size::SMALL), EntityConfig(Cost(100, 50, 20, 10), 0, 0, "P", 5, 10, 5, 3, 3, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::PARK, Size::MEDIUM), EntityConfig(Cost(200, 80, 30, 20), 0, 0, "P", 8, 15, 8, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::PARK, Size::LARGE), EntityConfig(Cost(400, 120, 50, 30), 0, 0, "P", 12, 20, 10, 7, 7, 0, 3));

        // Monuments
        entityConfigTable.emplace(std::make_pair(EntityType::MONUMENT, Size::SMALL), EntityConfig(Cost(1500, 500, 300, 200), 0, 0, "M", 10, 20, 15, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::MONUMENT, Size::MEDIUM), EntityConfig(Cost(3000, 800, 500, 300), 0, 0, "M", 15, 25, 20, 8, 8, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::MONUMENT, Size::LARGE), EntityConfig(Cost(5000, 1200, 700, 400), 0, 0, "M", 20, 30, 25, 10, 10, 0, 3));

        // Theater
        entityConfigTable.emplace(std::make_pair(EntityType::THEATER, Size::SMALL), EntityConfig(Cost(1000, 300, 150, 100), 15, 8, "T", 6, 10, 5, 5, 5, 4000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::THEATER, Size::MEDIUM), EntityConfig(Cost(2000, 500, 250, 150), 25, 12, "T", 10, 15, 8, 8, 8, 8000, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::THEATER, Size::LARGE), EntityConfig(Cost(3500, 800, 400, 250), 40, 20, "T", 15, 20, 12, 10, 10, 15000, 3));

        // Power Plants
        entityConfigTable.emplace(std::make_pair(EntityType::POWERPLANT, Size::SMALL), EntityConfig(Cost(2000, 800, 500, 300), 0, 0, "P", 20, -5, -10, 8, 8, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::POWERPLANT, Size::MEDIUM), EntityConfig(Cost(4000, 1200, 800, 500), 0, 0, "P", 25, -10, -15, 10, 10, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::POWERPLANT, Size::LARGE), EntityConfig(Cost(6000, 1600, 1000, 700), 0, 0, "P", 30, -15, -20, 12, 12, 0, 3));

        // Water Supply Systems
        entityConfigTable.emplace(std::make_pair(EntityType::WATERSUPPLY, Size::SMALL), EntityConfig(Cost(1500, 700, 300, 200), 10, 0, "W", 8, 5, 5, 6, 6, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::WATERSUPPLY, Size::MEDIUM), EntityConfig(Cost(2500, 900, 400, 300), 20, 0, "W", 12, 10, 8, 8, 8, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::WATERSUPPLY, Size::LARGE), EntityConfig(Cost(4000, 1200, 600, 400), 30, 0, "W", 15, 15, 12, 10, 10, 0, 3));

        // Waste Management
        entityConfigTable.emplace(std::make_pair(EntityType::WASTEMANAGMENT, Size::SMALL), EntityConfig(Cost(800, 400, 200, 100), 5, 2, "W", 5, 5, 3, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::WASTEMANAGMENT, Size::MEDIUM), EntityConfig(Cost(1200, 600, 300, 200), 10, 4, "W", 7, 7, 5, 7, 7, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::WASTEMANAGMENT, Size::LARGE), EntityConfig(Cost(1800, 800, 400, 300), 15, 6, "W", 10, 10, 7, 9, 9, 0, 3));

        // Sewage Systems
        entityConfigTable.emplace(std::make_pair(EntityType::SEWAGESYSTEM, Size::SMALL), EntityConfig(Cost(1000, 500, 200, 150), 8, 5, "S", 5, 6, 5, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::SEWAGESYSTEM, Size::MEDIUM), EntityConfig(Cost(1500, 800, 300, 200), 12, 8, "S", 8, 10, 7, 7, 7, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::SEWAGESYSTEM, Size::LARGE), EntityConfig(Cost(2500, 1000, 400, 300), 15, 10, "S", 10, 12, 10, 9, 9, 0, 3));

        // Stone Producer
        entityConfigTable.emplace(std::make_pair(EntityType::STONEPRODUCER, Size::SMALL), EntityConfig(Cost(1000, 500, 200, 150), 8, 5, "S", 5, 6, 5, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::STONEPRODUCER, Size::MEDIUM), EntityConfig(Cost(1500, 800, 300, 200), 12, 8, "S", 8, 10, 7, 7, 7, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::STONEPRODUCER, Size::LARGE), EntityConfig(Cost(2500, 1000, 400, 300), 15, 10, "S", 10, 12, 10, 9, 9, 0, 3));

        // Wood Producer
        entityConfigTable.emplace(std::make_pair(EntityType::WOODPRODUCER, Size::SMALL), EntityConfig(Cost(1000, 500, 200, 150), 8, 5, "W", 5, 6, 5, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::WOODPRODUCER, Size::MEDIUM), EntityConfig(Cost(1500, 800, 300, 200), 12, 8, "W", 8, 10, 7, 7, 7, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::WOODPRODUCER, Size::LARGE), EntityConfig(Cost(2500, 1000, 400, 300), 15, 10, "W", 10, 12, 10, 9, 9, 0, 3));

        // Concrete Producer
        entityConfigTable.emplace(std::make_pair(EntityType::CONCRETEPRODUCER, Size::SMALL), EntityConfig(Cost(1000, 500, 200, 150), 8, 5, "C", 5, 6, 5, 5, 5, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::CONCRETEPRODUCER, Size::MEDIUM), EntityConfig(Cost(1500, 800, 300, 200), 12, 8, "C", 8, 10, 7, 7, 7, 0, 3));
        entityConfigTable.emplace(std::make_pair(EntityType::CONCRETEPRODUCER, Size::LARGE), EntityConfig(Cost(2500, 1000, 400, 300), 15, 10, "C", 10, 12, 10, 9, 9, 0, 3));

        // Road
        entityConfigTable.emplace(std::make_pair(EntityType::ROAD, Size::SMALL), EntityConfig(Cost(10, 0, 0, 0), 0, 0, "█", 0, 0, 0, 1, 1, 0, 0));
        entityConfigTable.emplace(std::make_pair(EntityType::ROAD, Size::MEDIUM), EntityConfig(Cost(10, 0, 0, 0), 0, 0, "█", 0, 0, 0, 1, 1, 0, 0));
        entityConfigTable.emplace(std::make_pair(EntityType::ROAD, Size::LARGE), EntityConfig(Cost(10, 0, 0, 0), 0, 0, "█", 0, 0, 0, 1, 1, 0, 0));
    }

    void initializeSatisfactionConfig()
    {
        // SatisfactionConfig(localRate, globalRate, localExtreme, globalExtreme)

        // Hospital
        satisfactionConfigTable.emplace(EntityType::HOSPITAL, SatisfactionConfig(2.0f, 2.0f, 10.0f, 5.0f));

        // Police Station
        satisfactionConfigTable.emplace(EntityType::POLICESTATION, SatisfactionConfig(2.0f, 2.0f, 10.0f, 2.0f));

        // School
        satisfactionConfigTable.emplace(EntityType::SCHOOL, SatisfactionConfig(2.0f, 2.0f, 10.0f, 5.0f));

        // Park
        satisfactionConfigTable.emplace(EntityType::PARK, SatisfactionConfig(2.0f, 2.0f, 15.0f, 0.0f));

        // Monument
        satisfactionConfigTable.emplace(EntityType::MONUMENT, SatisfactionConfig(2.0f, 2.0f, 15.0f, 0.0f));

        // Theater
        satisfactionConfigTable.emplace(EntityType::THEATER, SatisfactionConfig(2.0f, 2.0f, 15.0f, 0.0f));

        // Power Plant
        satisfactionConfigTable.emplace(EntityType::POWERPLANT, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Water Supply
        satisfactionConfigTable.emplace(EntityType::WATERSUPPLY, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Waste Managment
        satisfactionConfigTable.emplace(EntityType::WASTEMANAGMENT, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Sewage System
        satisfactionConfigTable.emplace(EntityType::SEWAGESYSTEM, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Wood Producer
        satisfactionConfigTable.emplace(EntityType::WOODPRODUCER, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Stone Producer
        satisfactionConfigTable.emplace(EntityType::STONEPRODUCER, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Concrete Producer
        satisfactionConfigTable.emplace(EntityType::CONCRETEPRODUCER, SatisfactionConfig(2.0f, 2.0f, -25.0f, 0.0f));

        // Airport
        satisfactionConfigTable.emplace(EntityType::AIRPORT, SatisfactionConfig(2.0f, 2.0f, -15.0f, 5.0f));

        // Bus Stop
        satisfactionConfigTable.emplace(EntityType::BUSSTOP, SatisfactionConfig(2.0f, 2.0f, 10.0f, 2.0f));

        // Train Station
        satisfactionConfigTable.emplace(EntityType::BUSSTOP, SatisfactionConfig(2.0f, 2.0f, 10.0f, 2.0f));

        // Factory
        satisfactionConfigTable.emplace(EntityType::FACTORY, SatisfactionConfig(2.0f, 2.0f, -15.0f, 10.0f));

        // Shopping Mall
        satisfactionConfigTable.emplace(EntityType::SHOPPINGMALL, SatisfactionConfig(2.0f, 2.0f, 3.0f, 10.0f));

        // Office
        satisfactionConfigTable.emplace(EntityType::OFFICE, SatisfactionConfig(2.0f, 2.0f, -10.0f, 10.0f));
    }
};

#endif // CONFIGMANAGER_H
