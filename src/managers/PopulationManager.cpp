#include "PopulationManager.h"

PopulationManager::PopulationManager(int minimumIncrease, int maximumIncrease)
{
    this->minimumIncrease = minimumIncrease;
    this->maximumIncrease = maximumIncrease;
}

PopulationManager::~PopulationManager() {}

void PopulationManager::calculatePopulationCapacity()
{
    City* c = City::instance();
    PopulationVisitor* pv = new PopulationVisitor();
    pv->visit(c);
    int populationCapacity = pv->getTotalPopulationCapacity();
    c->setPopulationCapacity(populationCapacity);
}

void PopulationManager::growPopulation()
{
    City* c = City::instance();

    int increase = std::rand();
    increase = increase % (minimumIncrease+maximumIncrease);
    increase+=minimumIncrease;

    c->setPopulation(c->getPopulation()+increase);
}

void PopulationManager::decreasePopulation()
{
    City* c = City::instance();

    int decrease = std::rand();
    decrease = decrease % (minimumIncrease+maximumIncrease);
    decrease+=minimumIncrease;

    c->setPopulation(c->getPopulation()-decrease);
}

void PopulationManager::calculateSatisfaction()
{
    City* c = City::instance();
    SatisfactionVisitor* sv = new SatisfactionVisitor();
    sv->visit(c);
    float satisfaction = sv->getAverageSatisfaction();

    UtilityVisitor* uv = new UtilityVisitor();
    uv->visit(c);

    c->setWaterProduction(uv->getTotalWater());
    c->setElectricityProduction(uv->getTotalElectricity());
    c->setWasteProduction(uv->getTotalWasteHandled());
    c->setSewageProduction(uv->getTotalSewageHandled());

    PopulationVisitor* pv = new PopulationVisitor();
    pv->visit(c);

    c->setElectricityConsumption(pv->getTotalElectricityConsumption());
    c->setWasteConsumption(pv->getTotalWaterConsumption());
    
    //Todo - waste and sewage

    float electricityPercentage = (c->getElectricityProduction()/c->getElectricityProduction()) * 100;
    float waterPercentage = (c->getWaterProduction()/c->getWaterConsumption()) * 100;

    if(satisfaction>electricityPercentage)
    {
        satisfaction = electricityPercentage;
    }
    if(satisfaction>waterPercentage)
    {
        satisfaction = waterPercentage;
    }

    c->setSatisfaction(satisfaction);
}