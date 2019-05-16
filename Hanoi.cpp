#include "Hanoi.h"



Hanoi::Hanoi()
{
	std::cout << "n="; 
	std::cin >> n;
	hanoiRez(n, 'a', 'b', 'c');
}

void Hanoi::hanoiRez(int n, char a, char b, char c)
{
	if (n == 1) std::cout << a << b << " ";
	else
	{
		hanoiRez(n - 1, a, c, b);
		std::cout << a << b << " ";
		hanoiRez(n - 1, c, b, a);
	}
}


Hanoi::~Hanoi()
{
}
