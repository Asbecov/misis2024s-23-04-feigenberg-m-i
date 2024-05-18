#include <iostream>

int main(){
    int tc;
    std::cin >> tc;
    while (tc--) {
        int b, c, h;
        std::cin >> b >> c >> h;
        if (b >= (c + h + 1)) {
            std::cout << 2 * (c + h) + 1 << std::endl;
        } else {
            std::cout << 2 * b - 1 << std::endl;
        }
    }
    return 0;
}
