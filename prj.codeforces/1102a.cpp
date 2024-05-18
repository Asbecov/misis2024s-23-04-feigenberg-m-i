#include <iostream>

int main(){
    int n;
    std::cin >> n;
    if ((n * (n + 1) / 2) % 2 == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }
    return 0;
}
