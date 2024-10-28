#ifndef RESOURCEVISITOR_H
#define RESOURCEVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"

class City;

class ResourceVisitor : public CityVisitor
{
private:
    int totalWood;
    int totalConcrete;
    int totalStone;

public:
    ResourceVisitor();
    ~ResourceVisitor();

    void visit(City *city) override;

    int getTotalWood() const { return totalWood; }
    int getTotalConcrete() const { return totalConcrete; }
    int getTotalStone() const { return totalStone; }
};

#endif // RESOURCEVISITOR_H