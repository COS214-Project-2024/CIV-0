#include "Subject.h"

Subject::Subject(){}
Subject::~Subject() {}

//Removes and observer (A ResidentialBuilding) from its list of observers to notify
bool Subject::unsubscribe(Observer* observer)
{
    for(auto it = subscribers.begin(); it != subscribers.end(); it++)
    {
        if (*it == observer)
        {
            subscribers.erase(it);
            return true;
        }
    }
    return false;
}

bool Subject::subscribe(Observer* observer)
{
    for(Observer* obs : subscribers)
    {
        if(obs == observer)
        {
            return false;
        }
    }
    subscribers.push_back(observer);
    return true;
}

void subscribeToAllResidentialInRadius()
{
    //TODO - Need ResidentialIterator First
}