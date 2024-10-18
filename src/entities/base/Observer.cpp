#include "Observer.h"

Observer::Observer() {}

Observer::~Observer()
{
    unsubscribeFromAll();
}

bool Observer::subscribe(Subject* subject)
{
    for(Subject* sub : subscriptions)
    {
        if(sub == subject)
        {
            return false;
        }
    }   
    subscriptions.push_back(subject);
    return true;
}

bool Observer::unsubscribe(Subject* subject)
{
    return subject->unsubscribe(this);
}

void Observer::unsubscribeFromAll()
{
    
}