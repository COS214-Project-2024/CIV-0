#ifndef CITYVISITOR_H
#define CITYVISITOR_H

#include <vector>
#include "entities/base/Entity.h"

class City; // Forward declaration to avoid circular dependency

/**
 * @brief Base class for visiting and interacting with City objects.
 */
class CityVisitor
{
public:
    /**
     * @brief Default constructor.
     */
    CityVisitor() = default;

    /**
     * @brief Default destructor.
     */
    virtual ~CityVisitor() = default;

    /**
     * @brief Abstract method to visit a City object.
     * @param city Pointer to the City object to be visited.
     */
    virtual void visit(City *city) = 0;
};

#endif // CITYVISITOR_H