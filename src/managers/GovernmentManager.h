#ifndef GOVERNMENTMANAGER_H
#define GOVERNMENTMANAGER_H

#include "PolicyType.h"
#include <vector>
#include "utils/Caretaker.h"
#include "utils/PolicyType.h"


/**
 * @class GovernmentManager
 * @brief Manages government policies and taxation within the city.
 *
 * The GovernmentManager class interacts with the City and Visitor classes to manage
 * residential and economic taxation and to enact water and electricity usage policies.
 */
class GovernmentManager {
public:
    /**
     * @brief Constructor for GovernmentManager.
     */
    GovernmentManager();

    /**
     * @brief Destructor for GovernmentManager.
     */
    ~GovernmentManager();

    /**
     * @brief Sets the residential tax rate in the city.
     * @param rate The residential tax rate.
     */
    void setResidentialTaxRate(float rate);

    /**
     * @brief Sets the economic tax rate in the city.
     * @param rate The economic tax rate.
     */
    void setEconomicTaxRate(float rate);

    /**
     * @brief Gets the total residential tax collected.
     * @return The total residential tax amount.
     */
    int getResidentialTax();

    /**
     * @brief Gets the total economic tax collected.
     * @return The total economic tax amount.
     */
    int getEconomicTax();

    /**
     * @brief Gets the current residential tax rate.
     * @return The residential tax rate.
     */
    int getResidentialTaxRate();

    /**
     * @brief Gets the current economic tax rate.
     * @return The economic tax rate.
     */
    int getEconomicTaxRate();

    /**
     * @brief Enacts a specified water usage policy in the city.
     * @param policy The type of water policy to enact.
     */
    void enactWaterUsagePolicy(PolicyType policy);

    /**
     * @brief Enacts a specified electricity policy in the city.
     * @param policy The type of electricity policy to enact.
     */
    void enactElectricityPolicy(PolicyType policy);

    /**
     * @brief Retrieves all past policies stored by the caretaker.
     * @return Vector of pointers to Memento objects representing past policies.
     */
    std::vector<Memento*> getAllPastPolicies();

private:
    Caretaker* caretaker; ///< Pointer to the caretaker managing policy history.
};

#endif // GOVERNMENTMANAGER_H
