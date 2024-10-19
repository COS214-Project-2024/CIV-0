#include "doctest.h"
#include "entities/state/UnderConstruction.h"
#include "entities/state/Built.h"

TEST_CASE("UnderConstructionTest test")
{
    int buildTime = 3;
    UnderConstruction state(buildTime);

    CHECK(state.getGameLoopCounter() == 0);
    CHECK(state.getBuildTime() == buildTime);

    for(int i = 0; i < buildTime - 1; i++)
    {
        State* newState = state.update();
        CHECK(newState == &state);
        CHECK(state.getGameLoopCounter() == i + 1);
    }

    CHECK(state.getGameLoopCounter() == buildTime-1);

    State* newState = state.update();
    CHECK(newState != &state);
    CHECK(dynamic_cast<Built*>(newState) != nullptr);
    CHECK(newState->getGameLoopCounter() == 0);

    delete newState;
}

TEST_CASE("UnderConstructionTest with zero build time")
{
    int buildTime = 0;
    UnderConstruction state(buildTime);

    CHECK(state.getGameLoopCounter() == 0);
    CHECK(state.getBuildTime() == buildTime);

    State* newState = state.initialize();
    CHECK(newState != &state);
    CHECK(dynamic_cast<Built*>(newState) != nullptr);
    CHECK(newState->getGameLoopCounter() == 0);

    delete newState;
}
