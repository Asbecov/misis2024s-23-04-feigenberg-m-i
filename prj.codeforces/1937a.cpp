#include <iostream>

typedef long long Long;

void solve() {
    int n;
    std::cin >> n;
    int now = 1;
    while(now*2 <= n) now *= 2;
    std::cout << now << '\n';
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int tc = 1;
    std::cin >> tc;
    for(int kase = 1; kase <= tc; kase++) {
        solve();
    }
    return 0;
}