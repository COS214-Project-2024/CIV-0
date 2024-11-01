#include "doctest.h"
#include "policies/base/Policy.h"
#include "utils/Memento.h"

/**
 * @brief Test creating and restoring the state of a Policy using Memento.
 *
 * This test verifies that a policy can save its current state using a Memento
 * and restore it later, ensuring the correct behavior of the Memento pattern.
 */
TEST_CASE("Test Policy State") {
    Policy policy("Policy1", "Detail1");
    
    // Create a memento from the policy
    Memento* memento = policy.createMemento();

    // Modify the policy state
    Memento* temp = new Memento("Policy2", "Detail2");
    policy.setMemento(temp);
    
    CHECK(policy.getName() == "Policy2");
    CHECK(policy.getDetail() == "Detail2");

    // Restore the original state using the memento pointer
    policy.setMemento(memento);
    
    CHECK(policy.getName() == "Policy1");
    CHECK(policy.getDetail() == "Detail1");

    // Clean up dynamically allocated memory
    delete memento;
    delete temp;
}
