#ifndef STATSMENU_H
#define STATSMENU_H

#include "menus/base/IMenu.h"
#include "city/City.h"

class StatsMenu : public IMenu
{
public:
    StatsMenu();
    ~StatsMenu();

    void display() const override;
    void handleInput() override;

private:
    // Methods to display lists based on specific iterators
    void listAllCityEntities();
    void listAllBuildings();
    void listAllUtilities();
    void listAllRoads();
    void listAllTransport();
    void listAllEconomicBuildings();
    void listAllResidentialBuildings();
    void listAllServiceBuildings();
    void listAllAmenities();
    void listAllPowerPlants();
    void listAllWaterSupplies();
    void listAllWasteManagement();
    void listAllSewageSystems();
    void listAllConcreteProducers();
    void listAllStoneProducers();
    void listAllWoodProducers();

    void showCityStats(); // Displays overall city statistics
    std::string formatSatisfaction(float satisfaction) const;
};

#endif // STATSMENU_H
