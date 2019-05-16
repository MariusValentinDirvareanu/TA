#include "SumaTriunghi.h"



SumaTriunghi::SumaTriunghi()
{
	Suma_max_triunghi();
}

void SumaTriunghi::Suma_max_triunghi()
{
	std::cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			std::cout << "t[" << i << "," << j << "]";
			std::cin >> t[i][j];
			for (j = 1; j <= n; j++)
				c[n][j] = t[n][j];
			for (i = n - 1; i >= 1; i--)
				for (j = 1; j <= i; j++)
					if (c[i + 1][j] << c[i + 1][j + 1])
					{
						c[i][j] = t[i][j] + c[i + 1][j + 1];
						drum[i][j] = j + 1;
					}
					else
					{
						c[i][j] = t[i][j] + c[i + 1][j];
						drum[i][j] = i;
					}
			std::cout << "suma maxima=" << c[1][1] << std::endl;
			i = 1;
			j = 1;
			while (i <= n)
			{
				std::cout << t[i][j] << std::endl;
				j = drum[i][j];
				i++;
			}
		}
}


SumaTriunghi::~SumaTriunghi()
{
}
