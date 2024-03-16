#include "queuelstpr.hpp"

void QueueLstPr::Push(const Complex& rhs) noexcept {
    if (last_ != nullptr) {
        Node* head_ = first_;
        while((head_->next_ != nullptr ? head_->next_->data_ < rhs: true)) {
            head_ = head_->next_;
        }
        Node* temp = head_->next_;
        head_->next_ = new Node(rhs);
        head_->next_->next_ = temp;
        return;
    }
    first_ = new Node(rhs);
    last_ = first_;
}   