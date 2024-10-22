#include "Memento.h"

Memento::Memento(const std::string& name, const std::string& detail)
    : name(name), detail(detail) {}

std::string Memento::getName() const {
    return name;
}

std::string Memento::getDetail() const {
    return detail;
}

void Memento::setName(const std::string& name) {
    this->name = name;
}

void Memento::setDetail(const std::string& detail) {
    this->detail = detail;
}