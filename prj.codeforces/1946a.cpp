#include <iostream>
#include <algorithm>

const int N = 1e5 + 10;

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int g[N];
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> g[i];
        }

        if (n == 1)
        {
            std::cout << 1 << "\n";
            continue;
        }

        int tt = n / 2 + (n % 2 != 0);

        std::sort(g + 1, g + n + 1);

        int l = 0, r = n + 1;
        while (l + 1 != r)
        {
            int mid = (l + r) / 2;
            if (g[mid] > g[tt])
                r = mid;
            else
                l = mid;
        }

        std::cout << r - tt << "\n";
    }

    return 0;
}
