#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Observer.h"
#include "utils/ConfigManager.h"
#include <cmath>

class ResidentialBuilding : public Building, public Observer
{
private:
    const float RATE_OF_CHANGE = 1;
    float globalAirport;
    float localAirport;
    float globalBusStop;
    float localBusStop;
    float globalTrainStation;
    float localTrainStation;
    float globalFactory;
    float localFactory;
    float globalShoppingMall;
    float localShoppingMall;
    float globalOffice;
    float localOffice;
    float globalHospital;
    float localHospital;
    float globalPoliceStation;
    float localPoliceStation;
    float globalSchool;
    float localSchool;
    float globalAmenity;
    float localAmenity;
    float globalUtility;
    float localUtility;
    float globalIndustry;
    float localIndustry;
    float satisfaction;

    void updateEntity(SatisfactionConfig sc, float &local, float &global, Entity* entity);
    void reduceByChange(float &value);
    void reduceByChangeWithNegativeExtreme(SatisfactionConfig sc, float &value);
public:
    ResidentialBuilding();
    ResidentialBuilding(EntityConfig ec, Size size, int xPos, int yPos);
    virtual ~ResidentialBuilding();

    void update();
    virtual Entity* clone() = 0;
    void reset();
    void calculateSatisfaction();
    float getSatisfaction();

    void updateAirport(Entity* entity);
    void updateBusStop(Entity* entity);
    void updateTrainStation(Entity* entity);
    void updateFactory(Entity* entity);
    void updateShoppingMall(Entity* entity);
    void updateOffice(Entity* entity);
    void updateHospital(Entity* entity);
    void updatePoliceStation(Entity* entity);
    void updateSchool(Entity* entity);
    void updateAmenity(Entity* entity);
    void updateUtility(Entity* entity);
    void updateIndustry(Entity* entity);
    
};

#endif // RESIDENTIALBUILDING_H
