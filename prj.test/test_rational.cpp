#include <rational/rational.hpp>
#include <iostream>

int main() {
	// Test constructor and output operator
	Rational r1(1, 2);
	std::cout << "r1 = " << r1 << std::endl;

	// Test addition operator
	Rational r2(3, 4);
	Rational r3 = r1 + r2;
	std::cout << "r3 = " << r3 << std::endl;

	//// Test subtraction operator
	Rational r4 = r1 - r2;
	std::cout << "r4 = " << r4 << std::endl;

	// Test multiplication operator
	Rational r5 = r1 * r2;
	std::cout << "r5 = " << r5 << std::endl;

	// Test division operator
	Rational r6 = r1 / r2;
	std::cout << "r6 = " << r6 << std::endl;

	// Test equality operator
	Rational r7(1, 2);
	if (r1 == r7) {
		std::cout << "r1 equals r7" << std::endl;
	}
	else {
		std::cout << "r1 does not equal r7" << std::endl;
	}

	// Test less than operator
	Rational r8(2, 3);
	if (r1 < r8) {
		std::cout << "r1 is less than r8" << std::endl;
	}
	else {
		std::cout << "r1 is not less than r8" << std::endl;
	}

	// Test greater than operator
	Rational r9(1, 3);
	if (r1 > r9) {
		std::cout << "r1 is greater than r9" << std::endl;
	}
	else {
		std::cout << "r1 is not greater than r9" << std::endl;
	}

	// Test less than or equal to operator
	Rational r10(1, 2);
	if (r1 <= r10) {
		std::cout << "r1 is less than or equal to r10" << std::endl;
	}
	else {
		std::cout << "r1 is not less than or equal to r10" << std::endl;
	}

	// Test greater than or equal to operator
	Rational r11(3, 4);
	if (r1 >= r11) {
		std::cout << "r1 is greater than or equal to r11" << std::endl;
	}
	else {
		std::cout << "r1 is not greater than or equal to r11" << std::endl;
	}

	return 0;
}