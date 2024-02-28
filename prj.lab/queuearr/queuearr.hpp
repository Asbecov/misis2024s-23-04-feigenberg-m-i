#pragma once
#ifndef QUEUEARRHPP27022024
#define QUEUEARRHPP27022024

#include <complex/complex.hpp>
#include <cstddef>
#include <stdexcept>

class QueueArr {
private:
    std::ptrdiff_t head_{0};
    std::ptrdiff_t tail_{0};
    std::ptrdiff_t capacity_{0};
    Complex* data_{nullptr};
public:
    QueueArr() = default;
    ~QueueArr() {
        if (data_ != nullptr) {
            delete[] data_;
        }
        data_ = nullptr;
    }
    QueueArr(const QueueArr& rhs)
        : head_{rhs.head_}, tail_{rhs.tail_}, capacity_{rhs.capacity_}
    {
        data_ = new Complex[capacity_];
        std::copy(rhs.data_, rhs.data_ + capacity_, data_);
    }
    QueueArr operator=(const QueueArr& rhs) {
        if (this != &rhs) {
            
        }
        return *this;
    }

    std::ptrdiff_t Size() const noexcept;
    void Push(const Complex&) noexcept;
    void Pop() noexcept;
    Complex& Top();
    const Complex& Top() const;
    bool IsEmpty() noexcept;
    void Clear() noexcept;
};

#endif //QUEUEARRHPP27022024