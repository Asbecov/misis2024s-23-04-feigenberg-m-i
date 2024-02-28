#include "queuearr.hpp"

std::ptrdiff_t QueueArr::Size() const noexcept {
    return (head_ <= tail_ ? tail_ - head_ +  1 : capacity_ - (head_ - tail_ - 1));
}

void QueueArr::Push(const Complex& rhs) noexcept {
    if (data_ != nullptr) {
        if (Size() < capacity_) {
            data_[(tail_ < capacity_ - 1 ? ++tail_ : tail_ = 0)] = rhs;
            return;
        }

    }
    
}

void QueueArr::Pop() noexcept {
    if (Size() != 0) {
        --head_; 
    }
    return;
}

Complex& QueueArr::Top() {
    if (Size() != 0) {
        return data_[head_];
    }
    throw std::range_error("The queue is empty");
}

const Complex& QueueArr::Top() const {
    if (Size() != 0) {
        return data_[head_];
    }
    throw std::range_error("The queue is empty");   
}

bool QueueArr::IsEmpty() noexcept {
    return (Size() == 0);
}

void QueueArr::Clear() noexcept {
    if (data_ != nullptr) {
            delete[] data_;
        }
    data_ = nullptr;
    head_ = 0;
    tail_ = 0;
    capacity_ = 0;
}