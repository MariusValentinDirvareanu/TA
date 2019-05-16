#include "FactorialRecursiv.h"



FactorialRecursiv::FactorialRecursiv()
{
	std::cout << "n=";
	std::cin >> n;
	std::cout << factorial(n);
}

int FactorialRecursiv::factorial(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}


FactorialRecursiv::~FactorialRecursiv()
{
}
