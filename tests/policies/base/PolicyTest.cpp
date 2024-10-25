#include "doctest.h"
#include "policies/base/Policy.h"
#include  "utils/Memento.h"

/**
 * @brief Test creating and restoring the state of a Policy using Memento.
 */
TEST_CASE("Test Policy State") {
    Policy policy("Policy1", "Detail1");
    
    // Create a memento from the policy
    Memento memento = policy.createMemento();
    
    // Modify the policy state
    policy.setMemento(Memento("Policy2", "Detail2"));
    
    CHECK(policy.getName() == "Policy2");
    CHECK(policy.getDetail() == "Detail2");

    // Restore the original state
    policy.setMemento(memento);
    
    CHECK(policy.getName() == "Policy1");
    CHECK(policy.getDetail() == "Detail1");
}