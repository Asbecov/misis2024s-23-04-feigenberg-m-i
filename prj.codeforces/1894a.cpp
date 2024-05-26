#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::string str;
        std::cin >> n >> str;
        std::cout << str[n - 1] << "\n";
    }

    return 0;
}
