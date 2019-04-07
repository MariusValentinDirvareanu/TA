#pragma once
#include <iostream>

using namespace std;


class VerificareAlfabet
{
public:
	VerificareAlfabet();
	~VerificareAlfabet();
	void verificare_alfabet();

private:
	int m, n, M[10][10], x[30], i, j, k, a, l1, l2, y;
	int A[30][30][10] = { 0 };
};

