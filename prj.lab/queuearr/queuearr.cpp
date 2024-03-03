#include "queuearr.hpp"

void QueueArr::Push(const Complex& rhs) noexcept {
    if (data_ != nullptr) {
        if (size_ < capacity_) {
            ++size_;
            data_[(head_ + size_ - 1) % capacity_] = rhs;
            return;
        }
        capacity_ = size_ * 2;
        Complex* new_data = new Complex[capacity_];
        std::ptrdiff_t idx{0};
        while (idx < size_) {
            new_data[idx] = data_[(head_ + idx) % capacity_];
            ++idx;
        }
        delete[] data_;
        data_ = new_data;
        return;
    }
    size_ = 1;
    capacity_ = size_ * 2;
    data_ = new Complex[capacity_];
    data_[size_] = rhs; 
}

void QueueArr::Pop() noexcept {
    if (size_ != 0) {
        (head_ < capacity_ - 1 ? ++head_ : head_ = 0);
        --size_;
    }
    if(size_ == 0) {
        head_ = 0;
    }
}

Complex& QueueArr::Top() {
    if (size_ != 0) {
        return data_[head_];
    }
    throw std::range_error("Queue is empty");
}

const Complex& QueueArr::Top() const {
    if (size_ != 0) {
        return data_[head_];
    }
    throw std::range_error("Queue is empty");
}

bool QueueArr::IsEmpty() noexcept {
    return (size_ == 0);
}

void QueueArr::Clear() noexcept {

}