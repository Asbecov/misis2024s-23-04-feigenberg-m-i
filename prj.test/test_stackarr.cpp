#include <stackarr/StackArr.hpp>

int main() {
	try {
		StackArr P1;
		Complex P2(5.0 , 4.0);
		P1.Push(P2);
		std::cout << P1.Top() << ' ' << std::endl;
		P1.Pop();
		std::cout << P1.IsEmpty();
	}
	catch (...) {
		std::cout << "\n bug was detected";
	}
}
 
