#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class MyObject {
public:
    int a, b;
    MyObject(int v1, int v2) {
        a = v1;
        b = v2;
    }
};

MyObject* createOnStack(int a, int b) {
    // Warning: address of stack memory associated with local
    // variable 'obj' returned [-Wreturn-stack-address]
    MyObject obj(a, b);
    return &obj;
}

MyObject* createOnHeap(int a, int b) {
    MyObject* obj_ptr = new MyObject(a, b);
    return obj_ptr;
}

TEST_CASE( "Keyword: new", "[new keyword]" ) {
    SECTION("Stack object is freed when the scope exits") {
        MyObject* obj_ptr = createOnStack(1, 2);
        REQUIRE(obj_ptr->a != 1);
        REQUIRE(obj_ptr->b != 2);

        // Not default value
        REQUIRE(obj_ptr->a != 0);
        REQUIRE(obj_ptr->b != 0);
    }
    SECTION("Heap object is freed when the program exits") {
        MyObject* obj_ptr = createOnHeap(1, 2);
        REQUIRE(obj_ptr->a == 1);
        REQUIRE(obj_ptr->b == 2);
    }
}
