#include <iostream>
#include <algorithm>
#include <cmath>

const int N = 1e5 + 10;
int g[N];

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> g[i];
        }

        std::sort(g + 1, g + n + 1);

        int a = g[n];
        int b = g[1];
        int c = g[n - 1];
        int d = g[2];

        int sum = std::abs(a - b) + std::abs(b - c) + std::abs(c - d) + std::abs(d - a);

        std::cout << sum << "\n";
    }

    return 0;
}
