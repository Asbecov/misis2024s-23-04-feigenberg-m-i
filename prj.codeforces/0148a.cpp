#include <iostream>
#include <vector>

int main() {
    int k, l, m, n, d;
    std::cin >> k >> l >> m >> n >> d;

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        std::cout << d;
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= d; ++i) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            ++ans;
        }
    }

    std::cout << ans;
    return 0;
}
