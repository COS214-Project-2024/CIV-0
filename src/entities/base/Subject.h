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
    virtual ~Subject();
    bool unsubscribe(Observer* observer);
    bool subscribe(Observer* observer);
};

#endif // SUBJECT_H
