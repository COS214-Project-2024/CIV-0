#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

#include "utils/EntityType.h"
#include "utils/Size.h"
#include "entities/utility/base/Utility.h"
#include "city/City.h"
#include "factory/utility/UtilityFactory.h"
#include "iterators/utility/UtilityIterator.h"
#include "iterators/utility/WaterSupplyIterator.h"
#include "iterators/utility/PowerPlantIterator.h"
#include "iterators/utility/WasteManagementIterator.h"
#include "iterators/utility/SewageSystemIterator.h"
#include <vector>

class UtilityManager
{
public:
    UtilityManager();
    ~UtilityManager();

    void buildUtility(EntityType type, Size size, int x, int y);

    int getElectricityProduction();
    int getElectricityConsumption();
    int getWaterProduction();
    int getWaterConsumption();

    std::vector<Utility*> getAllUtilities();
    std::vector<Utility*> getAllWaterSupplies();
    std::vector<Utility*> getAllPowerPlants();
    std::vector<Utility*> getAllWasteManagement();
    std::vector<Utility*> getAllSewageSystems();
    bool canAffordUpgrade(Utility* utility);
    bool upgrade(Utility* utility);
};

#endif // UTILITYMANAGER_H
