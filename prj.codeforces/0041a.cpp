#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, d;
    std::cin >> s >> d;

    if (s.size() != d.size()) {
        std::cout << "NO";
        return 0;
    }

    int ans = 0;
    std::vector<char> V(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        V[s.size() - 1 - i] = s[i];
    }

    for (size_t i = 0; i < s.size(); ++i) {
        if (V[i] == d[i]) {
            ans += 1;
        }
    }

    if (ans == s.size()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
