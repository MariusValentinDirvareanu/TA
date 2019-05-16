#include "ProblemaLabirintului.h"



ProblemaLabirintului::ProblemaLabirintului()
{
	fin.open("labirint.txt");
	Citire();
	fin.close();
	Rezolvare(poz_init_X, poz_init_Y, 2);

}

void ProblemaLabirintului::Citire()
{
	fin >> N >> M;
	fin >> poz_init_X >> poz_init_Y;
	fin >> poz_finala_X >> poz_finala_Y;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			fin >> matrice[i][j];
}

bool ProblemaLabirintului::isOK(int i, int j)
{
	if (i > N || i < 1)
		return false;
	if (j > M || j < 1)
		return false;

	if (matrice[i][j] == 1 || (i == poz_finala_X && j == poz_finala_Y))
		return true;

	if (matrice[i][j] == 0 || matrice[i][j])
		return false;

	return true;
}

void ProblemaLabirintului::afisare()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			std::cout << matrice[i][j] << " ";

		std::cout << "\n";
	}
	std::cout << "\n\n";
}

void ProblemaLabirintului::Rezolvare(int i, int j, int pas)
{
	if (i == poz_finala_X && j == poz_finala_Y)
		afisare();
	else
	{
		for (int k = 0; k < directii; k++)
		{
			int i_vecin = i + di[k];
			int j_vecin = j + dj[k];
			if (isOK(i_vecin, j_vecin))
			{
				matrice[i_vecin][j_vecin] = pas;
				Rezolvare(i_vecin, j_vecin, pas + 1);
				matrice[i_vecin][j_vecin] = 0;
			}
		}
	}
}


ProblemaLabirintului::~ProblemaLabirintului()
{
}
