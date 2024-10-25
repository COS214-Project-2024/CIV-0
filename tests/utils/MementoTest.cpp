#include "doctest.h"
#include "utils/Memento.h"

/**
 * @brief Test creation and retrieval of Memento details.
 */
TEST_CASE("Test Memento Creation") {
    Memento memento("Policy1", "Detail1");
    
    // Test initial state
    CHECK(memento.getName() == "Policy1");
    CHECK(memento.getDetail() == "Detail1");
}

/**
 * @brief Test modifying the state of Memento.
 */
TEST_CASE("Test Memento Modification") {
    Memento memento("Policy1", "Detail1");
    
    // Modify state
    memento.setName("Policy2");
    memento.setDetail("Detail2");

    CHECK(memento.getName() == "Policy2");
    CHECK(memento.getDetail() == "Detail2");
}