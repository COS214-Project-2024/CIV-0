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
#include <iostream>

// Brother what are these includes - does anyone want to fix this?

CityManager::CityManager() {}
CityManager::~CityManager() {}

void CityManager::initializeCity()
{
    City::instance();
}

void CityManager::updateCity()
{
    // TODO - I need to wait for the other managers
}

Entity *CityManager::getEntity(int x, int y)
{
    City *c = City::instance();
    return c->getEntity(x, y);
}

void CityManager::sellBuilding(int xPos, int yPos)
{
    City *c = City::instance();
    // Can't sell a road
    if (dynamic_cast<Road *>(c->getEntity(xPos, yPos)) != nullptr)
    {
        return;
    }
    c->deleteEntity(xPos, yPos);
}

void CityManager::sellAllBuildingsOfType(EntityType type)
{
    City *c = City::instance();
    for (int i = 0; i < c->getHeight(); i++)
    {
        for (int j = 0; j < c->getWidth(); j++)
        {
            switch (type)
            {
            case (EntityType::BUSSTOP):
                if (dynamic_cast<BusStop *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::TRAINSTATION):
                if (dynamic_cast<TrainStation *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::AIRPORT):
                if (dynamic_cast<Airport *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::OFFICE):
                if (dynamic_cast<Office *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::SHOPPINGMALL):
                if (dynamic_cast<ShoppingMall *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::FACTORY):
                if (dynamic_cast<Factory *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::HOUSE):
                if (dynamic_cast<House *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::APARTMENT):
                if (dynamic_cast<Apartment *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::HOSPITAL):
                if (dynamic_cast<Hospital *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::POLICESTATION):
                if (dynamic_cast<PoliceStation *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::SCHOOL):
                if (dynamic_cast<School *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::PARK):
                if (dynamic_cast<Park *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::THEATER):
                if (dynamic_cast<Theater *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::MONUMENT):
                if (dynamic_cast<Monument *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::POWERPLANT):
                if (dynamic_cast<PowerPlant *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::WATERSUPPLY):
                if (dynamic_cast<WaterSupply *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::WASTEMANAGMENT):
                if (dynamic_cast<WasteManagement *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::SEWAGESYSTEM):
                if (dynamic_cast<SewageSystem *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::ROAD):
                if (dynamic_cast<Road *>(c->getEntity(i, j)) != nullptr)
                {
                    //! Cant sell a road
                    return;
                }
                break;
            case (EntityType::WOODPRODUCER):
                if (dynamic_cast<WoodProducer *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::STONEPRODUCER):
                if (dynamic_cast<StoneProducer *>(c->getEntity(i, j)) != nullptr)
                {
                    sellBuilding(i, j);
                }
                break;
            case (EntityType::CONCRETEPRODUCER):
                if (dynamic_cast<ConcreteProducer *>(c->getEntity(i, j)) != nullptr)
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
    std::vector<std::vector<int>> v;

    City *c = City::instance();
    for (int i = 0; i < c->getWidth(); i++)
    {
        for (int j = 0; j < c->getHeight(); j++)
        {
            if (canBuyAt(i, j, type, size))
            {
                std::vector<int> v2;
                v2.push_back(i);
                v2.push_back(j);
                v.push_back(v2);
            }
        }
    }
    return v;
}

bool CityManager::canAffordToBuy(EntityType type, Size size)
{
    City *c = City::instance();
    EntityConfig ec = ConfigManager::getEntityConfig(type, size);
    if (ec.cost.concreteCost > c->getConcrete())
    {
        return false;
    }
    else if (ec.cost.woodCost > c->getWood())
    {
        return false;
    }
    else if (ec.cost.stoneCost > c->getStone())
    {
        return false;
    }
    else if (ec.cost.moneyCost > c->getMoney())
    {
        return false;
    }
    return true;
}

bool CityManager::canBuyAt(int xPos, int yPos, EntityType type, Size size)
{
    City *c = City::instance();

    if (xPos < 0 || xPos >= c->getWidth() || yPos < 0 || yPos >= c->getHeight())
    {
        return false;
    }

    if (c->getEntity(xPos, yPos) != nullptr)
    {
        return false;
    }

    EntityConfig ec = ConfigManager::getEntityConfig(type, size);

    if (xPos + ec.width > c->getWidth() || yPos - ec.height < 0)
    {
        return false;
    }

    bool isRoad = false;

    for (int i = xPos; i < xPos + ec.width; i++)
    {
        for (int j = yPos - ec.height + 1; j <= yPos; j++)
        {
            if (c->getEntity(i, j) != nullptr)
            {
                return false;
            }
            if (!isRoad)
            {
                if (dynamic_cast<Road *>(c->getEntity(i - 1, j)) != nullptr)
                {
                    isRoad = true;
                }
                else if (dynamic_cast<Road *>(c->getEntity(i + 1, j)) != nullptr)
                {
                    isRoad = true;
                }
                else if (dynamic_cast<Road *>(c->getEntity(i, j - 1)) != nullptr)
                {
                    isRoad = true;
                }
                else if (dynamic_cast<Road *>(c->getEntity(i, j + 1)) != nullptr)
                {
                    isRoad = true;
                }
            }
        }
    }

    return isRoad;
}

bool CityManager::buyEntity(EntityType type, Size size)
{
    if (canAffordToBuy(type, size))
    {
        EntityConfig ec = ConfigManager::getEntityConfig(type, size);
        City *city = City::instance();

        city->setMoney(city->getMoney() - ec.cost.moneyCost);
        city->setWood(city->getWood() - ec.cost.woodCost);
        city->setConcrete(city->getConcrete() - ec.cost.concreteCost);
        city->setStone(city->getStone() - ec.cost.stoneCost);

        return true;
    }

    return false;
}