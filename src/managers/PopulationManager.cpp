#include "PopulationManager.h"
#include "utils/PolicyType.h"
#include "policies/electricity/HighElectricityPolicy.h"
#include "policies/electricity/NormalElectricityPolicy.h"
#include "policies/electricity/LowElectricityPolicy.h"
#include "policies/water/HighWaterPolicy.h"
#include "policies/water/NormalWaterPolicy.h"
#include "policies/water/LowWaterPolicy.h"

PopulationManager::PopulationManager(int minimumIncrease, int maximumIncrease)
{
    this->minimumIncrease = minimumIncrease;
    this->maximumIncrease = maximumIncrease;
}

PopulationManager::~PopulationManager() {}

void PopulationManager::calculatePopulationCapacity()
{
    City *c = City::instance();
    PopulationVisitor *pv = new PopulationVisitor();
    pv->visit(c);
    int populationCapacity = pv->getTotalPopulationCapacity();
    c->setPopulationCapacity(populationCapacity);
    delete pv;
}

void PopulationManager::growPopulation()
{
    City *c = City::instance();

    int increase = std::rand();
    increase = increase % (maximumIncrease - minimumIncrease);
    increase += minimumIncrease;

    c->setPopulation(c->getPopulation() + increase);
}

void PopulationManager::decreasePopulation()
{
    City *c = City::instance();

    int decrease = std::rand();
    decrease = decrease % (maximumIncrease - minimumIncrease);
    decrease += minimumIncrease;

    c->setPopulation(c->getPopulation() - decrease);
}

void PopulationManager::calculateSatisfaction()
{
    City *c = City::instance();
    SatisfactionVisitor *sv = new SatisfactionVisitor();
    sv->visit(c);
    float satisfaction = sv->getAverageSatisfaction();
    satisfaction = satisfaction - c->getResidentialTax() - c->getEconomicTax() + 50;

    UtilityVisitor *uv = new UtilityVisitor();
    uv->visit(c);

    c->setWaterProduction(uv->getTotalWater());
    c->setElectricityProduction(uv->getTotalElectricity());
    c->setWasteProduction(uv->getTotalWasteHandled());
    c->setSewageProduction(uv->getTotalSewageHandled());

    PopulationVisitor *pv = new PopulationVisitor();
    pv->visit(c);

    c->setElectricityConsumption(pv->getTotalElectricityConsumption());
    c->setWaterConsumption(pv->getTotalWaterConsumption());

    // Todo - consider adding waste and sewage (optional)

    ElectricityPolicy *et = City::instance()->getElectricityPolicy();
    WaterPolicy *wt = City::instance()->getWaterPolicy();

    float electricityConsumption = static_cast<float>(c->getElectricityConsumption());
    if (dynamic_cast<HighElectricityPolicy *>(et) != nullptr)
    {
        electricityConsumption += electricityConsumption * 0.25;
        satisfaction += 5;
    }
    else if (dynamic_cast<LowElectricityPolicy *>(et) != nullptr)
    {
        electricityConsumption -= electricityConsumption * 0.25;
        satisfaction -= 5;
    }

    float waterConsumption = static_cast<float>(c->getElectricityConsumption());
    if (dynamic_cast<HighWaterPolicy *>(wt) != nullptr)
    {
        waterConsumption += waterConsumption * 0.25;
        satisfaction += 5;
    }
    else if (dynamic_cast<LowWaterPolicy *>(wt) != nullptr)
    {
        waterConsumption -= waterConsumption * 0.25;
        satisfaction -= 5;
    }

    float electricityPercentage;
    if (electricityConsumption <= 0)
    {
        electricityPercentage = 100;
    }
    else
    {
        electricityPercentage = (static_cast<float>(c->getElectricityProduction()) / electricityConsumption) * 100.0f;
    }

    float waterPercentage;
    if (waterConsumption <= 0)
    {
        waterPercentage = 100;
    }
    else
    {
        waterPercentage = (static_cast<float>(c->getWaterProduction()) / waterConsumption) * 100.0f;
    }

    if (satisfaction > electricityPercentage)
    {
        satisfaction = electricityPercentage;
    }
    if (satisfaction > waterPercentage)
    {
        satisfaction = waterPercentage;
    }

    if (satisfaction > 100)
    {
        satisfaction = 100;
    }
    else if (satisfaction < 0)
    {
        satisfaction = 0;
    }

    delete sv;
    delete uv;
    delete pv;

    int randomAdjustment = (std::rand() % 21) - 10;
    satisfaction = std::max(0.0f, std::min(100.0f, satisfaction + randomAdjustment));

    c->setSatisfaction(satisfaction);
}