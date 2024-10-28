#include "doctest.h"
#include "entities/transport/Airport.h"
#include "entities/transport/BusStop.h"
#include "entities/transport/TrainStation.h"

#include "iterators/transport/TransportIterator.h"
#include <vector>

TEST_CASE("TransportIterator test") {
    std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Airport* a = new Airport();
    BusStop* b = new BusStop();
    TrainStation* t = new TrainStation();

    row1.push_back(a);
    row1.push_back(b);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator* aIter = new TransportIterator(grid);
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Airport* a = new Airport();
    BusStop* b = new BusStop();
    TrainStation* t = new TrainStation();

    row1.push_back(a);
    row1.push_back(b);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator* aIter = new TransportIterator(grid);
    aIter->next();
    CHECK(aIter->getCol() == 1);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing first()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Airport* a = new Airport();
    BusStop* b = new BusStop();
    TrainStation* t = new TrainStation();

    row1.push_back(a);
    row1.push_back(b);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator* aIter = new TransportIterator(grid);
    aIter->first();
    CHECK(aIter->getCol() == 0);
    CHECK(aIter->getRow() == 0);
    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Airport* a = new Airport();
    BusStop* b = new BusStop();
    TrainStation* t = new TrainStation();

    row1.push_back(a);
    row1.push_back(b);
    row2.push_back(NULL);
    row2.push_back(t);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator* aIter = new TransportIterator(grid);
    aIter->next();
    CHECK(aIter->hasNext() == true);
    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing hasNext()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Airport* a = new Airport();
    BusStop* b = new BusStop();
    TrainStation* t = new TrainStation();

    row1.push_back(t);
    row1.push_back(b);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator* aIter = new TransportIterator(grid);
    aIter->next();
    aIter->next();
    CHECK(aIter->hasNext() == false);
    delete aIter;
    delete a;
    delete b;
    delete t;
}

TEST_CASE("Testing next()"){
        std::vector<std::vector<Entity*>> grid;

    std::vector<Entity*> row1;
    std::vector<Entity*> row2;
    Airport* a = new Airport();
    BusStop* b = new BusStop();
    TrainStation* t = new TrainStation();

    row1.push_back(a);
    row1.push_back(b);
    row2.push_back(NULL);
    row2.push_back(NULL);

    grid.push_back(row1);
    grid.push_back(row2);

    TransportIterator* aIter = new TransportIterator(grid);
    aIter->next();
    aIter->next();
    aIter->next();
    CHECK(aIter->getCol() == 1);
    delete aIter;
    delete a;
    delete b;
    delete t;
}

