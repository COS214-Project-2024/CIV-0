#include "doctest.h"
#include "entities/transport/TrainStation.h"
#include "entities/building/residential/House.h"

TEST_CASE("Testing TrainStation constructor and clone")
{
    Entity* a1 = new TrainStation(100, 200, "A", 50, 20, 10, 5, 5, 1000, Size::LARGE, 10, 20, 15);
    
    CHECK(a1->getXPosition() == 10);
    CHECK(a1->getYPosition() == 20);
    CHECK(a1->getRevenue() == 1000);
    CHECK(a1->getWidth() == 5);
    CHECK(a1->getHeight() == 5);

    Entity* cloneTrainStation = a1->clone();
    CHECK(cloneTrainStation->getXPosition() == 10);
    CHECK(cloneTrainStation->getYPosition() == 20);
    CHECK(cloneTrainStation->getRevenue() == 1000);

    delete cloneTrainStation;
    delete a1;
}

TEST_CASE("Testing TrainStation update")
{
    TrainStation* ts = new TrainStation(100, 200, "A", 50, 20, 10, 5, 5, 1000, Size::LARGE, 10, 20, 15);
    House* house = new House(100, 100, "R", 50, 20, 10, 5, 5, 1000, Size::MEDIUM, 15, 25, 10);

    ts->subscribe(house);

    ts->update();
    
    CHECK(house->getSatisfaction() <= 100);

    delete ts;
    delete house;
}

TEST_CASE("Testing TrainStation subscribe and unsubscribe")
{
    TrainStation ts(100, 200, "A", 50, 20, 10, 5, 5, 1000, Size::LARGE, 10, 20, 15);
    House rb(100, 100, "R", 50, 20, 10, 5, 5, 1000, Size::MEDIUM, 15, 25, 10);

    CHECK(ts.subscribe(&rb) == true);
    CHECK(ts.subscribe(&rb) == false);

    CHECK(ts.unsubscribe(&rb) == true);
    CHECK(ts.unsubscribe(&rb) == false);
}