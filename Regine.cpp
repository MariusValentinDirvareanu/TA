#include "Regine.h"



Regine::Regine()
{
	rezolvare();
}

void Regine::rezolvare()
{
	if (rezolvareUtilitar(0) == false)
	{
		std::cout << "Solutia nu exista!\n";
	}
	else {
		printSolutie();
	}
}

void Regine::printSolutie()
{
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			std::cout << tabla[i][j] << "  ";
		std::cout << "\n";
	}
}

bool Regine::esteSigur(int rand, int coloana)
{
	

	for (i = 0; i < coloana; i++)
		if (tabla[rand][i])
			return false;

	for (i = rand, j = coloana; i >= 0 && j >= 0; i--, j--)
		if (tabla[i][j])
			return false;

	for (i = rand, j = coloana; j >= 0 && i < N; i++, j--)
		if (tabla[i][j])
			return false;

	return true;
}

bool Regine::rezolvareUtilitar(int col)
{
	if (col >= N)
		return true;

	for (int r = 0; r < N; r++)
	{
		if (esteSigur(r, col))
		{
			tabla[r][col] = 1;

			if (rezolvareUtilitar(col + 1))
				return true;

			tabla[r][col] = 0;
		}
	}

	return false;
}


Regine::~Regine()
{
}
