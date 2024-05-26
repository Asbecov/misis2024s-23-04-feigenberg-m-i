#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    
    while (t--)
    {
        int n = 0, ans = 0;
        std::cin >> n;
        
        for (int i = 1; i <= n; ++i)
        {
            int a, b;
            std::cin >> a >> b;
            if (a > b)
            {
                ++ans;
            }
        }
        
        std::cout << ans << "\n";
    }
    
    return 0;
}
