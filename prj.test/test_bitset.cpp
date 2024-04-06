#include <bitset/bitset.hpp>
#include <iostream>
#include <bitset>


int main() {
    try {
        BitSet P1 (15);
        P1.Fill(0);
        P1.Set(2, 1);
        for (int32_t idx{0}; idx < P1.Size(); ++idx) {
            std::cout << P1.Get(idx);
        }
        std::cout << std::endl;
        std::cout << std::bitset<8>((1 << 2 % 32));
    }
    catch (...) {
        std::cout << "Error was found\n";
    }
}