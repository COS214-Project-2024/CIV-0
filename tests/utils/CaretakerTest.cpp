#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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