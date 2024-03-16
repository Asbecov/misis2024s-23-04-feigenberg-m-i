#include "queuelstpr/queuelstpr.hpp"

int main() {
	try {
		QueueLstPr P1;
		for (int i{5} ; i >= 0; --i) {
			P1.Push(Complex(i));
			std::cout << P1.Top() << ' ';
		}
		std::cout << std::endl;
		QueueLstPr P2(P1);
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
		QueueLstPr P3;
		P2 = P3;
		while (!P2.IsEmpty()) {
			std::cout << P2.Top() << ' ';
			P2.Pop();
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