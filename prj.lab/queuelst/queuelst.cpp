#include "queuelst.hpp"

void QueueLst::Push(const Complex& rhs) noexcept {
    if (last_ != nullptr) {
        last_->next_ = new Node(rhs);
        last_ = last_->next_;
        return; 
    }
    last_ = new Node(rhs);
    first_ = last_;
}

void QueueLst::Pop() noexcept {
    if (first_ != nullptr) {
        if (first_ != last_) {
            Node* temp = first_;
            first_ = temp->next_;
            delete temp;
            return;
        }
        delete first_;
        first_ = nullptr;
        last_ = nullptr;
    }
}

Complex&  QueueLst::Top() {
    return (first_->data_);
} 

const Complex&  QueueLst::Top() const {
    return (first_->data_);
}

void QueueLst::Clear() noexcept{
    delete this;
}

bool QueueLst::IsEmpty() {
    return (first_ == nullptr);
}
