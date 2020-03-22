#include "task4-1.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Creating")
{
    queue queue;
    REQUIRE( queue.gethead() == nullptr );
    REQUIRE( queue.gettail() == nullptr );
}

TEST_CASE("Push")
{
    queue queue;
    int val;
    for (int i = 1; i < 3000; i++) {
        val = 1 + rand() % 100;
        queue.push(val);
        REQUIRE( queue.gettail()->value == val );
        REQUIRE( queue.getsize() == i );
    }
}

TEST_CASE("Getsize")
{
    queue queue;
    for (int i = 1; i < 3000; i++)
    {
        queue.push(1 + rand() % 10);
        REQUIRE( queue.getsize() == i );
    }

}

TEST_CASE("Clear")
{
    queue queue;
    for (int i = 1; i < 3000; i++)
    {
        queue.push(1 + rand() % 10);
        REQUIRE( queue.getsize() == i );
    }
    queue.clear();
    REQUIRE( queue.getsize() == 0 );
}

TEST_CASE("Extraction")
{
    queue queue;
    int val;

    for (int i = 1; i < 500; i++) {
        val = 1 + rand() % 100;
        queue.push(val);
        REQUIRE( queue.gettail()->value == val );
        REQUIRE( queue.getsize() == i );
    }

    queue::node_t * head;
    for (int i = 498; i >= 0; i--) {
        head = queue.gethead()->next;
        queue.extraction();
        REQUIRE( queue.gethead() == head );
        REQUIRE( queue.getsize() == i );
    }

    for (int i = 0; i < 100; i++) REQUIRE_THROWS_AS( queue.extraction() , std::out_of_range);
}

TEST_CASE("Out of range")
{
    queue queue;
    for (int i = 0; i < 100; i++)
    {
        REQUIRE( queue.getsize() == 0 );
        REQUIRE_THROWS_AS( queue.extraction() , std::out_of_range);
    }
}