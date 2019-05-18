#pragma once
#include <iostream>
#include <vector>




class VerificareAlfabet
{
public:
	VerificareAlfabet();
	~VerificareAlfabet();
	void verificare_alfabet();

	void VerificareCompunere();

	void CitireDate();

	void CompletareStraturi();

	void StraturiMatrice();

private:
	int m, n, i, j, k, a, l1, l2, y;
	std::vector<int> x;
	std::vector<std::vector<int>> M;
	int A[30][30][10] = { 0 };
};

