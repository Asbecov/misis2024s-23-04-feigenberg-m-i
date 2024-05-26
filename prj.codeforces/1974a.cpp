#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int x, y;
        std::cin >> x >> y;

        int ans = (y + 1) / 2;
        int rem = y / 2 * 7 + y % 2 * 11;
        x = std::max(0, x - rem);
        ans += (x + 14) / 15;
        std::cout << ans << "\n";
    }

    return 0;
}
