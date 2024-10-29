#include "CityManager.h"
#include "entities/transport/BusStop.h"
#include "entities/transport/TrainStation.h"
#include "entities/transport/Airport.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/road/Road.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"
#include "entities/building/amenity/Amenity.h"
#include "entities/building/amenity/Monument.h"
#include "entities/building/amenity/Park.h"
#include "entities/building/amenity/Theater.h"
#include "entities/building/economic/Factory.h"
#include "entities/building/economic/Office.h"
#include "entities/building/economic/ShoppingMall.h"
#include "entities/building/residential/Apartment.h"
#include "entities/building/residential/House.h"
#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"

//Brother what are these includes - does anyone want to fix this?

CityManager::CityManager() {}
CityManager::~CityManager() {}

void CityManager::initializeCity()
{
    City::instance();
}

void CityManager::updateCity()
{
    //TODO
}

Entity* CityManager::getEntity(int x, int y)
{
    City* c = City::instance();
    return c->getEntity(x, y);
}

void CityManager::sellBuilding(int xPos, int yPos)
{
    City* c = City::instance();   
    c->deleteEntity(xPos, yPos);

}

void CityManager::sellAllBuildingsOfType(EntityType type)
{
    City* c = City::instance();  
    for (int i = 0; i < c->getHeight(); i++)
    {
        for(int j = 0; j < c->getWidth(); j++)
        {
            switch(type)
            {
                case(EntityType::BUSSTOP):
                    if(dynamic_cast<BusStop*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::TRAINSTATION):
                    if(dynamic_cast<TrainStation*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::AIRPORT):
                    if(dynamic_cast<Airport*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::OFFICE):
                    if(dynamic_cast<Office*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::SHOPPINGMALL):
                    if(dynamic_cast<ShoppingMall*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::FACTORY):
                    if(dynamic_cast<Factory*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::HOUSE):
                    if(dynamic_cast<House*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::APARTMENT):
                    if(dynamic_cast<Apartment*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::HOSPITAL):
                    if(dynamic_cast<Hospital*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::POLICESTATION):
                    if(dynamic_cast<PoliceStation*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::SCHOOL):
                    if(dynamic_cast<School*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::PARK):
                    if(dynamic_cast<Park*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::THEATER):
                    if(dynamic_cast<Theater*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::MONUMENT):
                    if(dynamic_cast<Monument*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::POWERPLANT):
                    if(dynamic_cast<PowerPlant*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::WATERSUPPLY):
                    if(dynamic_cast<WaterSupply*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::WASTEMANAGMENT):
                    if(dynamic_cast<WasteManagement*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::SEWAGESYSTEM):
                    if(dynamic_cast<SewageSystem*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::ROAD):
                    if(dynamic_cast<Road*>(c->getEntity(i,j))!=nullptr)
                    {
                        return;
                    }
                    break;
                case(EntityType::WOODPRODUCER):
                    if(dynamic_cast<WoodProducer*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::STONEPRODUCER):
                    if(dynamic_cast<StoneProducer*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                case(EntityType::CONCRETEPRODUCER):
                    if(dynamic_cast<ConcreteProducer*>(c->getEntity(i,j))!=nullptr)
                    {
                        sellBuilding(i, j);
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

std::vector<std::vector<int>> CityManager::getAvailiablePositions(EntityType type, Size size)
{

}

bool CityManager::canAffordToBuy(EntityType type, Size size)
{

}

bool CityManager::canBuyAt(int xPos, int yPos, EntityType type, Size size)
{
    City* c = City::instance();
    if(c->getEntity(xPos, yPos)!=nullptr)
    {
        return false;
    }

    EntityConfig ec = ConfigManager::getEntityConfig(type, size);
    
    if(xPos+ec.width > c->getWidth() || yPos-ec.height < 0)
    {
        return false;
    }

    for(int i = xPos; i<xPos+ec.width; i++)
    {
        for(int j = yPos-ec.height; j<yPos; j++)
        {
            if(c->getEntity(i, j)!=nullptr)
            {
                return false;
            }
        }
    }

    //TODO check if it is touching road
}

bool CityManager::buyEntity(EntityType type, Size size)
{

}