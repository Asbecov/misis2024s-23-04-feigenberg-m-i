#include <iostream>

int main() {
    int s, k;
    std::cin >> s >> k;

    for (int i = 0; i < k; ++i) {
        if (s % 10 == 0) {
            s /= 10;
        } else {
            s -= 1;
        }
    }

    std::cout << s;
    return 0;
}
