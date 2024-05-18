#include <iostream>

int main() {
    int n, k, ans = 0;
    std::cin >> n >> k;
    k = (240 - k);
    for (int i = 1; i <= n; i++) {
        if ((5 * i) <= k) {
            k -= (5 * i);
            ans++;
        }
    }
    std::cout << ans;
}