#ifndef INDUSTRY_H
#define INDUSTRY_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"

class Industry : public Entity, public Subject
{
public:
    Industry();
    ~Industry();
};

#endif // INDUSTRY_H
