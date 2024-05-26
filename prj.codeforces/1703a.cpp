#include <iostream>
#include <string>
#include <cctype>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int ctr = 0;
        std::string s1;
        std::cin >> s1;
        for (auto& x : s1) {
            x = std::toupper(x);
        }
        std::string y = "YES";
        for (int i = 0; i < 3; i++) {
            if (s1[i] == y[i]) {
                ctr++;
            }
        }
        if (ctr <= 2) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }
    return 0;
}
