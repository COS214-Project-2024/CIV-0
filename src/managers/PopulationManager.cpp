#include "PopulationManager.h"

//!DO NOT TOUCH MY CODE. I AM GOING TO EDIT THIS IN ANOTHER BRANCH
PopulationManager::PopulationManager(int minimumIncrease, int maximumIncrease)
{
    this->minimumIncrease = minimumIncrease;
    this->maximumIncrease = maximumIncrease;
}

//!DO NOT TOUCH MY CODE. I AM GOING TO EDIT THIS IN ANOTHER BRANCH
PopulationManager::~PopulationManager() {}

//!DO NOT TOUCH MY CODE. I AM GOING TO EDIT THIS IN ANOTHER BRANCH
void PopulationManager::calculatePopulationCapacity()
{
    City* c = City::instance();
    PopulationVisitor* pv = new PopulationVisitor();
    pv->visit(c);
    int populationCapacity = pv->getTotalPopulationCapacity();
    c->setPopulationCapacity(populationCapacity);
}

//!DO NOT TOUCH MY CODE. I AM GOING TO EDIT THIS IN ANOTHER BRANCH
void PopulationManager::growPopulation()
{
    City* c = City::instance();

    int increase = std::rand();
    increase = increase % (minimumIncrease+maximumIncrease);
    increase+=minimumIncrease;

    c->setPopulation(c->getPopulation()+increase);
}

//!DO NOT TOUCH MY CODE. I AM GOING TO EDIT THIS IN ANOTHER BRANCH
void PopulationManager::decreasePopulation()
{
    City* c = City::instance();

    int decrease = std::rand();
    decrease = decrease % (minimumIncrease+maximumIncrease);
    decrease+=minimumIncrease;

    c->setPopulation(c->getPopulation()-decrease);
}

//!DO NOT TOUCH MY CODE. I AM GOING TO EDIT THIS IN ANOTHER BRANCH
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