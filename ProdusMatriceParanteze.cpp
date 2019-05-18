#include "ProdusMatriceParanteze.h"



ProdusMatriceParanteze::ProdusMatriceParanteze()
{
	matrice_parantezare();
}

void ProdusMatriceParanteze::produs_M(int n, int p[10], int M[10][10])
{
	for (i = n - 1; i >= 1; i--)
	{
		for (j = i + 1; j <= n; j++)
		{
			//k ia valori i,i+1,...,j01
			mini = p[i] * p[i + 1] * p[j + 1] + M[i + 1][j];
			k0 = i;
			for (k = i + 1; k < j; k++)
			{
				int d = M[i][k] + M[i + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (mini > d)
				{
					mini = d;
					k0 = k;
				}
			}
			M[i][j] = mini;
			M[j][i] = k0;
		}
	}
}
void ProdusMatriceParanteze::produs_parantezare(int i, int j, int M[10][10])
{
	//afiseaza parantezarea intre Ai si Aj (cu nr de inmultiri minim)
	if (i < j)
	{
		int k = M[j][i];
		if (k != i)
		{
			std::cout << "(";
			produs_parantezare(i, k, M);
			std::cout << ")";
		}
		else produs_parantezare(i, k, M);
		std::cout << "*";
		if ((k + 1) != j)
		{
			std::cout << "(";
			produs_parantezare(k + 1, j, M);
			std::cout << ")";
		}
		else produs_parantezare(k + 1, j, M);
	}
	else std::cout << "A" << i;
}
void ProdusMatriceParanteze::matrice_parantezare()
{
	std::cout << "n="; std::cin >> n;
	for (ii = 1; ii <= n + 1; ii++)
	{
		std::cout << "p[" << ii << "]= "; std::cin >> p[ii];
	}
	produs_M(n, p, M);
	std::cout << M[1][n] << '\n';
	produs_parantezare(1, n, M);
}


ProdusMatriceParanteze::~ProdusMatriceParanteze()
{
}
