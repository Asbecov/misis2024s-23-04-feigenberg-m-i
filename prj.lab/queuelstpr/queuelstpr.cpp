#include "queuelstpr.hpp"

void QueueLstPr::Push(const Complex& rhs) noexcept {
    if (last_ != nullptr) {
        Node* head_ = first_;
        if (head_->data_ < rhs) {
            first_ = new Node(rhs);
            first_->next_ = head_;
            return;
        }
        while((head_->next_ != nullptr) && (head_->next_->data_ > rhs)) {
            head_ = head_->next_;
        }
        Node* temp = head_->next_;
        head_->next_ = new Node(rhs);
        if (temp == nullptr) {
            last_ = head_->next_;
        } else {
            head_->next_->next_ = temp;
        }
        return;
    }
    first_ = new Node(rhs);
    last_ = first_;
}   