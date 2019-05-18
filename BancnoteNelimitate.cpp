#include "BancnoteNelimitate.h"



BancnoteNelimitate::BancnoteNelimitate()
{
	std::cout << "Suma="; std::cin >> s;
	/*std::cout << "Numarul de bancnote:"; std::cin >> n;
	for (i = 1; i <= n; i++)
	{
		std::cout << "a[" << i << "]="; std::cin >> a[i];
	}*/
	do
	{
		inv = 0;
		for (i = 1; i <= n - 1; i++)
			if (a[i] < a[i + 1])
			{
				man = a[i];
				a[i] = a[i + 1];
				a[i + 1] = man;
			}
	} while (inv);
	i = 1;
	std::cout << s << '\n';
	do
	{
		if (s / a[i] > 0)
			std::cout << s / a[i] << " bancnote cu valoarea " << a[i] << '\n', s = s % a[i];
		i++;
	} while (i <= n);
}


BancnoteNelimitate::~BancnoteNelimitate()
{
}
