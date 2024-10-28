#ifndef POPULATIONVISITOR_H
#define POPULATIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"

class PopulationVisitor : public CityVisitor
{
private:
    int totalPopulationCapacity;
    int totalWaterConsumption;
    int totalElectricityConsumption;
    int housePopulationCapacity;
    int apartmentPopulationCapacity;

public:
    PopulationVisitor();
    ~PopulationVisitor() {}

    void visit(City *city) override;

    int getTotalPopulationCapacity() const;
    int getHousePopulationCapacity() const;
    int getTotalWaterConsumption() const;
    int getTotalElectricityConsumption() const;
    int getApartmentPopulationCapacity() const;
};

#endif // POPULATIONVISITOR_H
