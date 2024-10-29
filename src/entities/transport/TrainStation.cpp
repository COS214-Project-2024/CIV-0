#include "TrainStation.h"

TrainStation::TrainStation(EntityConfig ec, Size size, int xPos, int yPos) : Transport(ec, size, xPos, yPos)
{

}

TrainStation::TrainStation(TrainStation* trainStation) : Transport(trainStation) {

}

TrainStation::TrainStation() {}
TrainStation::~TrainStation() {}

void TrainStation::update()
{
    for(Entity* o : observers)
    {
        ResidentialBuilding* rb = dynamic_cast<ResidentialBuilding*>(o);
        
        if(rb)
        {
            rb->updateTrainStation(this);
        }
    }
}

Entity* TrainStation::clone()
{
    return new TrainStation(this);
}
