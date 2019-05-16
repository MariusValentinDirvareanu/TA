#include "FactoriPrimiRecursiv.h"



FactoriPrimiRecursiv::FactoriPrimiRecursiv()
{
	std::cout << "n=";
	std::cin >> n;
	factori_primi(n);
}

void FactoriPrimiRecursiv::factori_primi(int n)
{
	p = 0;
	if (n % 2 == 0)
	{
		while (n % 2 == 0)
		{
			p++;
			n = n / 2;
		}
		std::cout << 2 << ' ' << p << '\n';
	}
	d = 3;
	while (n > 1)
	{
		if (n % d == 0)
		{
			p = 0;
			while (n % d == 0)
			{
				p++;
				n = n / d;
			}
			std::cout << d << ' ' << p << '\n';
		}
		else
			d += 2;
		if (n > 1 && d * d > n)
		{
			std::cout << n << ' ' << 1 << '\n';
			break;
		}
	}
}


FactoriPrimiRecursiv::~FactoriPrimiRecursiv()
{
}
