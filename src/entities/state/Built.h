#ifndef BUILT_H
#define BUILT_H

#include "State.h"

class Built : public State
{
public:
    Built(int buildTime);
    ~Built();
    State* update();
    State* initialize();
};

#endif // BUILT_H
