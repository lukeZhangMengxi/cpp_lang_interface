#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// typedef int (*Operation)(int a, int b);
struct Formula {
    // Operation op_ptr;
    int (*op_ptr)(int a, int b);
};

int Add(int a, int b) {
    return a+b;
}

int Multi(int a, int b) {
    return a*b;
}

TEST_CASE( "Function inside struct", "[func in struct]" ) {
    Formula f;
    f.op_ptr = Add;
    REQUIRE(f.op_ptr(3, 7) == 10);

    f.op_ptr = Multi;
    REQUIRE(f.op_ptr(3, 7) == 21);
}
