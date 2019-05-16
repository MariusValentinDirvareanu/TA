#pragma once
#include <iostream>

class ProdusMatriceParanteze
{
private:
	int i, j, k, mini, k0;
	int n, ii, p[10], M[10][10] = { 0 };

private:
	void produs_M(int n, int p[10], int M[10][10]);
	void produs_parantezare(int i, int j, int M[10][10]);
	void matrice_parantezare();

public:
	ProdusMatriceParanteze();
	~ProdusMatriceParanteze();
};

