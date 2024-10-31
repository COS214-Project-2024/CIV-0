// #include "doctest.h"
// #include "managers/AmenityManager.h"

// TEST_CASE("AmenityManagerTest buildPark")
// {
//     AmenityManager *am = new AmenityManager();
//     Park *p = dynamic_cast<Park *>(am->buildAmenity(EntityType::PARK, Size::MEDIUM, 1, 1));
//     CHECK(p != NULL);
//     CHECK(p->getSymbol() == "P");

//     delete am;
//     delete p;
// }

// TEST_CASE("AmenityManagerTest buildMonument")
// {
//     AmenityManager *am = new AmenityManager();
//     Monument *p = dynamic_cast<Monument *>(am->buildAmenity(EntityType::MONUMENT, Size::MEDIUM, 1, 1));
//     CHECK(p != NULL);
//     CHECK(p->getSymbol() == "M");

//     delete am;
//     delete p;
// }

// TEST_CASE("AmenityManagerTest buildTheater")
// {
//     AmenityManager *am = new AmenityManager();
//     Theater *p = dynamic_cast<Theater *>(am->buildAmenity(EntityType::THEATER, Size::MEDIUM, 1, 1));
//     CHECK(p != NULL);
//     CHECK(p->getSymbol() == "T");

//     delete am;
//     delete p;
// }
