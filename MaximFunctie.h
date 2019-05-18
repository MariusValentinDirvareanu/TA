#pragma once
#include "EcuatieAlgebricaInR.h"
#include <iostream>

class MaximFunctie :
	public EcuatieAlgebricaInR
{
private:
	double c;
	int c1;
	double a = sqrt(3);
	double b = sqrt(9);
	int nrmaxit = 100; // numarul maxim de iteratii
	double maximf = f(a);
	int k = 1;

private:
	double Maxim();

public:
	MaximFunctie();
	~MaximFunctie();
};

