#include <iostream>
#include <map>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::map<int, int> mp;
        for (int i = 1; i <= n; ++i)
        {
            int g;
            std::cin >> g;
            mp[g]++;
        }

        if (n < 3)
        {
            std::cout << 0 << "\n";
            continue;
        }

        int cnt = 0;
        for (const auto &f : mp)
        {
            if (f.second >= 3)
                cnt += f.second / 3;
        }

        std::cout << cnt << "\n";
    }

    return 0;
}
