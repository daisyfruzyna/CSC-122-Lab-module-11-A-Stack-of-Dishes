#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"
#include "../src/stack.hpp"
#include "../src/dish.hpp"

TEST_CASE( "it returns Hello World" ) {
    REQUIRE( hello() == "Hello World!" );
}
/*
TEST_CASE("") {
    REQUIRE( () == "" );
}
*/
TEST_CASE("empty") {
    Stack<Dish> stack;
    REQUIRE( stack.size() == 0 );
    REQUIRE( stack.isEmpty() == true );
    stack.push(Dish("Hello World"));
    REQUIRE( stack.size() == 1 );
    REQUIRE( stack.isEmpty() == false );
}

TEST_CASE("full") {
    Stack<Dish> stack;
    REQUIRE( stack.size() == 0 );
    REQUIRE( stack.isFull() == false );
    for (int i = 0; i < 99; i++) {
        stack.push(Dish("Hello World"));
    }
    REQUIRE( stack.size() == 99 );
    REQUIRE( stack.isFull() == false );
    stack.push(Dish("Hello World"));
    REQUIRE( stack.size() == 100 );
    REQUIRE( stack.isFull() == true );
}

TEST_CASE("peek") {
    Stack<Dish> stack;
    Dish one_dish = Dish("1");
    Dish two_dish = Dish("2");
    stack.push(one_dish);
    stack.push(two_dish);
    REQUIRE( stack.peek().get_description() == two_dish.get_description() );
    REQUIRE( stack.pop().get_description() == two_dish.get_description() );
    REQUIRE( stack.peek().get_description() == one_dish.get_description() );
    REQUIRE( stack.pop().get_description() == one_dish.get_description() );
}


TEST_CASE("clear") {
    Stack<Dish> stack;
    REQUIRE( stack.size() == 0 );
    REQUIRE( stack.isEmpty() == true );
    stack.push(Dish("Hello World"));
    REQUIRE( stack.size() == 1 );
    REQUIRE( stack.isEmpty() == false );
    stack.clear();
    REQUIRE( stack.size() == 0 );
    REQUIRE( stack.isEmpty() == true );
}