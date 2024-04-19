#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stacklst/stacklst.hpp>
#include "doctest.h"

TEST_CASE("Test constructors") {
	StackLst P1;
	CHECK(P1.IsEmpty());
	StackLst P2(P1);
	CHECK(P2.IsEmpty());
	StackLst P3;
	P3 = P1;
	CHECK(P3.IsEmpty());
}

TEST_CASE("Test LIFO stack with StackLst") {
	StackLst P1;
	for (int i{1} ; i < 6 ; i++) {
		P1.Push(Complex(i));
	}
	StackLst P2(P1);
	for(int i{5} ; i > 0 ; i--) {
		CHECK(P2.Top() == Complex(i));
		P2.Pop();
	}
	P2 = P1;
	P1.Pop();
	P2 = P1;
	for(int i{4} ; i > 0 ; i--) {
		CHECK(P2.Top() == Complex(i));
		P2.Pop();
	}
	StackLst P3;
	P2 = P3;
	CHECK(P2.IsEmpty());
}
 