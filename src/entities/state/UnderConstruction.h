#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "State.h"

class UnderConstruction : public State
{
public:
    UnderConstruction(int buildTime);
    ~UnderConstruction();
    State* update();
    State* initialize();
};

#endif // UNDERCONSTRUCTION_H
