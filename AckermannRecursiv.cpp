#include "AckermannRecursiv.h"



AckermannRecursiv::AckermannRecursiv()
{
	std::cout << "m= "; 
	std::cin >> m;
	std::cout << "n= "; 
	std::cin >> n;
	std::cout << "ac(" << m << ", " << n << ") =" << ac(m, n);
}

int AckermannRecursiv::ac(int m, int n)
{
	if (m == 0) { 
		return n + 1; 
	}
	else {
		if (n == 0) {
			ac(m - 1, 1);
		}
		else {
			ac(m - 1, ac(m, n - 1));
		}
	}
	return 0;
}


AckermannRecursiv::~AckermannRecursiv()
{
}
