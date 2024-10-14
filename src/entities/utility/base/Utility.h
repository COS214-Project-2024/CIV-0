#ifndef UTILITY_H
#define UTILITY_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"

class Utility : public Entity, public Subject
{
public:
    Utility();
    ~Utility();
};

#endif // UTILITY_H
