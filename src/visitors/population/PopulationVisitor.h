#ifndef POPULATIONVISITOR_H
#define POPULATIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"

class PopulationVisitor : public CityVisitor
{
private:
    int totalPopulationCapacity;
    int housePopulationCapacity;
    int apartmentPopulationCapacity;

public:
    PopulationVisitor();
    ~PopulationVisitor() {}

    void visit(City *city) override;

    int getTotalPopulationCapacity() const;
    int getHousePopulationCapacity() const;
    int getApartmentPopulationCapacity() const;
};

#endif // POPULATIONVISITOR_H
