#include "doctest.h"
#include "entities/state/Built.h"

TEST_CASE("BuiltTest test")
{
    int buildTime = 5;
    Built state(buildTime);

    CHECK(state.getGameLoopCounter() == 0);
    CHECK(state.getBuildTime() == buildTime);

    State* newState = state.update();
    CHECK(newState == &state);

    newState = state.initialize();
    CHECK(newState == &state);
}