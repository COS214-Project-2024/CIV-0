#ifndef RESOURCEVISITOR_H
#define RESOURCEVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "entities/industry/concreteproducer/ConcreteProducer.h"
#include "entities/industry/stoneproducer/StoneProducer.h"
#include "entities/industry/woodproducer/WoodProducer.h"

/**
 * @brief Visitor that calculates total resource output in a city.
 */
class ResourceVisitor : public CityVisitor
{
private:
    int totalWood;     /**< Total wood output from all wood producers */
    int totalConcrete; /**< Total concrete output from all concrete producers */
    int totalStone;    /**< Total stone output from all stone producers */

public:
    /**
     * @brief Constructs a ResourceVisitor with zeroed resource totals.
     */
    ResourceVisitor();

    /**
     * @brief Default destructor.
     */
    ~ResourceVisitor();

    /**
     * @brief Visits a city to calculate resource production.
     * @param city Pointer to the City object being visited.
     */
    void visit(City *city) override;

    /**
     * @brief Gets the total wood produced.
     * @return Total wood output in the city.
     */
    int getTotalWood() const { return totalWood; }

    /**
     * @brief Gets the total concrete produced.
     * @return Total concrete output in the city.
     */
    int getTotalConcrete() const { return totalConcrete; }

    /**
     * @brief Gets the total stone produced.
     * @return Total stone output in the city.
     */
    int getTotalStone() const { return totalStone; }
};

#endif // RESOURCEVISITOR_H