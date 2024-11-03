#include "GovernmentManager.h"
#include "city/City.h"
#include "visitors/tax/TaxCalculationVisitor.h"
#include "utils/Memento.h"
#include "utils/Caretaker.h"

GovernmentManager::GovernmentManager() {
    caretaker = new Caretaker();
}

GovernmentManager::~GovernmentManager() {
    delete caretaker;
}

void GovernmentManager::setResidentialTaxRate(float rate) {
    City::instance()->setResidentialTax(static_cast<int>(rate));
}

void GovernmentManager::setEconomicTaxRate(float rate) {
    City::instance()->setEconomicTax(static_cast<int>(rate));
}

int GovernmentManager::getResidentialTax() {
    TaxCalculationVisitor* taxVisitor = new TaxCalculationVisitor();
    City::instance()->accept(*taxVisitor);
    int totalResidentialTax = taxVisitor->getTotalResidentialTax();
    delete taxVisitor;
    return totalResidentialTax;
}

int GovernmentManager::getEconomicTax() {
    TaxCalculationVisitor* taxVisitor = new TaxCalculationVisitor();
    City::instance()->accept(*taxVisitor);
    int totalEconomicTax = taxVisitor->getTotalEconomicTax();
    delete taxVisitor;
    return totalEconomicTax;
}

int GovernmentManager::getResidentialTaxRate() {
    return City::instance()->getResidentialTax();
}

int GovernmentManager::getEconomicTaxRate() {
    return City::instance()->getEconomicTax();
}

void GovernmentManager::enactWaterUsagePolicy(PolicyType policy) {
    City::instance()->setWaterPolicy(policy);
    Policy* newPolicy = City::instance()->getWaterPolicy(); // Treat as Policy*
    if (newPolicy) {
        Memento* m = newPolicy->createMemento();
        caretaker->setMemento(m);
    }
}

void GovernmentManager::enactElectricityPolicy(PolicyType policy) {
    City::instance()->setElectricityPolicy(policy);
    Policy* newPolicy = City::instance()->getElectricityPolicy(); // Treat as Policy*
    if (newPolicy) {
        Memento* m = newPolicy->createMemento();
        caretaker->setMemento(m);
    }
}

std::vector<Memento*> GovernmentManager::getAllPastPolicies() {
    return caretaker->getPastPolicies();
}