#include <iostream>
#include <cmath>
#include <vector>
#include "Norme.h"
#include "PCA.h"
#include "EcuatieAlgebricaInR.h"
#include "VerificareAlfabet.h"
#include "AckermannListe.h"
#include "Binar.h"
#include "Regine.h"
#include "ComisVoiajor.h"
#include "Perspico.h"
#include "SumaTriunghi.h"
#include "ProdusMatriceParanteze.h"
#include "Hanoi.h"
#include "FactorialRecursiv.h"
#include "FibonacciRecursiv.h"
#include "FactoriPrimiRecursiv.h"


using namespace std;

int main() {
	int op, op1, op2, op3, op4, op5, op6, op7, op8;

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
		cout << "7. Metoda 'Ramifica si margineste' (Bound and Branch)" << endl;
		cout << "8. Algoritmi probabilisti" << endl;
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
				case 1: {
					Norme norma;
					vector<vector<double>> A = { {3,5},{2,1} };
					norma.normaUnuMatrici(A);
					norma.normaInfinitMatrici(A);
					norma.normaDoiMatrici(A); 
				}
					break;

				case 2:
				{
					EcuatieAlgebricaInR ecuatie;
					ecuatie.rezolvare_ecuatie();
				}
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
				{
					PCA per;
					per.permutari(5);

				}
				break;

				case 2:
					// Combinari
				{
					PCA comb;
					comb.combinari(5, 2);

				}
				break;

				case 3:
					// Combinari
				{
					PCA aran;
					aran.aranjamente(3, 2);

				}
				break;

				case 4:
					// Combinari
				{
					Regine reg;

				}
				break;

				case 6: {
					ComisVoiajor comis;
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
					FactorialRecursiv fact;
				}
				break;

				case 2:
					//
				{
					FibonacciRecursiv fibonacci;
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
					AckermannListe ac(3, 2);
					
				}
				break;

				case 8:
				{
					FactoriPrimiRecursiv factori;
				}
				break;

				case 0:
					cout << "A terminat submeniu 3" << endl << endl;
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
				cout << "4.0. Exit Divide et Impera!" << endl;

				cout << "Optiune probleme diverse : "; cin >> op4;

				switch (op4)
				{
					case 1:
					{
						Hanoi hanoi;
					}
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
				cout << "6.4. Binar" << endl;
				cout << "6.0. Exit Divide et Impera!" << endl;

				cout << "Optiune probleme diverse : "; cin >> op6;

				switch (op6)
				{
				case 1:
				{
					ProdusMatriceParanteze matrice;
				}
					break;

				case 2:
				{
					SumaTriunghi triunghi;
				}
					break;

				case 3: // verifacre cuvant in alfabet
					{
					VerificareAlfabet cuvant;
					}	
					break;

				case 4:
				{
					Binar b(5);
				}
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

		case 7:
			do
			{
				cout << endl << "Metoda Bound and Branch" << endl;
				cout << "7.1. Jocul Perspico" << endl;
				cout << "7.0. Exit Bound and Branch!" << endl;

				cout << "Bound and Branch : "; cin >> op7;

				switch (op7)
				{
				case 1:
				{
					Perspico perspico;
				}
					break;

				case 0:
					cout << "A terminat submeniu 7" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op7 != 0);
			break;

		case 8:
			do
			{
				cout << endl << "Algoritmi probabilisti" << endl;
				cout << "8.1. Maximul unei functii" << endl;
				cout << "8.2. Integrala unei functii" << endl;
				cout << "8.0. Exit Algoritmi probabilisti !" << endl;

				cout << "Optiune Algoritmi probabilisti : "; cin >> op8;

				switch (op8)
				{
				case 1:
					// Maxim();
					break;

				case 2:
					// Integrala()
					break;

				case 0:
					cout << "A terminat submeniu 8" << endl << endl;
					break;

				default:
					cout << "Optiune invalida!" << endl;
					break;

				}
			} while (op8 != 0);
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
