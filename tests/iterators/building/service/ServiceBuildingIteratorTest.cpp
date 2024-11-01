#include "doctest.h"
#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"
#include "iterators/building/service/ServiceBuildingIterator.h"
#include <vector>

TEST_CASE("Testing ServiceBuildingIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *p = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    School *s = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(h);
    row1.push_back(p);
    row2.push_back(nullptr);
    row2.push_back(s);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator *aIter = new ServiceBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    delete aIter;
    delete h;
    delete p;
    delete s;
}

TEST_CASE("Testing ServiceBuildingIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *p = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    School *s = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(s);
    row1.push_back(p);
    row2.push_back(nullptr);
    row2.push_back(h);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator *aIter = new ServiceBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 1);

    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete h;
    delete p;
    delete s;
}

TEST_CASE("Testing ServiceBuildingIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *p = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    School *s = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(h);
    row1.push_back(s);
    row2.push_back(nullptr);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator *aIter = new ServiceBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete h;
    delete p;
    delete s;
}

TEST_CASE("Testing ServiceBuildingIterator hasNext() with multiple buildings")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *p = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    School *s = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(s);
    row1.push_back(h);
    row2.push_back(nullptr);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator *aIter = new ServiceBuildingIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 1);

    delete aIter;
    delete h;
    delete p;
    delete s;
}

TEST_CASE("Testing ServiceBuildingIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *p = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    School *s = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(s);
    row1.push_back(p);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    ServiceBuildingIterator *aIter = new ServiceBuildingIterator(grid);
    aIter->first();
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete h;
    delete p;
    delete s;
}