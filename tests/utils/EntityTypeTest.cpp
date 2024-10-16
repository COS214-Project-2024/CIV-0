#include "doctest.h"
#include "utils/EntityType.h"

TEST_CASE("EntityTypeTest test")
{
    SUBCASE("Valid EntityType enum values")
    {
        EntityType house = EntityType::HOUSE;
        CHECK(static_cast<int>(house) == static_cast<int>(EntityType::HOUSE));

        EntityType factory = EntityType::FACTORY;
        CHECK(static_cast<int>(factory) == static_cast<int>(EntityType::FACTORY));

        EntityType theater = EntityType::THEATER;
        CHECK(static_cast<int>(theater) == static_cast<int>(EntityType::THEATER));
    }

    SUBCASE("Invalid EntityType casting")
    {
        EntityType invalidEntity = static_cast<EntityType>(100); // No such EntityType exists
        CHECK(static_cast<int>(invalidEntity) == 100);
    }
}
