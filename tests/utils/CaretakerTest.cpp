#include "doctest.h"
#include "utils/Caretaker.h"
#include "utils/Memento.h"

/**
 * @brief Test storing and retrieving Mementos in Caretaker.
 */
TEST_CASE("Test Memento Storage in Caretaker") {
    Caretaker caretaker;
    
    Memento* m1 = new Memento("Policy1", "Detail1");
    Memento* m2 = new Memento("Policy2", "Detail2");
    
    caretaker.setMemento(m1);
    caretaker.setMemento(m2);

    // Retrieve the most recent memento (m2)
    Memento* retrieved = caretaker.getMemento();
    
    CHECK(retrieved->getName() == "Policy2");
    CHECK(retrieved->getDetail() == "Detail2");

}

/**
 * @brief Test retrieving all past mementos stored in the Caretaker.
 *
 * This test verifies that all mementos stored in the caretaker are accessible
 * through the getPastPolicies method in the correct order.
 */
TEST_CASE("Test getPastPolicies in Caretaker") {
    Caretaker caretaker;
    
    Memento* m1 = new Memento("Policy1", "Detail1");
    Memento* m2 = new Memento("Policy2", "Detail2");
    Memento* m3 = new Memento("Policy3", "Detail3");
    
    caretaker.setMemento(m1);
    caretaker.setMemento(m2);
    caretaker.setMemento(m3);

    // Retrieve all past mementos
    std::vector<Memento*> pastPolicies = caretaker.getPastPolicies();
    
    REQUIRE(pastPolicies.size() == 3); // Ensure three mementos are stored
    
    // Check that each memento is stored in the correct order
    CHECK(pastPolicies[0]->getName() == "Policy1");
    CHECK(pastPolicies[0]->getDetail() == "Detail1");

    CHECK(pastPolicies[1]->getName() == "Policy2");
    CHECK(pastPolicies[1]->getDetail() == "Detail2");

    CHECK(pastPolicies[2]->getName() == "Policy3");
    CHECK(pastPolicies[2]->getDetail() == "Detail3");
    
    // Clean up dynamically allocated Mementos
    for (Memento* memento : pastPolicies) {
        delete memento;
    }
}