#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"
#include <vector>

class Subject;

class Observer
{
protected:
    std::vector<Subject*> subscriptions;
public:
    Observer();
    virtual ~Observer();
    bool subscribe(Subject* subject);
    bool unsubscribe(Subject* subject);
    void unsubscribeFromAll();
};

#endif // OBSERVER_H
