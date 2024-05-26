#include <iostream>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        long long p1, p2, p3;
        std::cin >> p1 >> p2 >> p3;

        long long sum = p1 + p2 + p3;

        if (sum % 2 != 0)
        {
            std::cout << -1 << "\n";
        }
        else
        {
            std::cout << std::min(p1 + p2, sum / 2) << "\n";
        }
    }

    return 0;
}
