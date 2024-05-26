#include <iostream>

int main() {
    int n, c = 0;
    std::cin >> n;
    int arr[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][0] == arr[j][1]) {
                c++;
            }
        }
    }
    std::cout << c << std::endl;

    return 0;
}
