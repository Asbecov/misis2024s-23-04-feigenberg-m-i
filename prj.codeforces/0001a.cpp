#include <iostream>
#include <cmath>


int main() {
    long long n, m, a;
    std::cin >> n >> m >> a;
    if (n % a == 0) {
        if (m % a == 0) {
            std::cout << (n / a) * (m / a);
        } else {
            std::cout << ((n / a) + (((m - (m % a)) / a) * ((n - (n % a)) / a)));
        }
    } else {
        if (m % a == 0) {
            std::cout << ((m / a) + (((m - (m % a)) / a) * ((n - (n % a)) / a)));
        } else {
            std::cout << ((((n - (n % a)) + (m - (m % a))) / a) + (((m - (m % a)) / a) * ((n - (n % a)) / a)) + 1);
        }
    }
}
