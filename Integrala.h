#pragma once
#include "EcuatieAlgebricaInR.h"
class Integrala :
	public EcuatieAlgebricaInR
{
private:
	double c;
	int a = 3;
	int b = 10;
	int nrmaxit = 100; // numarul maxim de iteratii
	int k = 1;
	double integrala = 0;

private:
	double Int();


public:
	Integrala();
	~Integrala();
};

