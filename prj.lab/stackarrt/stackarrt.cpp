#include "stackarrt.hpp"

template<typename T>
void StackArrT<T>::Pop() noexcept {
	if (size_ != 0) {
		--size_;
	}
}

template<typename T>
void StackArrT<T>::Push(const T& rhs) noexcept {
	if (size_ < capacity_) {
		data_[size_] = rhs;
		++size_;
		return;
	}
	capacity_ = (size_ + 1) * 2;
	T* new_data_ = new T[capacity_];
	for (std::ptrdiff_t i(0); i < size_; i++) {
		new_data_[i] = data_[i];
	}
	delete[] data_;
	data_ = new_data_;
	new_data_ = nullptr;
	data_[size_] = rhs;
	++size_;
}

template<typename T>
bool StackArrT<T>::IsEmpty() noexcept{
	return (size_ == 0);
}

template<typename T>
T& StackArrT<T>::Top() {
	if (size_ != 0) {
		return data_[size_ - 1];
	}
	throw std::range_error("Stack is empty");
}

template<typename T>
const T& StackArrT<T>::Top() const {
	if (size_ != 0) {
		return data_[size_ - 1];
	}
	throw std::range_error("Stack is empty");
}