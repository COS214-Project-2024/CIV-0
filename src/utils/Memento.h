#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

class Memento {
private:
    std::string name;
    std::string detail;

public:
    Memento(const std::string& name, const std::string& detail);
    std::string getName() const;
    std::string getDetail() const;
    void setName(const std::string& name);
    void setDetail(const std::string& detail);
};

#endif
