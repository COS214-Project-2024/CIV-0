#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "entities/base/Entity.h"
#include "entities/base/Subject.h"

class Transport : public Entity, public Subject
{
public:
    Transport();
    ~Transport();
};

#endif // TRANSPORT_H
