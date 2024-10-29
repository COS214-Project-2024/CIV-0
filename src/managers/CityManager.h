#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include "entities/base/Entity.h"
#include <vector>
#include "city/City.h"

class CityManager
{
public:
    CityManager();
    ~CityManager();
    void initializeCity();
    void updateCity();
    Entity* getEntity(int x, int y);
    void sellBuilding(int xPos, int yPos);
    void sellAllBuildingsOfType(EntityType type);
    std::vector<std::vector<int>> getAvailiablePositions(EntityType type, Size size);
    bool canAffordToBuy(EntityType type, Size size);
    bool canBuyAt(int xPos, int yPos, EntityType type, Size size);
    bool buyEntity(EntityType type, Size size);
};

#endif // CITYMANAGER_H
