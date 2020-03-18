#include "task4-1.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Creating")
{
queue queue;
REQUIRE( queue.gethead() == nullptr );
REQUIRE( queue.gettail() == nullptr );
}

TEST_CASE("Creating with copy")
{
std::string result{"1  2  3  "};
queue queue2;
queue2.push(1);
queue2.push(2);
queue2.push(3);
queue queue1(queue2);
std::ostringstream ostream;
queue1.print(ostream);
REQUIRE( ostream.str() == result );

}

TEST_CASE("equals")
{
    queue queue1;
    std::string result{"1  2  3  "};
    queue1.push(6);
    queue1.push(5);
    queue1.push(4);
    queue queue2;
    queue2.push(1);
    queue2.push(2);
    queue2.push(3);
    std::ostringstream ostream;
    queue1 = queue2;
    queue1.print(ostream);
    REQUIRE( ostream.str() == result );
}

TEST_CASE("push")
{
queue queue;
std::string result{"6  5  4  "};
queue.push(6);
queue.push(5);
queue.push(4);
std::ostringstream ostream;
queue.print(ostream);
REQUIRE( ostream.str() == result );
std::string result1{"5  4  "};
queue.extraction();
std::ostringstream ostream1;
queue.print(ostream1);
REQUIRE( ostream1.str() == result1 );
}

TEST_CASE("getsize")
{
    queue queue;
    queue.push(6);
    queue.push(5);
    queue.push(4);
    REQUIRE( queue.getsize() == 3 );
}

TEST_CASE("clear")
{
    queue queue;
    std::string result{"nothing"};
    queue.push(6);
    queue.push(5);
    queue.push(4);
    queue.clear();
    REQUIRE( queue.getsize() == 0 );
    std::ostringstream ostream;
    queue.print(ostream);
    REQUIRE(ostream.str() == result);
}

TEST_CASE("Out of range")
{
queue queue;
REQUIRE_THROWS_AS( queue.extraction() , std::out_of_range);
}