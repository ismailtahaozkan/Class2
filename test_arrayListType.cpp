#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "arrayListType.h"

TEST_CASE("removeAt shifts elements and shrinks length", "[removeAt]") {
    arrayListType<int> lst(5);
    lst.insertEnd(1);
    lst.insertEnd(2);
    lst.insertEnd(3);
    REQUIRE(lst.listSize() == 3);

    lst.removeAt(1);
    // now [1,3]
    int x;
    lst.retrieveAt(0, x);
    REQUIRE(x == 1);
    lst.retrieveAt(1, x);
    REQUIRE(x == 3);
    REQUIRE(lst.listSize() == 2);
}

TEST_CASE("removeAll deletes every occurrence", "[removeAll]") {
    arrayListType<int> lst(10);
    for (int v : {2,1,2,3,2}) lst.insertEnd(v);
    lst.removeAll(2);
    REQUIRE(lst.listSize() == 2);
    int x;
    lst.retrieveAt(0, x);
    REQUIRE(x == 1);
    lst.retrieveAt(1, x);
    REQUIRE(x == 3);
}

TEST_CASE("min and max return correct values", "[min][max]") {
    arrayListType<int> lst(5);
    lst.insertEnd( 7 );
    lst.insertEnd( 3 );
    lst.insertEnd( 9 );
    lst.insertEnd( 5 );
    REQUIRE( lst.min() == 3 );
    REQUIRE( lst.max() == 9 );
}

TEST_CASE("min and max assert on empty list", "[min][max]") {
    arrayListType<int> lst(3);
    REQUIRE_THROWS_AS( lst.min(), std::exception );
    REQUIRE_THROWS_AS( lst.max(), std::exception );
}
