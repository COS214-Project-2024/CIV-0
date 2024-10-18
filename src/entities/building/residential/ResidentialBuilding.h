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

    void updateEntity(SatisfactionConfig sc, float &local, float &global);
    void reduceByChange(float &value);
    void reduceByChangeWithNegativeExtreme(SatisfactionConfig sc, float &value);
public:
    ResidentialBuilding();
    ResidentialBuilding(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~ResidentialBuilding();

    void update();
    virtual Entity* clone() = 0;
    void reset();
    void calculateSatisfaction();
    float getSatisfaction();

    void updateAirport();
    void updateBusStop();
    void updateTrainStation();
    void updateFactory();
    void updateShoppingMall();
    void updateOffice();
    void updateHospital();
    void updatePoliceStation();
    void updateSchool();
    void updateAmenity();
    void updateUtility();
    void updateIndustry();
    
};

#endif // RESIDENTIALBUILDING_H
