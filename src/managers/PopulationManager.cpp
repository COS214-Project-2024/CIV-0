#include "PopulationManager.h"
#include <iostream>

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

    float electricityPercentage;
    if (c->getElectricityConsumption() == 0)
    {
        electricityPercentage = 100;
    }
    else
    {
        electricityPercentage = (static_cast<float>(c->getElectricityProduction()) / static_cast<float>(c->getElectricityConsumption())) * 100.0f;
    }

    float waterPercentage;
    if (c->getWaterConsumption() == 0)
    {
        waterPercentage = 100;
    }
    else
    {
        waterPercentage = (static_cast<float>(c->getWaterProduction()) / static_cast<float>(c->getWaterConsumption())) * 100.0f;
    }


    if (satisfaction > electricityPercentage)
    {
        satisfaction = electricityPercentage;
    }
    if (satisfaction > waterPercentage)
    {
        satisfaction = waterPercentage;
    }

    if(satisfaction>100)
    {
        satisfaction = 100;
    }
    else if(satisfaction<0)
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