#pragma once
#include <iostream>
#include <fstream>

class ProblemaLabirintului
{
private:
	std::ifstream fin;

	const int N_MAX = 2005;
	const int M_MAX = 2005;

	int N, M;

	unsigned int poz_init_X, poz_init_Y;
	unsigned int poz_finala_X, poz_finala_Y;

	unsigned int matrice[2005][2005];

	const int directii = 4;
	const int di[4] = { -1, 0, 1,  0 };
	const int dj[4] = { 0,  1, 0, -1 };

private:
	void Citire();
	bool isOK(int, int);
	void afisare();
	void Rezolvare(int, int, int);


public:
	ProblemaLabirintului();
	~ProblemaLabirintului();
};

