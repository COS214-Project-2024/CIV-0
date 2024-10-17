#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class Subject;

class Observer
{
protected:
    std::vector<Subject*> subscriptions;
public:
    Observer();
    ~Observer();
    bool unsubscribe(Subject* subject);
    void unsubscribeFromAll();
};

#endif // OBSERVER_H
