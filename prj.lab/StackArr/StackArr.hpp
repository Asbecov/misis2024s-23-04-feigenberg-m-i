
#ifndef STACKARRHPP09022024
#define STACKARRHPP09022024

#include <sstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <complex/complex.hpp>

class StackArr {
private:
	Complex* data_ = nullptr;
	std::ptrdiff_t capacity_;
	std::ptrdiff_t size_;
public:
	StackArr() 
		: size_(0), capacity_(2)
	{
		data_ = new Complex[capacity_];
	}
	StackArr(const StackArr&) = default;
	~StackArr() {
		delete[] data_;
		data_ = nullptr;
	}
	StackArr& operator=(const StackArr&) = default;

	void Pop() noexcept;
	void Push(const Complex&) noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();
	const Complex& Top() const;
};

#endif //STACKARRHPP09022024