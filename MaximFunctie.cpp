#include "MaximFunctie.h"



MaximFunctie::MaximFunctie()
{
	std::cout << Maxim() << '\n';
}

double MaximFunctie::Maxim()
{
	// determinam cu algoritm probabilist maximul unei functii f(x)=x^2-2 pe intervalul [2,3]
	do
	{
		c1 = rand(); // rand() = alege un numar intre 0 si cel mai mare intreg RAND_MAX=32767
		cout << "c1 = " << c1 << endl;
		c = a + (c1 - (b - a) * (int(double(c1) / (b - a))));
		cout << "c= " << c << endl;
		if (maximf < f(c)) {
			maximf = f(c);
		}
		k++;
	} while (k <= nrmaxit);
	return maximf;

}


MaximFunctie::~MaximFunctie()
{
}
