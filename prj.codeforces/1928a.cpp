#include <iostream>

const int N = 1e5 + 10, M = 5100;

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        long long n, m;
        std::cin >> n >> m;
        
        if ((n % 2 == 0 && n / 2 != m) || (m % 2 == 0 && m / 2 != n))
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
