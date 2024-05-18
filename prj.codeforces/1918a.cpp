#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    long long n, m;
    std::cin >> n >> m;
    if (n % 2 == 0 && m % 2 == 0) {
        std::cout << m / 2 * n << std::endl;
    } else if (n % 2 == 0 && m % 2 != 0) {
        if (m > 3) {
            std::cout << ((m - 3) / 2 + 1) * n << std::endl;
        } else {
            std::cout << n << std::endl;
        }
    } else if (m % 2 == 0 && n % 2 != 0) {
        std::cout << (m / 2) * n << std::endl;
    } else {
        if (m > 3) {
            std::cout << ((m - 3) / 2 + 1) * n << std::endl;
        } else {
            std::cout << n << std::endl;
        }
    }
}

int main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
