#include <iostream>
#include <cmath>

using namespace std;

// program pentru Teoria Algoritmilor

float f(float x)
{
	return x * x - 2;
}

float df(float x)
{
	return 2 * x;
}

void rezolvare_ecuatie()
{
	float a, b, eps, a0, b0, m;
	float x0, x1, ert;
	int nrit = 0;
	// Metoda bisectiei
	cout << " a= "; cin >> a;
	cout << " b= "; cin >> b;
	cout << " eps= "; cin >> eps;

	cout << "Iteratia" << "  Aprox. cu metoda bisectiei " << " Metoda tangentei " << endl;
	cout << "_______________________________________________________________" << endl;

	// initializare metoda bisectiei;
	a0 = a; b0 = b;
	// initializaremetoda tangentei
	x0 = b;
	// cout<<nrit<<"   [ "<<a0<<" , "<<b0<<" ]    "<<x0<<endl;
	printf("%4d      [ %12.10f , %12.10f ]     %12.10f\n", nrit, a0, b0, x0);


	do
	{
		// calcule pentru metoda bisectiei
		m = (a0 + b0) / 2;
		if (f(m) == 0)
		{
			cout << "Solutia este " << m;
			break;
		}
		else
		{
			if (f(a0) * f(m) < 0)
				b0 = m;
			else
				a0 = m;
		}
		//  calcule cu metoda tangentei
		x1 = x0 - f(x0) / df(x0);
		ert = fabs(x1 - x0);
		x0 = x1;

		nrit++;
		//cout<<nrit<<"   [ "<<a0<<" , "<<b0<<" ]    "<<x0<<endl;
		printf("%4d      [ %12.10f , %12.10f ]     %12.10f\n", nrit, a0, b0, x0);
	} while (((b0 - a0) >= eps) || (ert > eps));
	cout << "Solutia se afla in intervalul [" << a0 << "," << b0 << "]" << endl;
	cout << " si poate fi aproximata prin valoarea " << (a0 + b0) / 2;
}

void permutari()
{
	int n;

	cout << " Permutari de n = "; cin >> n;
}

// pentru functia Ackermann
struct v {
	int val;
	v* prec;
	v* urm;
};

void parcurgere_lista(v * p, v * u)
{
	v* q;
	if (p == NULL)
		cout << "Lista este vida!" << endl;
	else
	{
		q = p;
		while (q != NULL)
		{
			cout << q->val << " ";
			q = q->urm;
		}
		cout << endl;
	}
}

int Ackermann_liste(int m, int n)
{
	v* p, * u, * q;

	//initializare lista dublu inlantuita
	//primul element
	p = new v;
	p->val = m;
	p->prec = NULL;
	//ultimul element
	u = new v;
	u->val = n;
	u->urm = NULL;
	p->urm = u;
	u->prec = p;
	parcurgere_lista(p, u);

	int k = 2; // numarul de elemnte din lista
	while (k > 1)
	{
		if (u->prec->val == 0) // ac(0,n)=n+1
		{
			u->prec->val = u->val + 1;
			q = u;
			u = u->prec;
			u->urm = NULL;
			k--;
			delete q;
		}
		else
		{
			if (u->val == 0) // ac(m,0)=ac(m-1,1)
			{
				u->val = 1;
				u->prec->val = u->prec->val - 1;
			}
			else  // ac(m,n)=ac(m-1,ac(m,n-1))
			{
				q = new v;
				q->val = u->val - 1;
				q->prec = u;
				q->urm = NULL;
				u->val = u->prec->val;
				u->prec->val = u->prec->val - 1;
				u->urm = q;
				u = q;
				k++;
			}
		}
		parcurgere_lista(p, u);
	}
	return p->val;
}

void verificare_alfabet()
{ // procedura verificare alfabet
	int m, n, M[10][10], x[30], i, j, k, a, l1, l2, y;
	int A[30][30][10] = { 0 };

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
		// TEMA: Scrietiparantezarea la fel ca la produsul de matrice
	}
	else
		cout << "  NU exista compunere astfel incat sa obtinem y = " << y << endl;
}

int main() // PROGRAM PRINCIPAL
{
	int op, op1, op2, op3, op4, op5, op6;

	do  // reia meniu principal pana la exit
	{
		// meniu principal
		cout << "PROGRAME TA " << endl;
		cout << "1. Probleme diverse" << endl;
		cout << "2. Backtracking" << endl;
		cout << "3. Metoda recursiva" << endl;
		cout << "4. Metoda Divide et Impera" << endl;
		cout << "5. Metoda Greedy" << endl;
		cout << "6. Programare dinamica" << endl;
		// se vor adauga optiuni
		cout << "0. Exit program." << endl;

		cout << "Optiune : "; cin >> op;

		switch (op) // switch pentruoptiune meniu principal
		{

		case 1: //Probleme diverse (laborator 1)
			do
			{
				cout << endl << "Probleme diverse" << endl;
				cout << "1.1. Calculul unor norme matriciale" << endl;
				cout << "1.2. Rezolvarea aproximativa pentru o ecuatie algebrica in R" << endl;
				cout << "1.0. Exit probleme diverse!" << endl;

				cout << "Optiune probleme diverse : "; cin >> op1;

				switch (op1)
				{
				case 1:
					// norme();
					break;

				case 2:
					rezolvare_ecuatie();
					break;

				case 0:
					cout << "A terminat submeniu 1" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op1 != 0);
			break;

		case 2: //Backtracking
		{


			do
			{
				cout << endl << "Backtracking" << endl;
				cout << "2.1. Generarea permutarilor " << endl;
				cout << "2.2. Generarea combinarilor " << endl;
				cout << "2.3. Generarea aranjamentelor " << endl;
				cout << "2.4. Problema reginelor" << endl;
				cout << "2.5. Problema parantezelor" << endl;
				cout << "2.6. Problema comisului voiajor" << endl;
				cout << "2.0. Exit Backtracking." << endl;
				cout << "Optiune Backtracking: "; cin >> op2;
				switch (op2)
				{
				case 1: //permutari
					permutari();
					break;

				case 2:
					// Combinari
				{

				}
				break;

				case 0:
					cout << "A terminat submeniu Backtracking" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op2 != 0);
		}
		break;

		case 3: //Recursivitate
			do
			{
				cout << endl << "Recursivitate" << endl;
				cout << " 3.1. Calculul factorialului" << endl;
				cout << " 3.2. Calculul sirului Fibonacci" << endl;
				cout << " 3.3. Functia Ackermann - recursiv " << endl;
				cout << " 3.4. Functia Ackermann - iterativ cu vector sau lista" << endl;
				cout << " 3.5. Calculul numarului de partitii cu k submultimi " << endl;
				cout << "        ale unei multimi cu n elemente " << endl;
				cout << " 3.6. Determinare permutari de n - recursiv" << endl;
				cout << " 3.7. Problema reginelor - recursiv" << endl;
				cout << " 3.8. Descompunere in factori -  recursiv" << endl;
				cout << " 3.9. Recursivitate indirecta: miscare pe ecran" << endl;
				cout << "3.10. Problema labirintului" << endl;
				cout << " 3.0. Exit Recursivitate!" << endl;


				cout << "Optiune recursivitate: "; cin >> op3;
				switch (op3)
				{
				case 1: //
				{

				}
				break;

				case 2:
					//
				{

				}
				break;

				case 3:
					//
				{

				}
				break;
				case 4:
					// Ackermann cu liste
				{
					int m, n;
					cout << "m = "; cin >> m;
					cout << "n = "; cin >> n;
					int ac = Ackermann_liste(m, n);
					cout << "ac(" << m << "," << n << ") = " << ac << endl;
				}
				break;

				case 0:
					cout << "A terminat submeniu 2" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op3 != 0);
			break;

		case 4:
			do
			{
				cout << endl << "Metoda Divide et Impera" << endl;
				cout << "4.1. Turnurile din Hanoi" << endl;
				cout << "4.2. " << endl;
				cout << "4.0. Exit Divide et Impera!" << endl;

				cout << "Optiune probleme diverse : "; cin >> op4;

				switch (op4)
				{
				case 1:
					// Turnurile_din_Hanoi();
					break;

				case 2:

					break;

				case 0:
					cout << "A terminat submeniu 4" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op4 != 0);
			break;

		case 5: //Greedy
			do
			{
				cout << endl << "Metoda Greedy" << endl;
				cout << "5.1. Parcurgere tabla de sah nxn cu saritura cal" << endl;
				cout << "5.2. Plata unei daca numarul de bancnote este nelimitat" << endl;
				cout << "5.3. Plata unei daca numarul de bancnote este limitat" << endl;
				cout << "5.4. Interclasarea a k siruir de numere ordonate crescator" << endl;
				cout << "5.5. Obtinerea codificarii Fibonacci pentru un numar n dat" << endl;
				cout << "5.0. Exit Greedy!" << endl;

				cout << "Optiune probleme diverse : "; cin >> op5;

				switch (op5)
				{
				case 1:
					// parcugere_cal();
					break;

				case 2:

					break;

				case 0:
					cout << "A terminat submeniu 5" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op5 != 0);
			break;

		case 6: //Progaamare dinamica
			do
			{
				cout << endl << "Programare dinamica" << endl;
				cout << "6.1. Parantezarea produsului de matrice cu numar minim de inmultiri" << endl;
				cout << "6.2. Determinarea sumei maxime intr-un triunghi de numere" << endl;
				cout << "6.3. Verificare cuvant in alfabet" << endl;
				cout << "6.0. Exit Divide et Impera!" << endl;

				cout << "Optiune probleme diverse : "; cin >> op6;

				switch (op6)
				{
				case 1:
					// Parantezare_produs_matrice();
					break;

				case 2:

					break;

				case 3: // verifacre cuvant in alfabet
					verificare_alfabet();

					break;

				case 0:
					cout << "A terminat submeniu 6" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op6 != 0);
			break;

		case 0: // end Meniu principal
			cout << "Bye! Bye!" << endl;
			break;

		default:
			cout << "Optiune invalida!" << endl;
			break;
		} // end switch op meniu principal
	} while (op != 0); // end meniu principal

	return 0;
}
