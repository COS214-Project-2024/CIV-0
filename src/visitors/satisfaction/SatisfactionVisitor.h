#ifndef SATISFACTIONVISITOR_H
#define SATISFACTIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"

/**
 * @brief Visitor that calculates the average satisfaction of residential buildings in a city.
 */
class SatisfactionVisitor : public CityVisitor
{
private:
    float totalSatisfaction; /**< Accumulated satisfaction of all residential buildings */
    int residentialCount;    /**< Number of residential buildings visited */

public:
    /**
     * @brief Constructs a SatisfactionVisitor with zeroed satisfaction and count.
     */
    SatisfactionVisitor();

    /**
     * @brief Default destructor.
     */
    ~SatisfactionVisitor() {}

    /**
     * @brief Visits a city to calculate residential satisfaction.
     * @param city Pointer to the City object being visited.
     */
    void visit(City *city) override;

    /**
     * @brief Gets the average satisfaction of residential buildings.
     * @return Average satisfaction, or 0 if no residential buildings.
     */
    float getAverageSatisfaction() const;

    /**
     * @brief Gets the count of residential buildings.
     * @return Number of residential buildings in the city.
     */
    int getResidentialCount() const;
};

#endif // SATISFACTIONVISITOR_H