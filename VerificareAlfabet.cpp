#include "VerificareAlfabet.h"



VerificareAlfabet::VerificareAlfabet()
{
	verificare_alfabet();
}

void VerificareAlfabet::verificare_alfabet()
{ // procedura verificare alfabet
	CitireDate();

	// Verificare ca in x doar caractere din alfabet, adica numere de la 1 la m

	std::cout << "Valoarea cuvant y="; std::cin >> y;

	CompletareStraturi();
	StraturiMatrice();

	VerificareCompunere();
}

void VerificareAlfabet::VerificareCompunere()
{
	std::cout << "Pentru x = ";
	for (i = 1; i <= n; i++)
		std::cout << x[i] << " ";
	if (A[1][n][y] == 1)
	{
		std::cout << "  exista compunere astfel incat sa obtinem y = " << y << '\n';
		// TEMA: Scrieti parantezarea la fel ca la produsul de matrice
	}
	else
		std::cout << "  NU exista compunere astfel incat sa obtinem y = " << y << '\n';
}

void VerificareAlfabet::CitireDate()
{
	// citim datele
	std::cout << "Numarul de litere in alfabet m="; std::cin >> m;
	std::cout << "Citeste legea de compozitie (adica, matricea M)\n";
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			std::cin >> M.at(i).at(j);
	std::cout << "Numarul de litere din cuvant n="; std::cin >> n;
	std::cout << "Citeste cuvantul (adica, vectorul x)\n";
	for (i = 1; i <= n; i++)
		std::cin >> x.at(i);
}

void VerificareAlfabet::CompletareStraturi()
{
	// calculam matricele layer(straturi)
	// completam straturile pe diagonalele principale
	for (i = 1; i <= n; i++)
		A[i][i][x[i]] = 1;
	// completam straturile
	for (i = n - 1; i >= 1; i--)
		for (j = i + 1; j <= n; j++)
			for (a = 1; a <= m; a++)
			{
				for (k = i; k <= j - 1; k++)
				{
					// cauta l1 si l2 ai A[i][k][l1]=1 si A[k+1][j][l2]=1 si M[l1][l2]=a
					for (l1 = 1; l1 <= m; l1++)
						for (l2 = 1; l2 <= m; l2++)
						{
							if ((A[i][k][l1] == 1) && (A[k + 1][j][l2] == 1))
								if (M[l1][l2] == a)
								{
									A[i][j][a] = 1;
									A[j][i][a] = k;
								}
						}
				}
			}
}

void VerificareAlfabet::StraturiMatrice()
{
	// Scrie matricele straturi
	for (a = 1; a <= m; a++)
	{
		std::cout << "Stratul a = " << a << " este \n";
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				std::cout << A[i][j][a] << " ";
			std::cout << '\n';
		}
	}
}


VerificareAlfabet::~VerificareAlfabet()
{
}
