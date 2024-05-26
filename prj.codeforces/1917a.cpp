#include <iostream>

const int N = 1e4 + 10;
int g[N];

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int f1 = 0;
        bool zero_found = false;

        for (int i = 1; i <= n; ++i)
        {
            std::cin >> g[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            if (g[i] < 0)
                f1++;
            else if (g[i] == 0)
            {
                zero_found = true;
                break;
            }
        }

        if (zero_found)
        {
            std::cout << 0 << "\n";
        }
        else if (f1 % 2 == 1)
        {
            std::cout << 0 << "\n";
        }
        else
        {
            std::cout << 1 << "\n";
            std::cout << 1 << ' ' << 0 << "\n";
        }
    }

    return 0;
}
