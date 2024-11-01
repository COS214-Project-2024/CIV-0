#ifndef POLICYTYPE_H
#define POLICYTYPE_H

/**
 * @enum PolicyType
 * @brief Enumerates different policy types for water and electricity usage.
 *
 * This enumeration is used in the City and GovernmentManager classes to specify and enact different
 * water and electricity usage policies in the City.
 */
enum class PolicyType {
    LOW_WATER_POLICY,       ///< Represents a low water usage policy.
    NORMAL_WATER_POLICY,    ///< Represents a normal water usage policy.
    HIGH_WATER_POLICY,      ///< Represents a high water usage policy.
    LOW_ELECTRICITY_POLICY, ///< Represents a low electricity usage policy.
    NORMAL_ELECTRICITY_POLICY, ///< Represents a normal electricity usage policy.
    HIGH_ELECTRICITY_POLICY ///< Represents a high electricity usage policy.
};

#endif // POLICYTYPE_H
