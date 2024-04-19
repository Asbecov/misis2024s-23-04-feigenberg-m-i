#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stackarrt/stackarrt.hpp>

template<class T> 
StackArrT<T> filler() {
    StackArrT<T> stack;
    for (int idx{0}; idx <= 10; idx++) {
        stack.Push(idx);
    }
    return stack;
}

template <>
StackArrT<std::string> filler() {
    StackArrT<std::string> stack;
    for (int idx{0}; idx <= 10; idx++) {
        stack.Push(std::to_string(idx));
    }
    return stack;
}

TEST_CASE("Test LIFO stack with StackArrT") {
    StackArrT<int> stack = filler<int>();
    for (int idx{10}; idx >= 0; idx--) {
        CHECK(stack.Top() == idx);
        stack.Pop();
    }
    StackArrT<double> stack_double = filler<double>();
    for (int idx{10}; idx >= 0; idx--) {
        CHECK(stack_double.Top() == idx);
        stack_double.Pop();
    }
    StackArrT<std::string> stack_str = filler<std::string>();
    for (int idx{10}; idx >= 0; idx--) {
        CHECK(stack_str.Top() == std::to_string(idx));
        stack_str.Pop();
    }
}

TEST_CASE("Test LIFO stack with StackArrT with copy constructor") {
    StackArrT<int> stack = filler<int>();
    StackArrT<int> stack_copy = stack;
    for (int idx{10}; idx >= 0; idx--) {
        CHECK(stack_copy.Top() == idx);
        stack_copy.Pop();
    }
    StackArrT<double> stack_double = filler<double>();
    StackArrT<double> stack_double_copy = stack_double;
    for (int idx{10}; idx >= 0; idx--) {
        CHECK(stack_double_copy.Top() == idx);
        stack_double_copy.Pop();
    }
    StackArrT<std::string> stack_str = filler<std::string>();
    StackArrT<std::string> stack_str_copy = stack_str;
    for (int idx{10}; idx >= 0; idx--) {
        CHECK(stack_str_copy.Top() == std::to_string(idx));
        stack_str_copy.Pop();
    }
}
