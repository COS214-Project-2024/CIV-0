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
    bool subscribe(Observer* observer);
    void notify();
};

#endif // SUBJECT_H
