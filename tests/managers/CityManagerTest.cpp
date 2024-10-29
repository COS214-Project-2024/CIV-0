#include "doctest.h"
#include "managers/CityManager.h"
#include "entities/base/Entity.h"
#include "entities/road/Road.h"
#include "entities/transport/BusStop.h"
#include "city/City.h"
#include <iostream>
#include <vector>

TEST_CASE("CityManager Initialization") {
    City::instance()->reset();
    CityManager cityManager;
    cityManager.initializeCity();
    
    // Assuming the City singleton initializes something specific we can check
    City* city = City::instance();
    CHECK(city != nullptr);
    city->reset();
}

TEST_CASE("CityManager Entity Manipulation") {
    City::instance()->reset();
    CityManager cityManager;
    cityManager.initializeCity();
    
    // Sell a building at a position where none exists
    cityManager.sellBuilding(1, 1);
    CHECK(cityManager.getEntity(1, 1) == nullptr);
    
    // Test that an entity is correctly placed and can be sold
    // Assuming City::setEntity exists
    City::instance()->addEntity(new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 1, 1));
    CHECK(cityManager.getEntity(1, 1) != nullptr);
    
    cityManager.sellBuilding(1, 1);
    CHECK(cityManager.getEntity(1, 1) == nullptr);
    City::instance()->reset();
}

TEST_CASE("CityManager Sell All Buildings of Type") {
    City::instance()->reset();
    CityManager cityManager;
    cityManager.initializeCity();

    // Set entities of different types to test bulk selling
    City::instance()->addEntity(new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 10, 10));
    City::instance()->addEntity(new BusStop(ConfigManager::getEntityConfig(EntityType::BUSSTOP, Size::LARGE), Size::LARGE, 20, 20));
    City::instance()->addEntity(new Road(ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL), Size::SMALL, 30, 30));
    
    cityManager.sellAllBuildingsOfType(EntityType::BUSSTOP);
    
    CHECK(cityManager.getEntity(10, 10) == nullptr);
    CHECK(cityManager.getEntity(20, 20) == nullptr);
    CHECK(cityManager.getEntity(30, 30) != nullptr);  // Road should remain unaffected

    City::instance()->reset();
}

TEST_CASE("CityManager Buy Entity - Affordability Check") {
    City::instance()->reset();
    CityManager cityManager;
    cityManager.initializeCity();
    
    // Configuring City resources and EntityConfig values for affordability
    City* city = City::instance();
    city->setMoney(1000);
    city->setWood(500);
    city->setConcrete(300);
    city->setStone(200);
    
    // Assuming ConfigManager::getEntityConfig is correctly implemented
    bool canBuy = cityManager.canAffordToBuy(EntityType::BUSSTOP, Size::SMALL);
    CHECK(canBuy == true);
    City::instance()->reset();
}

TEST_CASE("CityManager Buy Entity - Placement Check") {
    City::instance()->reset();
    CityManager cityManager;
    cityManager.initializeCity();
    
    // Assume position (5, 5) is within the city bounds
    bool canPlace = cityManager.canBuyAt(5, 5, EntityType::BUSSTOP, Size::SMALL);
    CHECK(canPlace == false);
    City::instance()->addEntity(new Road(ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL), Size::SMALL, 5, 5));

    canPlace = cityManager.canBuyAt(1, 3, EntityType::BUSSTOP, Size::SMALL);
    CHECK(canPlace == false);

    canPlace = cityManager.canBuyAt(1, 1, EntityType::BUSSTOP, Size::SMALL);
    CHECK(canPlace == false);

    canPlace = cityManager.canBuyAt(6, 6, EntityType::BUSSTOP, Size::SMALL);
    CHECK(canPlace == false);

    canPlace = cityManager.canBuyAt(6, 5, EntityType::BUSSTOP, Size::SMALL);
    CHECK(canPlace == true);

    // for(int i = 0; i<City::instance()->getWidth(); i++)
    // {
    //     for(int j = 0; j<City::instance()->getHeight(); j++)
    //     {
    //         if(City::instance()->getGrid()[i][j]!=nullptr)
    //         std::cout<<City::instance()->getGrid()[i][j]->getSymbol()<<" ";
    //         else
    //             std::cout<<". ";
    //     }
    //     std::cout<<"\n";
    // }

    // std::vector<std::vector<int>> v = cityManager.getAvailiablePositions(EntityType::BUSSTOP, Size::SMALL);

    // for(int i = 0; i<v.size(); i++)
    // {
    //     for(int j = 0; j<2; j++)
    //     {
    //         std::cout<<v.at(i).at(j)<<" ";
    //     }
    //     std::cout<<"\n";
    // }
    City::instance()->reset();
    
}

TEST_CASE("CityManager Get Available Positions") {
    City::instance()->reset();
    CityManager cityManager;
    cityManager.initializeCity();
    
    // Test available positions for a specific entity type and size
    std::vector<std::vector<int>> positions = cityManager.getAvailiablePositions(EntityType::BUSSTOP, Size::SMALL);
    
    // Assuming some available positions are within bounds, so positions should not be empty
    CHECK(positions.empty());
    City::instance()->addEntity(new Road(ConfigManager::getEntityConfig(EntityType::ROAD, Size::SMALL), Size::SMALL, 5, 5));
    positions = cityManager.getAvailiablePositions(EntityType::BUSSTOP, Size::SMALL);
    CHECK(positions.size()==4);
    City::instance()->reset();
}
