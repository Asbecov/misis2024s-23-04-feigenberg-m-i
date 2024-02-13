#include "stacklst.hpp"

void StackLST::Push(const Complex& rhs) {
	if (head != nullptr) {
		head_->next_ = new Node(rhs);
		head_ = head_->next_;
		return;
	}
}

bool StackLST::IsEmpty() noexcept {
	return (first_ == nullptr)
}

