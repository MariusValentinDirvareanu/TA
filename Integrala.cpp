#include "Integrala.h"



Integrala::Integrala()
{
	std::cout << Int() << '\n';
	std::cout << c << '\n';
}

double Integrala::Int()
{
	// determinam cu algoritm probabilist maximul unei functii f(x)=x^2-2 pe intervalul [2,3]
	do
	{
		c = (double)(rand() % (b - a + 1)) + a; // rand() = alege un numar intre 0 si cel mai mare intreg RAND_MAX=32767
		integrala += f(c);
		k++;
	} while (k <= nrmaxit);
	integrala = integrala * (double)(b - a) / nrmaxit;
	return integrala;
}


Integrala::~Integrala()
{
}
