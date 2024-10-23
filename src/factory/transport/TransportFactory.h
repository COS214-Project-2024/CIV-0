#ifndef TRANSPORTFACTORY_H
#define TRANSPORTFACTORY_H

#include "factory/base/EntityFactory.h"



class TransportFactory : EntityFactory {
   public:
	TransportFactory();
	~TransportFactory();
	virtual Entity* createSmallEntity(EntityType type, int xPos, int yPos);
	virtual Entity* createMediumEntity(EntityType type, int xPos, int yPos);
	virtual Entity* createLargeEntity(EntityType type, int xPos, int yPos);

   private:
	Entity* createBusStop(Size size, int xPos, int yPos);
	Entity* createTrainStation(Size size, int xPos, int yPos);
	Entity* createAirport(Size size, int xPos, int yPos);
};

#endif
