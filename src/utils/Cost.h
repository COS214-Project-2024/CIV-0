#ifndef COST_H
#define COST_H

/**
 * @struct Cost
 * @brief Represents the cost of resources for building or upgrading an entity.
 *
 * This structure holds the resource requirements in terms of money, wood, stone, and concrete.
 * It provides a constructor for initializing costs and an overloaded equality operator for comparing costs.
 */
struct Cost
{
    int moneyCost;      /**< The amount of money required */
    int woodCost;       /**< The amount of wood required */
    int stoneCost;      /**< The amount of stone required */
    int concreteCost;   /**< The amount of concrete required */

    /**
     * @brief Constructs a Cost object with optional initial values.
     * @param money Initial money cost (default is 0)
     * @param wood Initial wood cost (default is 0)
     * @param stone Initial stone cost (default is 0)
     * @param concrete Initial concrete cost (default is 0)
     */
    Cost(int money = 0, int wood = 0, int stone = 0, int concrete = 0)
        : moneyCost(money), woodCost(wood), stoneCost(stone), concreteCost(concrete) {}

    /**
     * @brief Overloaded equality operator to compare two Cost objects.
     * @param other The other Cost object to compare with
     * @return true if all cost components are equal, false otherwise
     */
    bool operator==(const Cost& other) const {
        return moneyCost == other.moneyCost &&
               woodCost == other.woodCost &&
               stoneCost == other.stoneCost &&
               concreteCost == other.concreteCost;
    }
};

#endif // COST_H