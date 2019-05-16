#include "FibonacciRecursiv.h"



FibonacciRecursiv::FibonacciRecursiv()
{
	std::cout << "n=";
	std::cin >> n;
	std::cout << fibo(n) << '\n';
}

int FibonacciRecursiv::fibo(int a) {
	if (!a) {
		return 0;
	}
	else {
		if (a == 1) {
			return 1;
		}
		else {
			return fibo(a - 2) + fibo(a - 1);
		}
	}
}


FibonacciRecursiv::~FibonacciRecursiv()
{
}
