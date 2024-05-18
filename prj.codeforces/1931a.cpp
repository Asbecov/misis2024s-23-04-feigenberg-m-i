#include <iostream>
#include <string>
#include <algorithm>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    int sum;
    std::cin >> sum;
    std::string a = "zzz";
    std::string ans;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (i + j + k + 3 == sum) {
                    ans += static_cast<char>('a' + i);
                    ans += static_cast<char>('a' + j);
                    ans += static_cast<char>('a' + k);
                    a = std::min(ans, a);
                }
            }
        }
    }
    std::cout << a << std::endl;
}

int main() {
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
