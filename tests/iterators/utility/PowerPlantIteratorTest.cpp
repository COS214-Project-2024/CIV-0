#include "doctest.h"
#include "iterators/utility/PowerPlantIterator.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/building/amenity/Theater.h"

TEST_CASE("Testing PowerPlantIterator initial position")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *p = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(p);
    row1.push_back(p);
    row2.push_back(nullptr);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    PowerPlantIterator *aIter = new PowerPlantIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing PowerPlantIterator next()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *p = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(p);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    PowerPlantIterator *aIter = new PowerPlantIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing PowerPlantIterator first()")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *p = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(p);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(p);

    grid.push_back(row1);
    grid.push_back(row2);

    PowerPlantIterator *aIter = new PowerPlantIterator(grid);
    aIter->first();
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == true);

    delete aIter;
    delete p;
    delete t;
}

TEST_CASE("Testing PowerPlantIterator hasNext() with multiple PowerPlants")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *p1 = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    PowerPlant *p2 = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(p1);
    row1.push_back(nullptr);
    row2.push_back(t);
    row2.push_back(p2);

    grid.push_back(row1);
    grid.push_back(row2);

    PowerPlantIterator *aIter = new PowerPlantIterator(grid);
    aIter->first();
    CHECK(aIter->hasNext() == true);
    CHECK(aIter->getRow() == 0);
    CHECK(aIter->getCol() == 0);

    aIter->next();
    CHECK(aIter->getRow() == 1);
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->hasNext() == true);

    aIter->next();
    CHECK(aIter->getRow() == 2);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete p1;
    delete p2;
    delete t;
}

TEST_CASE("Testing PowerPlantIterator reaching the end")
{
    std::vector<std::vector<Entity *>> grid;

    std::vector<Entity *> row1;
    std::vector<Entity *> row2;
    PowerPlant *p = new PowerPlant(ConfigManager::getEntityConfig(EntityType::POWERPLANT, Size::SMALL), Size::SMALL, 10, 10);
    Theater *t = new Theater(ConfigManager::getEntityConfig(EntityType::THEATER, Size::SMALL), Size::SMALL, 10, 10);

    row1.push_back(p);
    row1.push_back(t);
    row2.push_back(nullptr);
    row2.push_back(nullptr);

    grid.push_back(row1);
    grid.push_back(row2);

    PowerPlantIterator *aIter = new PowerPlantIterator(grid);
    aIter->first();
    aIter->next();
    CHECK(aIter->hasNext() == false);

    delete aIter;
    delete p;
    delete t;
}
