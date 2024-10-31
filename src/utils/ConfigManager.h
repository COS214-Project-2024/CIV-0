#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <map>
#include <optional>
#include "EntityType.h"
#include "Size.h"
#include "EntityConfig.h"
#include "SatisfactionConfig.h"

class ConfigManager
{
public:
    static EntityConfig getEntityConfig(EntityType entityType, Size size)
    {
        static ConfigManager instance;
        auto key = std::make_pair(entityType, size);
        return instance.entityConfigTable.at(key); // Use at to safely access the map
    }

    static SatisfactionConfig getSatisfactionConfig(EntityType entityType)
    {
        static ConfigManager instance;
        return instance.satisfactionConfigTable.at(entityType); // Use `at` to safely access the map
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
        entityConfigTable.emplace(std::make_pair(EntityType::HOUSE, Size::SMALL),
                                  EntityConfig(Cost(100, 50, 20, 10), 2, 1, "△", 3, 5, 1, 2, 2, 500, 3, EntityType::HOUSE, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::HOUSE, Size::MEDIUM),
                                  EntityConfig(Cost(200, 80, 30, 20), 5, 2, "△", 5, 10, 2, 3, 3, 1000, 3, EntityType::HOUSE, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::HOUSE, Size::LARGE),
                                  EntityConfig(Cost(300, 120, 50, 30), 7, 3, "△", 7, 15, 3, 4, 4, 1500, 3, EntityType::HOUSE, Size::LARGE));

        // Apartments
        entityConfigTable.emplace(std::make_pair(EntityType::APARTMENT, Size::SMALL),
                                  EntityConfig(Cost(150, 70, 40, 15), 3, 1, "A", 4, 6, 2, 3, 3, 600, 3, EntityType::APARTMENT, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::APARTMENT, Size::MEDIUM),
                                  EntityConfig(Cost(300, 140, 60, 30), 6, 3, "A", 6, 12, 4, 4, 4, 1200, 3, EntityType::APARTMENT, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::APARTMENT, Size::LARGE),
                                  EntityConfig(Cost(450, 210, 90, 45), 9, 4, "A", 9, 18, 6, 5, 5, 1800, 3, EntityType::APARTMENT, Size::LARGE));

        // Factories
        entityConfigTable.emplace(std::make_pair(EntityType::FACTORY, Size::SMALL),
                                  EntityConfig(Cost(500, 200, 100, 50), 20, 10, "▣", 10, -5, -10, 4, 4, 3000, 3, EntityType::FACTORY, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::FACTORY, Size::MEDIUM),
                                  EntityConfig(Cost(700, 300, 150, 80), 30, 15, "▣", 15, -10, -15, 6, 6, 5000, 3, EntityType::FACTORY, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::FACTORY, Size::LARGE),
                                  EntityConfig(Cost(1000, 400, 200, 100), 50, 20, "▣", 20, -20, -25, 8, 8, 10000, 3, EntityType::FACTORY, Size::LARGE));

        // Offices
        entityConfigTable.emplace(std::make_pair(EntityType::OFFICE, Size::SMALL),
                                  EntityConfig(Cost(400, 100, 60, 20), 10, 4, "₪", 5, 5, 2, 3, 3, 2000, 3, EntityType::OFFICE, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::OFFICE, Size::MEDIUM),
                                  EntityConfig(Cost(600, 150, 90, 30), 20, 8, "₪", 7, 10, 4, 4, 4, 4000, 3, EntityType::OFFICE, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::OFFICE, Size::LARGE),
                                  EntityConfig(Cost(900, 250, 120, 40), 30, 12, "₪", 10, 15, 6, 5, 5, 6000, 3, EntityType::OFFICE, Size::LARGE));

        // Shopping Malls
        entityConfigTable.emplace(std::make_pair(EntityType::SHOPPINGMALL, Size::SMALL),
                                  EntityConfig(Cost(800, 300, 150, 100), 40, 25, "S", 8, 15, 10, 5, 5, 8000, 3, EntityType::SHOPPINGMALL, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::SHOPPINGMALL, Size::MEDIUM),
                                  EntityConfig(Cost(1500, 500, 300, 200), 60, 35, "S", 12, 20, 15, 8, 8, 15000, 3, EntityType::SHOPPINGMALL, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::SHOPPINGMALL, Size::LARGE),
                                  EntityConfig(Cost(3000, 1000, 500, 400), 100, 50, "S", 15, 30, 20, 10, 10, 30000, 3, EntityType::SHOPPINGMALL, Size::LARGE));

        // Schools
        entityConfigTable.emplace(std::make_pair(EntityType::SCHOOL, Size::SMALL),
                                  EntityConfig(Cost(600, 200, 80, 50), 10, 5, "✐", 6, 8, 4, 4, 4, 2500, 3, EntityType::SCHOOL, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::SCHOOL, Size::MEDIUM),
                                  EntityConfig(Cost(1200, 400, 160, 100), 20, 10, "✐", 10, 12, 6, 6, 6, 5000, 3, EntityType::SCHOOL, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::SCHOOL, Size::LARGE),
                                  EntityConfig(Cost(1800, 600, 240, 150), 30, 15, "✐", 15, 18, 8, 8, 8, 7500, 3, EntityType::SCHOOL, Size::LARGE));

        // Hospitals
        entityConfigTable.emplace(std::make_pair(EntityType::HOSPITAL, Size::SMALL),
                                  EntityConfig(Cost(1000, 400, 200, 150), 25, 10, "✙", 8, 10, 6, 6, 6, 10000, 3, EntityType::HOSPITAL, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::HOSPITAL, Size::MEDIUM),
                                  EntityConfig(Cost(2000, 600, 300, 200), 35, 15, "✙", 12, 15, 10, 8, 8, 15000, 3, EntityType::HOSPITAL, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::HOSPITAL, Size::LARGE),
                                  EntityConfig(Cost(4000, 1000, 500, 300), 50, 20, "✙", 20, 25, 15, 10, 10, 30000, 3, EntityType::HOSPITAL, Size::LARGE));

        // Police Stations
        entityConfigTable.emplace(std::make_pair(EntityType::POLICESTATION, Size::SMALL),
                                  EntityConfig(Cost(700, 250, 120, 70), 8, 5, "☎", 6, 10, 4, 4, 4, 4000, 3, EntityType::POLICESTATION, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::POLICESTATION, Size::MEDIUM),
                                  EntityConfig(Cost(1200, 400, 200, 100), 12, 7, "☎", 10, 15, 6, 6, 6, 6000, 3, EntityType::POLICESTATION, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::POLICESTATION, Size::LARGE),
                                  EntityConfig(Cost(2000, 600, 300, 150), 18, 10, "☎", 15, 20, 8, 8, 8, 10000, 3, EntityType::POLICESTATION, Size::LARGE));

        // Parks
        entityConfigTable.emplace(std::make_pair(EntityType::PARK, Size::SMALL),
                                  EntityConfig(Cost(300, 100, 50, 25), 0, 0, "⍋", 3, 12, 8, 4, 4, 0, 2, EntityType::PARK, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::PARK, Size::MEDIUM),
                                  EntityConfig(Cost(600, 200, 100, 50), 0, 0, "⍋", 6, 18, 10, 6, 6, 0, 2, EntityType::PARK, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::PARK, Size::LARGE),
                                  EntityConfig(Cost(1200, 400, 200, 100), 0, 0, "⍋", 10, 25, 15, 8, 8, 0, 2, EntityType::PARK, Size::LARGE));

        // Monuments
        entityConfigTable.emplace(std::make_pair(EntityType::MONUMENT, Size::SMALL),
                                  EntityConfig(Cost(2000, 700, 400, 300), 0, 0, "♝", 12, 25, 18, 5, 5, 0, 5, EntityType::MONUMENT, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::MONUMENT, Size::MEDIUM),
                                  EntityConfig(Cost(3500, 1000, 600, 400), 0, 0, "♝", 18, 30, 22, 7, 7, 0, 5, EntityType::MONUMENT, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::MONUMENT, Size::LARGE),
                                  EntityConfig(Cost(6000, 1500, 900, 600), 0, 0, "♝", 25, 35, 28, 10, 10, 0, 5, EntityType::MONUMENT, Size::LARGE));

        // Theater
        entityConfigTable.emplace(std::make_pair(EntityType::THEATER, Size::SMALL),
                                  EntityConfig(Cost(1200, 400, 200, 150), 20, 10, "♫", 8, 12, 10, 6, 6, 5000, 3, EntityType::THEATER, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::THEATER, Size::MEDIUM),
                                  EntityConfig(Cost(2500, 800, 500, 300), 30, 15, "♫", 12, 20, 15, 8, 8, 10000, 3, EntityType::THEATER, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::THEATER, Size::LARGE),
                                  EntityConfig(Cost(4500, 1200, 700, 500), 45, 25, "♫", 18, 30, 20, 10, 10, 15000, 3, EntityType::THEATER, Size::LARGE));

        // Power Plants
        entityConfigTable.emplace(std::make_pair(EntityType::POWERPLANT, Size::SMALL),
                                  EntityConfig(Cost(3000, 1200, 700, 500), 200, 0, "↯", 15, -10, -15, 6, 6, 0, 6, EntityType::POWERPLANT, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::POWERPLANT, Size::MEDIUM),
                                  EntityConfig(Cost(5500, 2000, 1200, 800), 400, 0, "↯", 20, -20, -30, 8, 8, 0, 8, EntityType::POWERPLANT, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::POWERPLANT, Size::LARGE),
                                  EntityConfig(Cost(8000, 3000, 2000, 1200), 600, 0, "↯", 30, -30, -45, 10, 10, 0, 10, EntityType::POWERPLANT, Size::LARGE));

        // Water Supply Systems
        entityConfigTable.emplace(std::make_pair(EntityType::WATERSUPPLY, Size::SMALL),
                                  EntityConfig(Cost(2000, 900, 400, 250), 0, 50, "❣", 10, 8, 5, 5, 5, 0, 4, EntityType::WATERSUPPLY, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::WATERSUPPLY, Size::MEDIUM),
                                  EntityConfig(Cost(3500, 1200, 600, 400), 0, 100, "❣", 15, 15, 10, 7, 7, 0, 6, EntityType::WATERSUPPLY, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::WATERSUPPLY, Size::LARGE),
                                  EntityConfig(Cost(5000, 2000, 1000, 700), 0, 200, "❣", 20, 25, 15, 10, 10, 0, 8, EntityType::WATERSUPPLY, Size::LARGE));

        // Waste Management
        entityConfigTable.emplace(std::make_pair(EntityType::WASTEMANAGMENT, Size::SMALL),
                                  EntityConfig(Cost(1000, 500, 300, 150), 10, 5, "☣", 5, -5, -5, 5, 5, 0, 3, EntityType::WASTEMANAGMENT, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::WASTEMANAGMENT, Size::MEDIUM),
                                  EntityConfig(Cost(2000, 900, 500, 300), 15, 10, "☣", 8, -10, -10, 7, 7, 0, 5, EntityType::WASTEMANAGMENT, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::WASTEMANAGMENT, Size::LARGE),
                                  EntityConfig(Cost(3500, 1500, 800, 600), 25, 15, "☣", 12, -15, -15, 9, 9, 0, 7, EntityType::WASTEMANAGMENT, Size::LARGE));

        // Sewage Systems
        entityConfigTable.emplace(std::make_pair(EntityType::SEWAGESYSTEM, Size::SMALL),
                                  EntityConfig(Cost(1500, 700, 400, 250), 5, 10, "♨", 6, -6, -8, 5, 5, 0, 4, EntityType::SEWAGESYSTEM, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::SEWAGESYSTEM, Size::MEDIUM),
                                  EntityConfig(Cost(2500, 1100, 600, 400), 10, 15, "♨", 8, -10, -12, 7, 7, 0, 6, EntityType::SEWAGESYSTEM, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::SEWAGESYSTEM, Size::LARGE),
                                  EntityConfig(Cost(4000, 1500, 1000, 800), 20, 25, "♨", 12, -15, -20, 10, 10, 0, 8, EntityType::SEWAGESYSTEM, Size::LARGE));

        // Stone Producer
        entityConfigTable.emplace(std::make_pair(EntityType::STONEPRODUCER, Size::SMALL),
                                  EntityConfig(Cost(1200, 600, 300, 200), 15, 0, "⛏", 6, 8, 5, 4, 4, 200, 3, EntityType::STONEPRODUCER, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::STONEPRODUCER, Size::MEDIUM),
                                  EntityConfig(Cost(2000, 1000, 500, 400), 30, 0, "⛏", 10, 15, 10, 6, 6, 400, 3, EntityType::STONEPRODUCER, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::STONEPRODUCER, Size::LARGE),
                                  EntityConfig(Cost(3500, 1500, 800, 600), 50, 0, "⛏", 15, 25, 20, 8, 8, 700, 3, EntityType::STONEPRODUCER, Size::LARGE));

        // Wood Producer
        entityConfigTable.emplace(std::make_pair(EntityType::WOODPRODUCER, Size::SMALL),
                                  EntityConfig(Cost(1000, 500, 250, 150), 10, 5, "W", 5, 8, 5, 4, 4, 300, 3, EntityType::WOODPRODUCER, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::WOODPRODUCER, Size::MEDIUM),
                                  EntityConfig(Cost(1800, 900, 450, 300), 20, 10, "W", 8, 12, 10, 6, 6, 500, 3, EntityType::WOODPRODUCER, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::WOODPRODUCER, Size::LARGE),
                                  EntityConfig(Cost(3000, 1500, 750, 500), 40, 15, "W", 12, 18, 15, 8, 8, 800, 3, EntityType::WOODPRODUCER, Size::LARGE));

        // Concrete Producer
        entityConfigTable.emplace(std::make_pair(EntityType::CONCRETEPRODUCER, Size::SMALL),
                                  EntityConfig(Cost(1400, 700, 350, 200), 20, 5, "┲", 6, 10, 5, 4, 4, 250, 4, EntityType::CONCRETEPRODUCER, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::CONCRETEPRODUCER, Size::MEDIUM),
                                  EntityConfig(Cost(2500, 1200, 600, 400), 35, 10, "┲", 9, 18, 10, 6, 6, 600, 4, EntityType::CONCRETEPRODUCER, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::CONCRETEPRODUCER, Size::LARGE),
                                  EntityConfig(Cost(4000, 2000, 1000, 700), 60, 15, "┲", 12, 25, 15, 8, 8, 1000, 4, EntityType::CONCRETEPRODUCER, Size::LARGE));

        // Road
        entityConfigTable.emplace(std::make_pair(EntityType::ROAD, Size::SMALL),
                                  EntityConfig(Cost(50, 10, 5, 0), 0, 0, "█", 1, 0, 0, 1, 1, 0, 1, EntityType::ROAD, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::ROAD, Size::MEDIUM),
                                  EntityConfig(Cost(100, 20, 10, 0), 0, 0, "█", 1, 0, 0, 1, 1, 0, 1, EntityType::ROAD, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::ROAD, Size::LARGE),
                                  EntityConfig(Cost(200, 30, 15, 0), 0, 0, "█", 1, 0, 0, 1, 1, 0, 1, EntityType::ROAD, Size::LARGE));

        // Airport
        entityConfigTable.emplace(std::make_pair(EntityType::AIRPORT, Size::SMALL),
                                  EntityConfig(Cost(10000, 4000, 2000, 1000), 100, 50, "✈", 20, -15, -10, 10, 10, 0, 10, EntityType::AIRPORT, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::AIRPORT, Size::MEDIUM),
                                  EntityConfig(Cost(15000, 6000, 3000, 1500), 200, 100, "✈", 30, -20, -15, 12, 12, 0, 15, EntityType::AIRPORT, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::AIRPORT, Size::LARGE),
                                  EntityConfig(Cost(25000, 10000, 5000, 3000), 400, 150, "✈", 40, -30, -20, 15, 15, 0, 20, EntityType::AIRPORT, Size::LARGE));

        // BusStop
        entityConfigTable.emplace(std::make_pair(EntityType::BUSSTOP, Size::SMALL),
                                  EntityConfig(Cost(100, 20, 10, 5), 0, 0, "Ⓑ", 3, 5, 3, 2, 2, 0, 1, EntityType::BUSSTOP, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::BUSSTOP, Size::MEDIUM),
                                  EntityConfig(Cost(200, 40, 20, 10), 0, 0, "Ⓑ", 4, 8, 5, 3, 3, 0, 1, EntityType::BUSSTOP, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::BUSSTOP, Size::LARGE),
                                  EntityConfig(Cost(500, 100, 50, 25), 0, 0, "Ⓑ", 5, 12, 8, 4, 4, 0, 1, EntityType::BUSSTOP, Size::LARGE));

        // TrainStation
        entityConfigTable.emplace(std::make_pair(EntityType::TRAINSTATION, Size::SMALL),
                                  EntityConfig(Cost(1500, 600, 300, 200), 15, 0, "Ⓣ", 10, 8, 5, 5, 5, 0, 4, EntityType::TRAINSTATION, Size::SMALL));
        entityConfigTable.emplace(std::make_pair(EntityType::TRAINSTATION, Size::MEDIUM),
                                  EntityConfig(Cost(3000, 1200, 600, 400), 30, 0, "Ⓣ", 15, 15, 10, 7, 7, 0, 6, EntityType::TRAINSTATION, Size::MEDIUM));
        entityConfigTable.emplace(std::make_pair(EntityType::TRAINSTATION, Size::LARGE),
                                  EntityConfig(Cost(6000, 2400, 1200, 800), 50, 0, "Ⓣ", 20, 25, 15, 10, 10, 0, 8, EntityType::TRAINSTATION, Size::LARGE));
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
        satisfactionConfigTable.emplace(EntityType::POWERPLANT, SatisfactionConfig(-2.0f, 2.0f, -25.0f, 0.0f));

        // Water Supply
        satisfactionConfigTable.emplace(EntityType::WATERSUPPLY, SatisfactionConfig(-2.0f, -2.0f, -25.0f, 0.0f));

        // Waste Managment
        satisfactionConfigTable.emplace(EntityType::WASTEMANAGMENT, SatisfactionConfig(-2.0f, 2.0f, -25.0f, 0.0f));

        // Sewage System
        satisfactionConfigTable.emplace(EntityType::SEWAGESYSTEM, SatisfactionConfig(-2.0f, 2.0f, -25.0f, 0.0f));

        // Wood Producer
        satisfactionConfigTable.emplace(EntityType::WOODPRODUCER, SatisfactionConfig(-2.0f, 2.0f, -25.0f, 0.0f));

        // Stone Producer
        satisfactionConfigTable.emplace(EntityType::STONEPRODUCER, SatisfactionConfig(-2.0f, 2.0f, -25.0f, 0.0f));

        // Concrete Producer
        satisfactionConfigTable.emplace(EntityType::CONCRETEPRODUCER, SatisfactionConfig(-2.0f, 2.0f, -25.0f, 0.0f));

        // Airport
        satisfactionConfigTable.emplace(EntityType::AIRPORT, SatisfactionConfig(-2.0f, 2.0f, -15.0f, 5.0f));

        // Bus Stop
        satisfactionConfigTable.emplace(EntityType::BUSSTOP, SatisfactionConfig(2.0f, 2.0f, 10.0f, 2.0f));

        // Train Station
        satisfactionConfigTable.emplace(EntityType::TRAINSTATION, SatisfactionConfig(2.0f, 2.0f, 10.0f, 2.0f));

        // Factory
        satisfactionConfigTable.emplace(EntityType::FACTORY, SatisfactionConfig(-2.0f, 2.0f, -15.0f, 10.0f));

        // Shopping Mall
        satisfactionConfigTable.emplace(EntityType::SHOPPINGMALL, SatisfactionConfig(2.0f, 2.0f, 3.0f, 10.0f));

        // Office
        satisfactionConfigTable.emplace(EntityType::OFFICE, SatisfactionConfig(-2.0f, 2.0f, -10.0f, 10.0f));
    }
};

#endif // CONFIGMANAGER_H
