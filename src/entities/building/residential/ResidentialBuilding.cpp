#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding() {}
ResidentialBuilding::~ResidentialBuilding() {}

ResidentialBuilding::ResidentialBuilding(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime) : Building(electricity, water, symbol, radius, localEffect, globalEffect, width, height, revenue, size, xPos, yPos, buildTime)
{
    reset();
}

void ResidentialBuilding::reset()
{
    globalTransport = 0;
    localTransport = 0;
    globalEconomicBuilding = 0;
    localEconomicBuilding = 0;
    globalHospital = 0;
    localHospital = 0;
    globalPoliceStation = 0;
    localPoliceStation = 0;
    globalSchool = 0;
    localSchool = 0;
    globalAmenity = 0;
    localAmenity = 0;
    globalUtility = 0;
    localUtility = 0;
    satisfaction = 0;
}

void ResidentialBuilding::calculateSatisfaction()
{
    //TODO - MAGIC FORMULA - (This could either be just adding up all the values (which is mentioned below)
    //TODO - it could just be the summation of all values (which should be a maximum of 100) (localUtility is subtracted)
    //TODO - maybe add some balancing things dependant on how long you've been playing (i.e. a hospital is more important on round 10 than 2)
}

float ResidentialBuilding::getSatisfaction()
{
    return satisfaction;
}

/*
TODO - Okay so these settern need to set their corresponding variables to a set value.
TODO - Keep in mind that the sum of all these values that you will set need to add up to 100
TODO - Keep in mind that localUtility is the only value that will be minused instead of added (so it is not included in the 100)
*/

void ResidentialBuilding::setGlobalTransport()
{

}

void ResidentialBuilding::setLocalTransport()
{

}

void ResidentialBuilding::setGlobalEconomicBuilding()
{

}

void ResidentialBuilding::setLocalEconomicBuilding()
{

}

void ResidentialBuilding::setGlobalHospital()
{

}

void ResidentialBuilding::setLocalHospital()
{

}

void ResidentialBuilding::setGlobalPoliceStation()
{

}

void ResidentialBuilding::setLocalPoliceStation()
{

}

void ResidentialBuilding::setGlobalSchool()
{

}

void ResidentialBuilding::setLocalSchool()
{

}

void ResidentialBuilding::setGlobalAmenity()
{

}

void ResidentialBuilding::setLocalAmenity()
{

}

void ResidentialBuilding::setGlobalUnity()
{

}

void ResidentialBuilding::setLocalUnity()
{

}
