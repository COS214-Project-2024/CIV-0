#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;

class Subject
{
protected:
    std::vector<Observer*> subscribers;
public:
    Subject();
    ~Subject();
    bool unsubscribe(Observer* observer);
    bool subscribe(Observer* observer);
    void subscribeToAllResidentialInRadius();
};

#endif // SUBJECT_H
