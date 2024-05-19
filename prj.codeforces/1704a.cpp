#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::string a, b;
        std::cin >> n >> m >> a >> b;

        if (a.size() < b.size()) {
            std::cout << "No\n";
            continue;
        }

        std::vector<int> cnt(2, 0); 

        for (int i = 0; i <= n - m; ++i) {
            cnt[0] += (a[i] == '0');
            cnt[1] += (a[i] == '1');
        }

        if ((b[0] == '1' && cnt[1] == 0) || (b[0] == '0' && cnt[0] == 0)) {
            std::cout << "No\n";
            continue;
        }
        
        bool matched = true;
        for (int i = 1; i < m; ++i) {
            if (b[i] != a[n - m + i]) {
                std::cout << "No\n";
                matched = false;
                break;
            }
        }

        if (matched) {
            std::cout << "Yes\n";
        }
    }

    return 0;
}
