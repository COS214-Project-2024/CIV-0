#ifndef SATISFACTIONVISITOR_H
#define SATISFACTIONVISITOR_H

#include "visitors/base/CityVisitor.h"
#include "city/City.h"

class SatisfactionVisitor : public CityVisitor
{
private:
    float totalSatisfaction;
    int residentialCount;

public:
    SatisfactionVisitor();
    ~SatisfactionVisitor() {}

    void visit(City *city) override;

    float getAverageSatisfaction() const;
    int getResidentialCount() const;
};

#endif // SATISFACTIONVISITOR_H
