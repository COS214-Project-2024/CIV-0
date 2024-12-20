#include "doctest.h"
#include "entities/building/service/Hospital.h"
#include "entities/building/service/PoliceStation.h"
#include "entities/building/service/School.h"
#include "entities/building/residential/House.h"
#include "entities/building/residential/Apartment.h"
#include "iterators/building/BuildingIterator.h"
#include <vector>

TEST_CASE("Testing BuildingIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *ps = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    House *house = new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(h);
    row1.push_back(ps);
    row2.push_back(nullptr);
    row2.push_back(house);

    grid.push_back(row1);
    grid.push_back(row2);

    BuildingIterator *bIter = new BuildingIterator(grid);
    bIter->first();
    CHECK(bIter->getRow() == 0);
    CHECK(bIter->getCol() == 0);

    delete bIter;
    delete h;
    delete ps;
    delete house;
}

TEST_CASE("Testing BuildingIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    School *school = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    House *house = new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(school);
    row1.push_back(h);
    row2.push_back(nullptr);
    row2.push_back(house);

    grid.push_back(row1);
    grid.push_back(row2);

    BuildingIterator *bIter = new BuildingIterator(grid);
    bIter->first();
    CHECK(bIter->hasNext() == true);
    CHECK(bIter->getRow() == 0);
    CHECK(bIter->getCol() == 0);

    bIter->next();
    CHECK(bIter->hasNext() == true);
    CHECK(bIter->getRow() == 0);
    CHECK(bIter->getCol() == 1);

    bIter->next();
    CHECK(bIter->hasNext() == true);
    CHECK(bIter->getRow() == 1);
    CHECK(bIter->getCol() == 1);

    bIter->next();
    CHECK(bIter->hasNext() == false);

    delete bIter;
    delete school;
    delete h;
    delete house;
}

TEST_CASE("Testing BuildingIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    Apartment *apt = new Apartment(ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::SMALL), Size::SMALL, 10, 10);
    School *school = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(h);
    row1.push_back(school);
    row2.push_back(nullptr);
    row2.push_back(apt);

    grid.push_back(row1);
    grid.push_back(row2);

    BuildingIterator *bIter = new BuildingIterator(grid);
    bIter->first();
    CHECK(bIter->getRow() == 0);
    CHECK(bIter->getCol() == 0);
    CHECK(bIter->hasNext() == true);

    delete bIter;
    delete h;
    delete apt;
    delete school;
}

TEST_CASE("Testing BuildingIterator hasNext() with multiple buildings")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PoliceStation *ps = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    Hospital *h = new Hospital(ConfigManager::getEntityConfig(EntityType::HOSPITAL, Size::SMALL), Size::SMALL, 10, 10);
    Apartment *apt = new Apartment(ConfigManager::getEntityConfig(EntityType::APARTMENT, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(ps);
    row1.push_back(h);
    row2.push_back(nullptr);
    row2.push_back(apt);

    grid.push_back(row1);
    grid.push_back(row2);

    BuildingIterator *bIter = new BuildingIterator(grid);
    bIter->first();
    CHECK(bIter->hasNext() == true);
    CHECK(bIter->getRow() == 0);
    CHECK(bIter->getCol() == 0);

    bIter->next();
    CHECK(bIter->hasNext() == true);
    CHECK(bIter->getRow() == 0);
    CHECK(bIter->getCol() == 1);

    delete bIter;
    delete ps;
    delete h;
    delete apt;
}

TEST_CASE("Testing BuildingIterator hasNext() reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    House *house = new House(ConfigManager::getEntityConfig(EntityType::HOUSE, Size::SMALL), Size::SMALL, 10, 10);
    PoliceStation *ps = new PoliceStation(ConfigManager::getEntityConfig(EntityType::POLICESTATION, Size::SMALL), Size::SMALL, 10, 10);
    School *school = new School(ConfigManager::getEntityConfig(EntityType::SCHOOL, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(house);
    row1.push_back(ps);
    row2.push_back(nullptr);
    row2.push_back(school);

    grid.push_back(row1);
    grid.push_back(row2);

    BuildingIterator *bIter = new BuildingIterator(grid);
    bIter->first();
    bIter->next();
    bIter->next();
    bIter->next();
    CHECK(bIter->hasNext() == false);

    delete bIter;
    delete house;
    delete ps;
    delete school;
}