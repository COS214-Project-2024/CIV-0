#include "doctest.h"
#include "utils/Size.h"

TEST_CASE("SizeTest test")
{
    SUBCASE("Valid Size enum values")
    {
        Size small = Size::SMALL;
        CHECK(static_cast<int>(small) == static_cast<int>(Size::SMALL));

        Size medium = Size::MEDIUM;
        CHECK(static_cast<int>(medium) == static_cast<int>(Size::MEDIUM));

        Size large = Size::LARGE;
        CHECK(static_cast<int>(large) == static_cast<int>(Size::LARGE));
    }

    SUBCASE("Invalid Size casting")
    {
        Size invalidSize = static_cast<Size>(100); // No such Size exists
        CHECK(static_cast<int>(invalidSize) == 100);
    }
}
