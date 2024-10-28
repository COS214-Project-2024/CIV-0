#ifndef CITYVISITOR_H
#define CITYVISITOR_H

#include <vector>
#include "entities/base/Entity.h"

class City; // Forward declaration to avoid circular dependency

class CityVisitor
{
public:
    CityVisitor() = default;          // Default constructor
    virtual ~CityVisitor() = default; // Default destructor

    // Abstract visit method
    virtual void visit(City *city) = 0; // Pure virtual to force subclasses to implement
};

#endif // CITYVISITOR_H
