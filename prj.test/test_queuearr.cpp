#include <queuearr/queuearr.hpp>
#include <iostream>

int main() {
	try {
		QueueArr P1;
		for (int i{1} ; i < 6 ; i++) {
			P1.Push(Complex(i));
			std::cout << P1.Top() << ' ';
		}
        std::cout << std::endl;
		QueueArr P2(P1);
		while (!P2.IsEmpty()) {
			std::cout << P2.Top() << ' ';
			P2.Pop();
		}
		std::cout << std::endl;
		P2 = P1;
		P1.Pop();
		P2 = P1;
		while (!P2.IsEmpty()) {
			std::cout << P2.Top() << ' ';
			P2.Pop();
		}
		std::cout << std::endl;
		QueueArr P3;
		P2 = P3;
		while (!P2.IsEmpty()) {
			std::cout << P2.Top() << ' ';
			P2.Pop();
		}
		std::cout << std::endl;
		P3 = P1;
		while (!P3.IsEmpty()) {
			std::cout << P3.Top() << ' ';
			P3.Pop();
		}
		std::cout << std::endl;
		while(!P1.IsEmpty()) {
			std::cout << P1.Top() << ' ';
			P1.Pop();
		}
		std::cout << std::endl;
	}
	catch (...) {
		std::cout << "\n bug was detected";
	}
}