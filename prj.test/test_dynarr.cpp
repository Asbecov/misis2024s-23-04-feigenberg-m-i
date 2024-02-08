#include <dynarr/dynarr.hpp>
#include <iostream>

int main() {
	DynArr M1(10);
	for (int i(0); i < M1.Size(); i++) {
		M1[i] = i;
	}
	for (int i(-1); i >= -M1.Size(); i--) {
		std::cout << M1[i];
	}
	std::cout << std::endl;
	try {
		std::cout << M1[M1.Size() + 1];
	}
	catch (const std::out_of_range& exception) {
		std::cout << exception.what() << ' ';
	}
	try {
		std::cout << M1[-M1.Size() - 1];
	}
	catch (const std::out_of_range& exception) {
		std::cout << exception.what() << ' ';
	}
	try {
		std::cout << M1.Capacity() << ' ' << M1[M1.Size() - 1] << ' ' << M1.Size() << ' ' << std::endl;
		for (int i(0); i < 11; i++) {
			M1.PushBack(i);
		}
		std::cout << M1.Capacity() << ' ' << M1[M1.Size() - 1] << ' ' << M1.Size() << ' ' << std::endl;
		M1.PopBack();
		std::cout << M1.Capacity() << ' ' << M1[M1.Size() - 1] << ' ' << M1.Size() << ' ' << std::endl;
	}
	catch (const std::bad_alloc& exception) {
		std::terminate();
	}
	catch (...) {
		std::cout << "Error catched";
	}
}