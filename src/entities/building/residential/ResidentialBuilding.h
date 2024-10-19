#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "entities/building/base/Building.h"
#include "entities/base/Observer.h"

class ResidentialBuilding : public Building, public Observer
{
private:
    int globalTransport;
    int localTransport;
    int globalEconomicBuilding;
    int localEconomicBuilding;
    int globalHospital;
    int localHospital;
    int globalPoliceStation;
    int localPoliceStation;
    int globalSchool;
    int localSchool;
    int globalAmenity;
    int localAmenity;
    int globalUtility;
    int localUtility;
    float satisfaction;
public:
    ResidentialBuilding();
    ResidentialBuilding(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, 
           int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    virtual ~ResidentialBuilding();

    virtual void update() = 0;
    virtual Entity* clone() = 0;
    void reset();
    void calculateSatisfaction();
    float getSatisfaction();

    void setGlobalTransport();
    void setLocalTransport();
    void setGlobalEconomicBuilding();
    void setLocalEconomicBuilding();
    void setGlobalHospital();
    void setLocalHospital();
    void setGlobalPoliceStation();
    void setLocalPoliceStation();
    void setGlobalSchool();
    void setLocalSchool();
    void setGlobalAmenity();
    void setLocalAmenity();
    void setGlobalUnity();
    void setLocalUnity();
    
};

#endif // RESIDENTIALBUILDING_H
