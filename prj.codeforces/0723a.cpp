#include <iostream>
#include <cmath>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int p = std::min(std::abs(a - b), std::abs(b - c));
    int s = std::max(std::abs(a - b), std::abs(b - c));
    int q = std::min(s, std::abs(c - a));

    std::cout << p + q;

    return 0;
}
