#pragma once
#include <iostream>

class Regine
{
private:
	int N = 4;
	int tabla[4][4] = { 0 };
	int i = 0, j = 0;

private:
	void rezolvare();
	void printSolutie();
	bool esteSigur(int, int);
	bool rezolvareUtilitar(int);

public:
	Regine();
	~Regine();
};

