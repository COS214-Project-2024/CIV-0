#ifndef STATE_H
#define STATE_H


class State
{
private:
    int gameLoopCounter;
    int buildTime;
public:
    State(int buildTime);
    virtual ~State();
    virtual State* update() = 0;
    virtual State* initialize() = 0;
    int getGameLoopCounter();
    int getBuildTime();
    void incrementGameLoopCounter();
};

#endif // STATE_H
