#include <iostream>
#include <string>

int main() {
    std::string s;
    int ans1 = 0;
    std::cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'h' && ans1 == 0) {
            ans1++;
        }
        if (s[i] == 'e' && ans1 == 1) {
            ans1++;
        }
        if (s[i] == 'l' && ans1 == 2) {
            ans1++;
        }
        else {
            if (s[i] == 'l' && ans1 == 3) {
                ans1++;
            }
        }
        if (s[i] == 'o' && ans1 == 4) {
            ans1++;
        }
    }
    if (ans1 == 5) {
        std::cout << "YES";
        return 0;
    }
    std::cout << "NO";
}
