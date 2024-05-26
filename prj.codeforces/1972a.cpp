#include <iostream>

const int N = 110;

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int a[N], b[N];
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        int i, j;
        int cnt = 0;
        for (i = n, j = n; i >= 1 && j >= 1;)
        {
            if (a[i] <= b[j])
                --i, --j;
            else
            {
                ++cnt;
                --i;

                if (i < 1)
                    break;
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}
