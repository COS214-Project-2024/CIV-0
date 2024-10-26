#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "entities/building/base/Building.h"
#include "utils/ConfigManager.h"
#include <cmath>

/**
 * @class ResidentialBuilding
 * @brief Represents a residential building entity within the game.
 *
 * The ResidentialBuilding class handles properties and behaviors specific to residential
 * structures, such as satisfaction calculations based on proximity to various amenities,
 * utilities, and industries. It includes methods for updating these values based on nearby entities.
 */
class ResidentialBuilding : public Building
{
private:
    const float RATE_OF_CHANGE = 1;   ///< Rate at which satisfaction factors are adjusted.
    float globalAirport;              ///< Global effect of nearby airports.
    float localAirport;               ///< Local effect of nearby airports.
    float globalBusStop;              ///< Global effect of nearby bus stops.
    float localBusStop;               ///< Local effect of nearby bus stops.
    float globalTrainStation;         ///< Global effect of nearby train stations.
    float localTrainStation;          ///< Local effect of nearby train stations.
    float globalFactory;              ///< Global effect of nearby factories.
    float localFactory;               ///< Local effect of nearby factories.
    float globalShoppingMall;         ///< Global effect of nearby shopping malls.
    float localShoppingMall;          ///< Local effect of nearby shopping malls.
    float globalOffice;               ///< Global effect of nearby offices.
    float localOffice;                ///< Local effect of nearby offices.
    float globalHospital;             ///< Global effect of nearby hospitals.
    float localHospital;              ///< Local effect of nearby hospitals.
    float globalPoliceStation;        ///< Global effect of nearby police stations.
    float localPoliceStation;         ///< Local effect of nearby police stations.
    float globalSchool;               ///< Global effect of nearby schools.
    float localSchool;                ///< Local effect of nearby schools.
    float globalAmenity;              ///< Global effect of nearby amenities.
    float localAmenity;               ///< Local effect of nearby amenities.
    float globalUtility;              ///< Global effect of nearby utilities.
    float localUtility;               ///< Local effect of nearby utilities.
    float globalIndustry;             ///< Global effect of nearby industries.
    float localIndustry;              ///< Local effect of nearby industries.
    float satisfaction;               ///< Overall satisfaction level for the residential building.
    int capacity;                     ///< Occupant capacity of the residential building.

    /**
     * @brief Updates satisfaction factors for a specific entity type.
     *
     * @param sc Configuration settings for satisfaction.
     * @param local Local effect variable to update.
     * @param global Global effect variable to update.
     * @param entity Entity affecting the satisfaction.
     */
    void updateEntity(SatisfactionConfig sc, float &local, float &global, Entity* entity);

    /**
     * @brief Reduces a value by the set rate of change.
     *
     * @param value Reference to the value to be reduced.
     */
    void reduceByChange(float &value);

    /**
     * @brief Reduces a value by the set rate of change with negative limits.
     *
     * @param sc Configuration settings for satisfaction.
     * @param value Reference to the value to be reduced.
     */
    void reduceByChangeWithNegativeExtreme(SatisfactionConfig sc, float &value);

public:
    /**
     * @brief Default constructor for the ResidentialBuilding class.
     */
    ResidentialBuilding();

    /**
     * @brief Constructs a ResidentialBuilding with specified attributes.
     * 
     * @param ec Configuration containing resource consumption and other properties.
     * @param size Size of the residential building.
     * @param xPos X-coordinate position of the building.
     * @param yPos Y-coordinate position of the building.
     */
    ResidentialBuilding(EntityConfig ec, Size size, int xPos, int yPos);

    /**
     * @brief Copy constructor for the ResidentialBuilding class.
     * 
     * Creates a new ResidentialBuilding by copying the attributes of an existing ResidentialBuilding.
     * 
     * @param entity Pointer to the ResidentialBuilding object to be copied.
     */
    ResidentialBuilding(ResidentialBuilding* entity);

    /**
     * @brief Destructor for the ResidentialBuilding class.
     */
    virtual ~ResidentialBuilding();

    /**
     * @brief Updates the residential building's state.
     */
    void update();

    /**
     * @brief Creates a clone of the residential building.
     * 
     * @return A pointer to the cloned ResidentialBuilding.
     */
    virtual Entity* clone() = 0;

    /**
     * @brief Resets the satisfaction factors for the building.
     */
    void reset();

    /**
     * @brief Calculates the satisfaction level based on nearby entities.
     */
    void calculateSatisfaction();

    /**
     * @brief Gets the satisfaction level of the building.
     * 
     * @return The satisfaction level.
     */
    float getSatisfaction();

    /**
     * @brief Updates the effect of a nearby airport.
     * 
     * @param entity Entity representing the airport.
     */
    void updateAirport(Entity* entity);

    /**
     * @brief Updates the effect of a nearby bus stop.
     * 
     * @param entity Entity representing the bus stop.
     */
    void updateBusStop(Entity* entity);

    /**
     * @brief Updates the effect of a nearby train station.
     * 
     * @param entity Entity representing the train station.
     */
    void updateTrainStation(Entity* entity);

    /**
     * @brief Updates the effect of a nearby factory.
     * 
     * @param entity Entity representing the factory.
     */
    void updateFactory(Entity* entity);

    /**
     * @brief Updates the effect of a nearby shopping mall.
     * 
     * @param entity Entity representing the shopping mall.
     */
    void updateShoppingMall(Entity* entity);

    /**
     * @brief Updates the effect of a nearby office.
     * 
     * @param entity Entity representing the office.
     */
    void updateOffice(Entity* entity);

    /**
     * @brief Updates the effect of a nearby hospital.
     * 
     * @param entity Entity representing the hospital.
     */
    void updateHospital(Entity* entity);

    /**
     * @brief Updates the effect of a nearby police station.
     * 
     * @param entity Entity representing the police station.
     */
    void updatePoliceStation(Entity* entity);

    /**
     * @brief Updates the effect of a nearby school.
     * 
     * @param entity Entity representing the school.
     */
    void updateSchool(Entity* entity);

    /**
     * @brief Updates the effect of a nearby amenity.
     * 
     * @param entity Entity representing the amenity.
     */
    void updateAmenity(Entity* entity);

    /**
     * @brief Updates the effect of a nearby utility.
     * 
     * @param entity Entity representing the utility.
     */
    void updateUtility(Entity* entity);

    /**
     * @brief Updates the effect of a nearby industry.
     * 
     * @param entity Entity representing the industry.
     */
    void updateIndustry(Entity* entity);

    /**
     * @brief Gets the capacity of the residential building.
     * 
     * @return The occupant capacity.
     */
    int getCapacity();

    /**
     * @brief Sets the capacity of the residential building.
     * 
     * @param capacity The new capacity value.
     */
    void setCapacity(int capacity);
};

#endif // RESIDENTIALBUILDING_H
