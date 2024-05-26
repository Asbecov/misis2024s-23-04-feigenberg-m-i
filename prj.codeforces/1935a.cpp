#include <iostream>
#include <string>
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

        std::string str;
        std::cin >> str;

        std::string res = str;
        std::reverse(str.begin(), str.end());

        if (str >= res)
        {
            std::cout << res << "\n";
        }
        else
        {
            str += res;
            std::cout << str << "\n";
        }
    }

    return 0;
}
