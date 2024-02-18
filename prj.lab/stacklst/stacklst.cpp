#include "stacklst.hpp"

void StackLST::Push(const Complex& rhs) noexcept {
	if (head_ != nullptr) {
		Node* previ = head_;
		head_ = new Node(rhs);
		head_->prev_ = previ;
		return;
	}
	head_ =  new Node(rhs);
}

void StackLST::Pop() noexcept {
	if (head_ != nullptr) {
		Node* previ = head_->prev_;
		delete head_;
		head_ = previ;
	}
}

bool StackLST::IsEmpty() noexcept {
	return (head_ == nullptr);
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


