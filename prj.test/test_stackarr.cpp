#include <stackarr/stackarr.hpp>

int main() {
	try {
		StackArr P1;
		for (int i{0} ; i < 6 ; i++) {
			P1.Push(Complex(i));
		}
		StackArr P2(P1);
		while (!P2.IsEmpty()) {
			std::cout << P2.Top() << std::endl;
			P2.Pop();
		}
		P2 = P1;
		while (!P2.IsEmpty()) {
			std::cout << P2.Top() << std::endl;
			P2.Pop();
		}
		while(!P1.IsEmpty()) {
			std::cout << P1.Top() << std::endl;
			P1.Pop();
		}
	}
	catch (...) {
		std::cout << "\n bug was detected";
	}
}
 
