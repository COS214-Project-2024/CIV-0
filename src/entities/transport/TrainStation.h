#ifndef TRAINSTATION_H
#define TRAINSTATION_H

#include "Transport.h"

class TrainStation : public Transport
{
public:
    TrainStation();
    TrainStation(EntityConfig ec, Size size, int xPos, int yPos);
    TrainStation(TrainStation* trainStation);
    virtual ~TrainStation();
    void update();
    Entity* clone();
};

#endif // TRAINSTATION_H
