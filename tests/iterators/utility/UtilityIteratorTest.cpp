#include "doctest.h"
#include "iterators/utility/UtilityIterator.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/wastemanagement/WasteManagement.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("UtilityIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *pp = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    SewageSystem *ss = new SewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    WasteManagement *wm = new WasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 10, 10);
    WaterSupply *ws = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(pp);
    row1.push_back(ss);
    row2.push_back(t);
    row2.push_back(wm);
    row2.push_back(ws);

    grid.push_back(row1);
    grid.push_back(row2);

    UtilityIterator *utilIter = new UtilityIterator(grid);
    utilIter->first();
    CHECK(utilIter->getRow() == 0);
    CHECK(utilIter->getCol() == 0);

    delete utilIter;
    delete pp;
    delete ss;
    delete wm;
    delete ws;
    delete t;
}

TEST_CASE("UtilityIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *pp = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    SewageSystem *ss = new SewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    WasteManagement *wm = new WasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 10, 10);
    WaterSupply *ws = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(pp);
    row1.push_back(nullptr);
    row2.push_back(ss);
    row2.push_back(t);
    row2.push_back(wm);

    grid.push_back(row1);
    grid.push_back(row2);

    UtilityIterator *utilIter = new UtilityIterator(grid);
    utilIter->first();
    CHECK(utilIter->getRow() == 0);
    CHECK(utilIter->getCol() == 0);

    utilIter->next();
    CHECK(utilIter->getRow() == 1);
    CHECK(utilIter->getCol() == 0);
    CHECK(utilIter->hasNext() == true);

    utilIter->next();
    CHECK(utilIter->getRow() == 1);
    CHECK(utilIter->getCol() == 2);
    CHECK(utilIter->hasNext() == true);

    utilIter->next();
    CHECK(utilIter->getRow() == 2);
    CHECK(utilIter->getCol() == 0);
    CHECK(utilIter->hasNext() == false);

    delete utilIter;
    delete pp;
    delete ss;
    delete wm;
    delete ws;
    delete t;
}

TEST_CASE("UtilityIterator hasNext() with multiple Utility instances")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *pp = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    SewageSystem *ss = new SewageSystem(ConfigManager::getEntityConfig(EntityType::SEWAGESYSTEM, Size::SMALL), Size::SMALL, 10, 10);
    WasteManagement *wm = new WasteManagement(ConfigManager::getEntityConfig(EntityType::WASTEMANAGEMENT, Size::SMALL), Size::SMALL, 10, 10);
    WaterSupply *ws = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(pp);
    row1.push_back(ss);
    row2.push_back(t);
    row2.push_back(ws);

    grid.push_back(row1);
    grid.push_back(row2);

    UtilityIterator *utilIter = new UtilityIterator(grid);
    utilIter->first();
    CHECK(utilIter->hasNext() == true);
    CHECK(utilIter->getRow() == 0);
    CHECK(utilIter->getCol() == 0);

    utilIter->next();
    CHECK(utilIter->getRow() == 0);
    CHECK(utilIter->getCol() == 1);
    CHECK(utilIter->hasNext() == true);

    utilIter->next();
    CHECK(utilIter->getRow() == 1);
    CHECK(utilIter->getCol() == 1);
    CHECK(utilIter->hasNext() == true);

    utilIter->next();
    CHECK(utilIter->getRow() == 2);
    CHECK(utilIter->getCol() == 0);
    CHECK(utilIter->hasNext() == false);

    delete utilIter;
    delete pp;
    delete ss;
    delete wm;
    delete ws;
    delete t;
}

TEST_CASE("UtilityIterator reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    WaterSupply *ws1 = new WaterSupply(ConfigManager::getEntityConfig(EntityType::WATERSUPPLY, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(ws1);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    UtilityIterator *utilIter = new UtilityIterator(grid);
    utilIter->first();
    utilIter->next();
    CHECK(utilIter->hasNext() == false);

    delete utilIter;
    delete ws1;
    delete t;
}