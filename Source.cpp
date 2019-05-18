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
#include "AckermannRecursiv.h"
#include "ProblemaLabirintului.h"
#include "CalSah.h"
#include "MaximFunctie.h"
#include "Submultimi.h"
#include "BancnoteNelimitate.h"


int main() {
	//int op1, op2, op3, op4, op5, op6, op7, op8;
	int* op = new int;
	int* op1 = new int;
	int* op2 = new int;
	int* op3 = new int;
	int* op4 = new int;
	int* op5 = new int;
	int* op6 = new int;
	int* op7 = new int;
	int* op8 = new int;

	do  // reia meniu principal pana la exit
	{
		// meniu principal
		std::cout << "PROGRAME TA " << '\n';
		std::cout << "1. Probleme diverse" << '\n';
		std::cout << "2. Backtracking" << '\n';
		std::cout << "3. Metoda recursiva" << '\n';
		std::cout << "4. Metoda Divide et Impera" << '\n';
		std::cout << "5. Metoda Greedy" << '\n';
		std::cout << "6. Programare dinamica" << '\n';
		std::cout << "7. Metoda 'Ramifica si margineste' (Bound and Branch)" << '\n';
		std::cout << "8. Algoritmi probabilisti" << '\n';
		std::cout << "0. Exit program." << '\n';

		std::cout << "Optiune : "; std::cin >> *op;

		switch (*op) // switch pentru optiune meniu principal
		{

		case 1: //Probleme diverse (laborator 1)
			do
			{
				std::cout << '\n' << "Probleme diverse" << '\n';
				std::cout << "1.1. Calculul unor norme matriciale" << '\n';
				std::cout << "1.2. Rezolvarea aproximativa pentru o ecuatie algebrica in R" << '\n';
				std::cout << "1.0. Exit probleme diverse!" << '\n';

				std::cout << "Optiune probleme diverse : "; std::cin >> *op1;

				switch (*op1)
				{
				case 1: {
					Norme* norma = new Norme;
					std::vector<std::vector<double>> A = { {3,5},{2,1} };
					norma->normaUnuMatrici(A);
					norma->normaInfinitMatrici(A);
					norma->normaDoiMatrici(A); 
				}
					break;

				case 2:
				{
					EcuatieAlgebricaInR* ecuatie = new EcuatieAlgebricaInR;
					ecuatie->rezolvare_ecuatie();
				}
					break;

				case 0:
					std::cout << "A terminat submeniu 1" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op1 != 0);
			break;

		case 2: //Backtracking
		{


			do
			{
				std::cout << '\n' << "Backtracking" << '\n';
				std::cout << "2.1. Generarea permutarilor " << '\n';
				std::cout << "2.2. Generarea combinarilor " << '\n';
				std::cout << "2.3. Generarea aranjamentelor " << '\n';
				std::cout << "2.4. Problema reginelor" << '\n';
				std::cout << "2.5. Problema parantezelor" << '\n';
				std::cout << "2.6. Problema comisului voiajor" << '\n';
				std::cout << "2.0. Exit Backtracking." << '\n';
				std::cout << "Optiune Backtracking: "; std::cin >> *op2;
				switch (*op2)
				{
				case 1: //permutari
				{
					PCA* per = new PCA;
					per->permutari(5);

				}
				break;

				case 2:
					// Combinari
				{
					PCA* comb = new PCA;
					comb->combinari(5, 2);

				}
				break;

				case 3:
					// Combinari
				{
					PCA *aran = new PCA;
					aran->aranjamente(3, 2);

				}
				break;

				case 4:
				{
					Regine* reg = new Regine;
					//Regine reg;

				}
				break;

				case 6: {
					ComisVoiajor* comis = new ComisVoiajor;
				}
				break;

				case 0:
					std::cout << "A terminat submeniu Backtracking" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op2 != 0);
		}
		break;

		case 3: //Recursivitate
			do
			{
				std::cout << '\n' << "Recursivitate" << '\n';
				std::cout << " 3.1. Calculul factorialului" << '\n';
				std::cout << " 3.2. Calculul sirului Fibonacci" << '\n';
				std::cout << " 3.3. Functia Ackermann - recursiv " << '\n';
				std::cout << " 3.4. Functia Ackermann - iterativ cu vector sau lista" << '\n';
				std::cout << " 3.5. Calculul numarului de partitii cu k submultimi " << '\n';
				std::cout << "        ale unei multimi cu n elemente " << '\n';
				std::cout << " 3.6. Determinare permutari de n - recursiv" << '\n';
				std::cout << " 3.7. Problema reginelor - recursiv" << '\n';
				std::cout << " 3.8. Descompunere in factori -  recursiv" << '\n';
				std::cout << " 3.9. Recursivitate indirecta: miscare pe ecran" << '\n';
				std::cout << "3.10. Problema labirintului" << '\n';
				std::cout << " 3.0. Exit Recursivitate!" << '\n';


				std::cout << "Optiune recursivitate: "; std::cin >> *op3;
				switch (*op3)
				{
				case 1: //
				{
					FactorialRecursiv* fact = new FactorialRecursiv;
				}
				break;

				case 2:
					//
				{
					FibonacciRecursiv* fibonacci = new FibonacciRecursiv;
				}
				break;

				case 3:
					//
				{
					AckermannRecursiv* ack = new AckermannRecursiv;
				}
				break;
				case 4:
					// Ackermann cu liste
				{
					AckermannListe ac(3, 2);
					
				}
				break;

				case 5:
				{
					Submultimi* sub = new Submultimi;
				}
				break;

				case 8:
				{
					FactoriPrimiRecursiv* factori = new FactoriPrimiRecursiv;
				}
				break;

				case 10:
				{
					ProblemaLabirintului* labirint = new ProblemaLabirintului;
				}
				break;

				case 0:
					std::cout << "A terminat submeniu 3" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op3 != 0);
			break;

		case 4:
			do
			{
				std::cout << '\n' << "Metoda Divide et Impera" << '\n';
				std::cout << "4.1. Turnurile din Hanoi" << '\n';
				std::cout << "4.0. Exit Divide et Impera!" << '\n';

				std::cout << "Optiune probleme diverse : "; std::cin >> *op4;

				switch (*op4)
				{
					case 1:
					{
						Hanoi* hanoi = new Hanoi;
					}
						break;

					case 0:
						std::cout << "A terminat submeniu 4" << '\n' << '\n';
						break;

					default:
						std::cout << "Optiune invalida!" << '\n';
						break;

				}
			} while (*op4 != 0);
			break;

		case 5: //Greedy
			do
			{
				std::cout << '\n' << "Metoda Greedy" << '\n';
				std::cout << "5.1. Parcurgere tabla de sah nxn cu saritura cal" << '\n';
				std::cout << "5.2. Plata unei daca numarul de bancnote este nelimitat" << '\n';
				std::cout << "5.3. Plata unei daca numarul de bancnote este limitat" << '\n';
				std::cout << "5.4. Interclasarea a k siruri de numere ordonate crescator" << '\n';
				std::cout << "5.5. Obtinerea codificarii Fibonacci pentru un numar n dat" << '\n';
				std::cout << "5.0. Exit Greedy!" << '\n';

				std::cout << "Optiune probleme diverse : "; std::cin >> *op5;

				switch (*op5)
				{
				case 1:
				{
					CalSah* cal = new CalSah;
				}
					break;

				case 2: {
					BancnoteNelimitate* bancnote = new BancnoteNelimitate;
				}

					break;

				case 0:
					std::cout << "A terminat submeniu 5" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op5 != 0);
			break;

		case 6: //Progaamare dinamica
			do
			{
				std::cout << '\n' << "Programare dinamica" << '\n';
				std::cout << "6.1. Parantezarea produsului de matrice cu numar minim de inmultiri" << '\n';
				std::cout << "6.2. Determinarea sumei maxime intr-un triunghi de numere" << '\n';
				std::cout << "6.3. Verificare cuvant in alfabet" << '\n';
				std::cout << "6.4. Binar" << '\n';
				std::cout << "6.0. Exit Divide et Impera!" << '\n';

				std::cout << "Optiune probleme diverse : "; std::cin >> *op6;

				switch (*op6)
				{
				case 1:
				{
					ProdusMatriceParanteze* matrice = new ProdusMatriceParanteze;
				}
					break;

				case 2:
				{
					SumaTriunghi* triunghi = new SumaTriunghi;
				}
					break;

				case 3: // verifacre cuvant in alfabet
					{
					VerificareAlfabet* cuvant = new VerificareAlfabet;
					}	
					break;

				case 4:
				{
					Binar b(5);
				}
				break;

				case 0:
					std::cout << "A terminat submeniu 6" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op6 != 0);
			break;

		case 7:
			do
			{
				std::cout << '\n' << "Metoda Bound and Branch" << '\n';
				std::cout << "7.1. Jocul Perspico" << '\n';
				std::cout << "7.0. Exit Bound and Branch!" << '\n';

				std::cout << "Bound and Branch : "; std::cin >> *op7;

				switch (*op7)
				{
				case 1:
				{
					Perspico* perspico = new Perspico;
				}
					break;

				case 0:
					std::cout << "A terminat submeniu 7" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op7 != 0);
			break;

		case 8:
			do
			{
				std::cout << '\n' << "Algoritmi probabilisti" << '\n';
				std::cout << "8.1. Maximul unei functii" << '\n';
				std::cout << "8.2. Integrala unei functii" << '\n';
				std::cout << "8.0. Exit Algoritmi probabilisti !" << '\n';

				std::cout << "Optiune Algoritmi probabilisti : "; std::cin >> *op8;

				switch (*op8)
				{
				case 1:
				{
					MaximFunctie* maxim = new MaximFunctie;
				}
					break;

				case 2:
					// Integrala()
					break;

				case 0:
					std::cout << "A terminat submeniu 8" << '\n' << '\n';
					break;

				default:
					std::cout << "Optiune invalida!" << '\n';
					break;

				}
			} while (*op8 != 0);
			break;

		case 0: // end Meniu principal
			std::cout << "Bye! Bye!" << '\n';
			break;

		default:
			std::cout << "Optiune invalida!" << '\n';
			break;
		} // end switch op meniu principal
	} while (*op != 0); // end meniu principal

	return 0;
}
