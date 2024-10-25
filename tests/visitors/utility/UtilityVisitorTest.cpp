#include "doctest.h"
#include "visitors/utility/UtilityVisitor.h"
#include "city/City.h"
#include "entities/utility/powerplant/PowerPlant.h"
#include "entities/utility/watersupply/WaterSupply.h"
#include "entities/utility/sewagesystem/SewageSystem.h"
#include "entities/utility/wastemanagement/WasteManagement.h"

TEST_CASE("UtilityVisitorTest - Collect utilities output and handling capacity from entities")
{
    // Create a city instance
    City *city = City::instance();

    // Create utility entities and set their output manually
    PowerPlant *powerPlant = new PowerPlant(EntityConfig(), Size::SMALL, 0, 0);
    powerPlant->setOutput(100); // 100 electricity

    WaterSupply *waterSupply = new WaterSupply(EntityConfig(), Size::SMALL, 1, 0);
    waterSupply->setOutput(50); // 50 water

    SewageSystem *sewageSystem = new SewageSystem(EntityConfig(), Size::SMALL, 2, 0);
    sewageSystem->setOutput(200); // Can handle 200 sewage

    WasteManagement *wasteManagement = new WasteManagement(EntityConfig(), Size::SMALL, 3, 0);
    wasteManagement->setOutput(150); // Can handle 150 waste

    city->addEntity(powerPlant);
    city->addEntity(waterSupply);
    city->addEntity(sewageSystem);
    city->addEntity(wasteManagement);

    // Create a UtilityVisitor instance
    UtilityVisitor utilityVisitor;

    // Let the visitor visit the city
    city->accept(utilityVisitor);

    // Check the totals collected by the UtilityVisitor
    CHECK(utilityVisitor.getTotalElectricity() == 100);   // 100 electricity
    CHECK(utilityVisitor.getTotalWater() == 50);          // 50 water
    CHECK(utilityVisitor.getTotalSewageHandled() == 200); // 200 sewage handling
    CHECK(utilityVisitor.getTotalWasteHandled() == 150);  // 150 waste handling

    city->reset();
}

TEST_CASE("UtilityVisitorTest - Empty grid produces no output or capacity")
{
    // Create an empty city grid (all nullptrs)
    City *city = City::instance();

    // Create a UtilityVisitor instance
    UtilityVisitor utilityVisitor;

    // Let the visitor visit the empty city
    city->accept(utilityVisitor);

    // Check that no output or capacity was collected
    CHECK(utilityVisitor.getTotalElectricity() == 0);
    CHECK(utilityVisitor.getTotalWater() == 0);
    CHECK(utilityVisitor.getTotalSewageHandled() == 0);
    CHECK(utilityVisitor.getTotalWasteHandled() == 0);

    city->reset();
}
