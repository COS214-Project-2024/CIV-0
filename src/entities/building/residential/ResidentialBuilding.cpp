#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding() {}
ResidentialBuilding::~ResidentialBuilding() {}

ResidentialBuilding::ResidentialBuilding(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Building(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{
    reset();
}

//HMMMMMMMMMMM - idk this is needed but It looks like html code :(
void ResidentialBuilding::reset()
{
    globalAirport = ConfigManager::getSatisfactionConfig(EntityType::AIRPORT).globalExtreme;
    localAirport = 0;
    globalBusStop = ConfigManager::getSatisfactionConfig(EntityType::BUSSTOP).globalExtreme;
    localBusStop = ConfigManager::getSatisfactionConfig(EntityType::BUSSTOP).localExtreme;
    globalTrainStation = ConfigManager::getSatisfactionConfig(EntityType::TRAINSTATION).globalExtreme;
    localTrainStation = ConfigManager::getSatisfactionConfig(EntityType::TRAINSTATION).localExtreme;
    globalFactory = ConfigManager::getSatisfactionConfig(EntityType::FACTORY).globalExtreme;
    localFactory = 0;
    globalShoppingMall = ConfigManager::getSatisfactionConfig(EntityType::SHOPPINGMALL).globalExtreme;
    localShoppingMall = ConfigManager::getSatisfactionConfig(EntityType::SHOPPINGMALL).localExtreme;
    globalOffice = ConfigManager::getSatisfactionConfig(EntityType::OFFICE).globalExtreme;
    localOffice = 0;
    globalHospital = ConfigManager::getSatisfactionConfig(EntityType::HOSPITAL).globalExtreme;
    localHospital = ConfigManager::getSatisfactionConfig(EntityType::HOSPITAL).localExtreme;
    globalPoliceStation = ConfigManager::getSatisfactionConfig(EntityType::POLICESTATION).globalExtreme;
    localPoliceStation = ConfigManager::getSatisfactionConfig(EntityType::POLICESTATION).localExtreme;
    globalSchool = ConfigManager::getSatisfactionConfig(EntityType::SCHOOL).globalExtreme;
    localSchool = ConfigManager::getSatisfactionConfig(EntityType::SCHOOL).localExtreme;
    globalAmenity = ConfigManager::getSatisfactionConfig(EntityType::PARK).globalExtreme;
    localAmenity = ConfigManager::getSatisfactionConfig(EntityType::PARK).localExtreme;
    globalUtility = ConfigManager::getSatisfactionConfig(EntityType::POWERPLANT).globalExtreme;
    localUtility = 0;
    globalIndustry = ConfigManager::getSatisfactionConfig(EntityType::WOODPRODUCER).globalExtreme;
    localIndustry = 0;
    satisfaction = 100;
}

//Don't touch my addition tower
void ResidentialBuilding::calculateSatisfaction()
{
    satisfaction = 
    globalAirport
    + localAirport
    + globalBusStop
    + localBusStop
    + globalTrainStation
    + localTrainStation
    + globalFactory
    + localFactory
    + globalShoppingMall
    + localShoppingMall
    + globalOffice
    + localOffice
    + globalHospital
    + localHospital
    + globalPoliceStation
    + localPoliceStation
    + globalSchool
    + localSchool
    + globalAmenity
    + localAmenity
    + globalUtility
    + localUtility
    + globalIndustry
    + localIndustry;

    if(satisfaction<0)
    {
        satisfaction = 0;
    }
    if(satisfaction>100)
    {
        satisfaction = 100;
    }
}

float ResidentialBuilding::getSatisfaction()
{
    return satisfaction;
}

//this is beutiful
void ResidentialBuilding::updateAirport(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::AIRPORT), localAirport, globalAirport, entity);
}

void ResidentialBuilding::updateBusStop(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::BUSSTOP), localBusStop, globalBusStop, entity);
}

void ResidentialBuilding::updateTrainStation(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::TRAINSTATION), localTrainStation, globalTrainStation, entity);
}

void ResidentialBuilding::updateFactory(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::FACTORY), localFactory, globalFactory, entity);
}

void ResidentialBuilding::updateShoppingMall(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::SHOPPINGMALL), localShoppingMall, globalShoppingMall, entity);
}

void ResidentialBuilding::updateOffice(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::OFFICE), localOffice, globalOffice, entity);
}

void ResidentialBuilding::updateHospital(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::HOSPITAL), localHospital, globalHospital, entity);
}

void ResidentialBuilding::updatePoliceStation(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::POLICESTATION), localPoliceStation, globalPoliceStation, entity);
}

void ResidentialBuilding::updateSchool(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::SCHOOL), localSchool, globalSchool, entity);
}

void ResidentialBuilding::updateAmenity(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::PARK), localAmenity, globalAmenity, entity);
}

void ResidentialBuilding::updateUtility(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::POWERPLANT), localUtility, globalUtility, entity);
}

void ResidentialBuilding::updateIndustry(Entity* entity)
{
    updateEntity(ConfigManager::getSatisfactionConfig(EntityType::WOODPRODUCER), localIndustry, globalIndustry, entity);
}

void ResidentialBuilding::updateEntity(SatisfactionConfig sc, float &local, float &global, Entity* entity)
{
    if(isWithinEffectRadius(entity))
    {
        local += sc.localRate;
    }
    global += sc.globalRate;

    if(abs(local)>abs(sc.localExtreme))
    {
        local = sc.localExtreme;
    }
    if(abs(global)>abs(sc.globalExtreme))
    {
        global = sc.globalExtreme;
    }
}

//hey idk man. I've given up. I had an elegent solution for the code above this but now idk what to do. Maybe you can fix it. I give up. It works that's all that matters
void ResidentialBuilding::update()
{
    reduceByChange(globalAirport);
    reduceByChangeWithNegativeExtreme(ConfigManager::getSatisfactionConfig(EntityType::AIRPORT), localAirport);
    reduceByChange(globalBusStop);
    reduceByChange(localBusStop);
    reduceByChange(globalTrainStation);
    reduceByChange(localTrainStation);
    reduceByChange(globalFactory);
    reduceByChangeWithNegativeExtreme(ConfigManager::getSatisfactionConfig(EntityType::FACTORY), localFactory);
    reduceByChange(globalShoppingMall);
    reduceByChange(localShoppingMall);
    reduceByChange(globalOffice);
    reduceByChangeWithNegativeExtreme(ConfigManager::getSatisfactionConfig(EntityType::OFFICE), localOffice);
    reduceByChange(globalHospital);
    reduceByChange(localHospital);
    reduceByChange(globalPoliceStation);
    reduceByChange(localPoliceStation);
    reduceByChange(globalSchool);
    reduceByChange(localSchool);
    reduceByChange(globalAmenity);
    reduceByChange(localAmenity);
    reduceByChange(globalUtility);
    reduceByChangeWithNegativeExtreme(ConfigManager::getSatisfactionConfig(EntityType::POWERPLANT), localUtility);
    reduceByChange(globalIndustry);
    reduceByChangeWithNegativeExtreme(ConfigManager::getSatisfactionConfig(EntityType::WOODPRODUCER), localIndustry);
}

void ResidentialBuilding::reduceByChange(float &value)
{
    value -=RATE_OF_CHANGE;
    if(value<0)
    {
        value = 0;
    }
}

void ResidentialBuilding::reduceByChangeWithNegativeExtreme(SatisfactionConfig sc, float &value)
{
    value -=RATE_OF_CHANGE;
    if(value<sc.localExtreme)
    {
        value = sc.localExtreme;
    }
}