#include <iostream>
#include <string>

int main() {
	int n;
	std::string a;
	std::cin >> n;
	while(std::cin) {
		a = "";
		std::cin >> a;
		if (a.size() > 10)
			std::cout << (a[0] + std::to_string(a.size() - 2) + a[a.size() - 1]) << std::endl;
		else 
			std::cout << a << std::endl;
	}
	return 0;
}