#include "VerificareAlfabet.h"



VerificareAlfabet::VerificareAlfabet()
{
	verificare_alfabet();
}

void VerificareAlfabet::verificare_alfabet()
{ // procedura verificare alfabet
	// citim datele
	cout << "Numarul de litere in alfabet m="; cin >> m;
	cout << "Citeste legea de compozitie (adica, matricea M)\n";
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			cin >> M[i][j];
	cout << "Numarul de litere din cuvant n="; cin >> n;
	cout << "Citeste cuvantul (adica, vectorul x)\n";
	for (i = 1; i <= n; i++)
		cin >> x[i];

	// Verificare ca in x doar caractere din alfabet, adica numere de la 1 la m

	cout << "Valoarea cuvant y="; cin >> y;

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
	// Scrie matricele straturi
	for (a = 1; a <= m; a++)
	{
		cout << "Stratul a = " << a << " este " << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
				cout << A[i][j][a] << " ";
			cout << endl;
		}
	}

	cout << "Pentru x = ";
	for (i = 1; i <= n; i++)
		cout << x[i] << " ";
	if (A[1][n][y] == 1)
	{
		cout << "  exista compunere astfel incat sa obtinem y = " << y << endl;
		// TEMA: Scrieti parantezarea la fel ca la produsul de matrice
	}
	else
		cout << "  NU exista compunere astfel incat sa obtinem y = " << y << endl;
}


VerificareAlfabet::~VerificareAlfabet()
{
}
