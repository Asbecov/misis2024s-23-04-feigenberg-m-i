#include "stacklst.hpp"

void StackLST::Push(const Complex& rhs) noexcept {
	if (head_ != nullptr) {
		head_->next_ = new Node(rhs);
		head_ = head_->next_;
		return;
	}
	head_ =  new Node(rhs);
	first_ = head_;
}

void StackLST::Pop() noexcept {
	if (head_ != nullptr) {
		if (head_ != first_) {
			delete head_;
			head_ = first_;
			while (head_->next_ != nullptr) {
				head_ = head_->next_;
			}
			return;
		}
		delete head_;
		head_ = nullptr;
		first_ = nullptr;
	}
}

bool StackLST::IsEmpty() noexcept {
	return (first_ == nullptr);
}

Complex& StackLST::Top() {
	if (head_ != nullptr) {
		return head_->data_;
	}
	throw std::range_error("Stack is empty");
}

const Complex& StackLST::Top() const {
	if (head_ != nullptr) {
		return head_->data_;
	}
	throw std::range_error("Stack is empty");
}


