#include "bitset.hpp"

BitSet::BitSet(const std::int32_t size)
{
    size_ = size;
    bits_ = std::vector<uint32_t>(size_ / 32 + 1, 0);
}

bool BitSet::operator==(const BitSet &rhs) const noexcept
{
    return bits_ == rhs.bits_;
}

bool BitSet::operator!=(const BitSet &rhs) const noexcept
{
    return !(operator==(rhs));
}

int32_t BitSet::Size() const noexcept
{
    return size_;
}

void BitSet::Resize(const int32_t size)
{
    size_ = size;
    bits_.resize(size_ / 32 + 1);
}

bool BitSet::Get(const int32_t idx) const
{
    return bits_[idx / 32] & (1 << idx % 32) == 0 ? false : true;   
}

void BitSet::Set(const int32_t idx, const bool val)
{
    bits_[idx / 32] = val ? bits_[idx / 32] | (1 << idx % 32) : bits_[idx / 32] & ~(1 << idx % 32);
}

void BitSet::Fill(const bool val) noexcept
{
    for (uint32_t bit : bits_) {
        bit = val ? 0xFFFFFFFF : 0;
    }
}

BitSet &BitSet::operator&=(const BitSet &rhs)
{
    for (int32_t i; i < bits_.size(); ++i) {
        bits_[i] &= rhs.bits_[i];
    }
    return *this;
}

BitSet &BitSet::operator|=(const BitSet &rhs)
{
    for (int32_t i; i < bits_.size(); ++i) {
        bits_[i] |= rhs.bits_[i];
    }
    return *this;
}

BitSet &BitSet::operator^=(const BitSet &rhs)
{
    for (int32_t i; i < bits_.size(); ++i) {
        bits_[i] ^= rhs.bits_[i];
    }
    return *this;
}

BitSet BitSet::operator~()
{
    for (uint32_t bit : bits_) {
        bit = ~(bit);
    }
    return *this;
}

BitSet operator&(const BitSet &lhs, const BitSet &rhs)
{
    BitSet temp(lhs);
    return (temp &= rhs);
}

BitSet operator|(const BitSet &lhs, const BitSet &rhs)
{
    BitSet temp(lhs);
    return (temp |= rhs);
}

BitSet operator^(const BitSet &lhs, const BitSet &rhs)
{
    BitSet temp(lhs);
    return (temp ^= rhs);
}
