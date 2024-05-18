#include <iostream>
#include <cmath>

void solve() {
    int n;
    std::cin >> n;
    long long a[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (ceil(sqrt(static_cast<double>(sum))) == floor(sqrt(static_cast<double>(sum)))) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
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
