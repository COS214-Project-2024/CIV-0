#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

#include <string>
#include <stdexcept> // For std::invalid_argument

enum class EntityType
{
    BUSSTOP,
    TRAINSTATION,
    AIRPORT,
    OFFICE,
    SHOPPINGMALL,
    FACTORY,
    HOUSE,
    APARTMENT,
    HOSPITAL,
    POLICESTATION,
    SCHOOL,
    PARK,
    THEATER,
    MONUMENT,
    POWERPLANT,
    WATERSUPPLY,
    WASTEMANAGMENT,
    SEWAGESYSTEM,
    ROAD,
    WOODPRODUCER,
    STONEPRODUCER,
    CONCRETEPRODUCER,
};

/**
 * @brief Converts an EntityType enum to its corresponding string value.
 * @param type The EntityType enum value.
 * @return The string representation of the EntityType.
 */
inline std::string entityTypeToString(EntityType type)
{
    switch (type)
    {
    case EntityType::BUSSTOP:
        return "BUSSTOP";
    case EntityType::TRAINSTATION:
        return "TRAINSTATION";
    case EntityType::AIRPORT:
        return "AIRPORT";
    case EntityType::OFFICE:
        return "OFFICE";
    case EntityType::SHOPPINGMALL:
        return "SHOPPINGMALL";
    case EntityType::FACTORY:
        return "FACTORY";
    case EntityType::HOUSE:
        return "HOUSE";
    case EntityType::APARTMENT:
        return "APARTMENT";
    case EntityType::HOSPITAL:
        return "HOSPITAL";
    case EntityType::POLICESTATION:
        return "POLICESTATION";
    case EntityType::SCHOOL:
        return "SCHOOL";
    case EntityType::PARK:
        return "PARK";
    case EntityType::THEATER:
        return "THEATER";
    case EntityType::MONUMENT:
        return "MONUMENT";
    case EntityType::POWERPLANT:
        return "POWERPLANT";
    case EntityType::WATERSUPPLY:
        return "WATERSUPPLY";
    case EntityType::WASTEMANAGMENT:
        return "WASTEMANAGMENT";
    case EntityType::SEWAGESYSTEM:
        return "SEWAGESYSTEM";
    case EntityType::ROAD:
        return "ROAD";
    case EntityType::WOODPRODUCER:
        return "WOODPRODUCER";
    case EntityType::STONEPRODUCER:
        return "STONEPRODUCER";
    case EntityType::CONCRETEPRODUCER:
        return "CONCRETEPRODUCER";
    default:
        return "Unknown Entity";
    }
}

/**
 * @brief Converts a string to its corresponding EntityType enum value.
 * @param typeStr The string representation of the EntityType.
 * @return The corresponding EntityType enum value.
 * @throws std::invalid_argument if the string does not match any enum value.
 */
inline EntityType stringToEntityType(const std::string &typeStr)
{
    if (typeStr == "BUSSTOP")
        return EntityType::BUSSTOP;
    else if (typeStr == "TRAINSTATION")
        return EntityType::TRAINSTATION;
    else if (typeStr == "AIRPORT")
        return EntityType::AIRPORT;
    else if (typeStr == "OFFICE")
        return EntityType::OFFICE;
    else if (typeStr == "SHOPPINGMALL")
        return EntityType::SHOPPINGMALL;
    else if (typeStr == "FACTORY")
        return EntityType::FACTORY;
    else if (typeStr == "HOUSE")
        return EntityType::HOUSE;
    else if (typeStr == "APARTMENT")
        return EntityType::APARTMENT;
    else if (typeStr == "HOSPITAL")
        return EntityType::HOSPITAL;
    else if (typeStr == "POLICESTATION")
        return EntityType::POLICESTATION;
    else if (typeStr == "SCHOOL")
        return EntityType::SCHOOL;
    else if (typeStr == "PARK")
        return EntityType::PARK;
    else if (typeStr == "THEATER")
        return EntityType::THEATER;
    else if (typeStr == "MONUMENT")
        return EntityType::MONUMENT;
    else if (typeStr == "POWERPLANT")
        return EntityType::POWERPLANT;
    else if (typeStr == "WATERSUPPLY")
        return EntityType::WATERSUPPLY;
    else if (typeStr == "WASTEMANAGMENT")
        return EntityType::WASTEMANAGMENT;
    else if (typeStr == "SEWAGESYSTEM")
        return EntityType::SEWAGESYSTEM;
    else if (typeStr == "ROAD")
        return EntityType::ROAD;
    else if (typeStr == "WOODPRODUCER")
        return EntityType::WOODPRODUCER;
    else if (typeStr == "STONEPRODUCER")
        return EntityType::STONEPRODUCER;
    else if (typeStr == "CONCRETEPRODUCER")
        return EntityType::CONCRETEPRODUCER;
    else
        throw std::invalid_argument("Invalid entity type string: " + typeStr);
}

#endif // ENTITYTYPE_H
