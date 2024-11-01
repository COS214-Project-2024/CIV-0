#include "GovernmentManager.h"
#include "city/City.h"
#include "visitors/tax/TaxCalculationVisitor.h"
#include "utils/Memento.h"
#include "utils/Caretaker.h"


/**
 * @brief Constructor for GovernmentManager, initializing the caretaker.
 */
GovernmentManager::GovernmentManager() {
    caretaker = new Caretaker();
}

/**
 * @brief Destructor for GovernmentManager, cleaning up resources.
 */
GovernmentManager::~GovernmentManager() {
    delete caretaker;
}

/**
 * @brief Sets the residential tax rate in the city.
 * 
 * @param rate The residential tax rate.
 */
void GovernmentManager::setResidentialTaxRate(float rate) {
    City::instance()->setResidentialTax(static_cast<int>(rate));
}

/**
 * @brief Sets the economic tax rate in the city.
 * 
 * @param rate The economic tax rate.
 */
void GovernmentManager::setEconomicTaxRate(float rate) {
    City::instance()->setEconomicTax(static_cast<int>(rate));
}

/**
 * @brief Gets the total residential tax collected.
 * 
 * @return The total residential tax amount.
 */
int GovernmentManager::getResidentialTax() {
    TaxCalculationVisitor* taxVisitor = new TaxCalculationVisitor();
    City::instance()->accept(*taxVisitor);
    int totalResidentialTax = taxVisitor->getTotalResidentialTax();
    delete taxVisitor;
    return totalResidentialTax;
}

/**
 * @brief Gets the total economic tax collected.
 * 
 * @return The total economic tax amount.
 */
int GovernmentManager::getEconomicTax() {
    TaxCalculationVisitor* taxVisitor = new TaxCalculationVisitor();
    City::instance()->accept(*taxVisitor);
    int totalEconomicTax = taxVisitor->getTotalEconomicTax();
    delete taxVisitor;
    return totalEconomicTax;
}

/**
 * @brief Gets the current residential tax rate.
 * 
 * @return The residential tax rate.
 */
int GovernmentManager::getResidentialTaxRate() {
    return City::instance()->getResidentialTax();
}

/**
 * @brief Gets the current economic tax rate.
 * 
 * @return The economic tax rate.
 */
int GovernmentManager::getEconomicTaxRate() {
    return City::instance()->getEconomicTax();
}

/**
 * @brief Enacts a specified water usage policy in the city.
 * 
 * @param policy The type of water policy to enact.
 */
void GovernmentManager::enactWaterUsagePolicy(PolicyType policy) {
    City::instance()->setWaterPolicy(policy);
    Policy* newPolicy = City::instance()->getWaterPolicy(); // Treat as Policy*
    if (newPolicy) {
        Memento* m = newPolicy->createMemento();
        caretaker->setMemento(m);
    }
}

/**
 * @brief Enacts a specified electricity policy in the city.
 * 
 * @param policy The type of electricity policy to enact.
 */
void GovernmentManager::enactElectricityPolicy(PolicyType policy) {
    City::instance()->setElectricityPolicy(policy);
    Policy* newPolicy = City::instance()->getElectricityPolicy(); // Treat as Policy*
    if (newPolicy) {
        Memento* m = newPolicy->createMemento();
        caretaker->setMemento(m);
    }
}

/**
 * @brief Retrieves all past policies stored by the caretaker.
 * 
 * @return Vector of pointers to Memento objects representing past policies.
 */
std::vector<Memento*> GovernmentManager::getAllPastPolicies() {
    return caretaker->getPastPolicies();
}