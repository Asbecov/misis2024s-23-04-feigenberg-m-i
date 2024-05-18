#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::vector<char> V;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'A' && s[i] != 'O' && s[i] != 'Y' && s[i] != 'E' && s[i] != 'U' && s[i] != 'I' && s[i] != 'a' && s[i] != 'o' && s[i] != 'y' && s[i] != 'e' && s[i] != 'u' && s[i] != 'i') {
            V.push_back('.');
            V.push_back(tolower(s[i]));
        }
    }
    for (int j = 0; j < V.size(); j++) {
        std::cout << V[j];
    }
}
