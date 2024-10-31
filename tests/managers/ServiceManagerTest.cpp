 #include "doctest.h"
 #include "managers/ServiceManager.h"

TEST_CASE("ServiceManagerTest buildSchool") {
    ServiceManager sm;
    City* c = City::instance();
    sm.buildService(EntityType::SCHOOL,Size::LARGE,23,23);
    CHECK(dynamic_cast<School*>(c->getEntity(23,23)) != NULL);
}

TEST_CASE("ServiceManagerTest buildHospital") {
    ServiceManager sm;
    City* c = City::instance();
    sm.buildService(EntityType::HOSPITAL,Size::MEDIUM,12,12);
    CHECK(dynamic_cast<Hospital*>(c->getEntity(12,12)) != NULL);
}

TEST_CASE("ServiceManagerTest buildPoliceStation") {
    ServiceManager sm;
    City* c = City::instance();
    sm.buildService(EntityType::POLICESTATION,Size::SMALL,5,5);
    CHECK(dynamic_cast<PoliceStation*>(c->getEntity(5,5)) != NULL);
}

