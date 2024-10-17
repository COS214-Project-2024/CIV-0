#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "Transport.h"

class TrainStation : public Transport
{
public:
    TrainStation();
    TrainStation(int electricity, int water, std::string symbol, int radius, int localEffect, int globalEffect, int width, int height, int revenue, Size size, int xPos, int yPos, int buildTime);
    ~TrainStation();
    void update(); //TODO
    Entity* clone();
};

#endif // TRAINSTATION_H
