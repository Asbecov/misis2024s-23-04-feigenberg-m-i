#include <iostream>

int n;

int main() {
    std::cin >> n;
    if (n < 6 || n % 2 == 1) {
        std::cout << 0;
    } else {
        if ((n / 2) % 2 == 0) {
            std::cout << (n / 2 - 2) / 2;
        } else {
            std::cout << (n / 2 - 1) / 2;
        }
    }
    return 0;
}
