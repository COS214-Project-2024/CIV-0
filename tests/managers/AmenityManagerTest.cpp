#include "doctest.h"
#include "managers/AmenityManager.h"
#include "city/City.h"

TEST_CASE("AmenityManagerTest buildPark") {
    City* c = City::instance();
    c->reset();
    AmenityManager am;
    am.buildAmenity(EntityType::PARK,Size::SMALL,5,5);
    CHECK(dynamic_cast<Park*>(c->getEntity(5,5)) != nullptr);
}

TEST_CASE("AmenityManagerTest buildMonument") {
    City* c = City::instance();
    c->reset();
    AmenityManager am;
    am.buildAmenity(EntityType::MONUMENT,Size::LARGE,24,24);
    CHECK(dynamic_cast<Monument*>(c->getEntity(24,24)) != nullptr);
}

TEST_CASE("AmenityManagerTest buildTheater") {
    City* c = City::instance();
    c->reset();
    AmenityManager am;
    am.buildAmenity(EntityType::THEATER,Size::MEDIUM,11,11);
    CHECK(dynamic_cast<Theater*>(c->getEntity(11,11)) != nullptr);
}