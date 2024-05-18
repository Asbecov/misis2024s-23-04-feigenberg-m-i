#include <iostream>
#include <string>

int main(){
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n, k;
        std::cin >> n >> k;

        std::string s;
        int x = 0;
        for (int i = 0; i < n * k; i++) {
            if (x <= k) {
                s.push_back('a' + i % k);
            }
        }
        std::cout << s << std::endl;
    }
    return 0;
}
