#pragma once
#include <iostream>


class Perspico
{
private:
	struct config
	{
		int C[5][5]; // matricea care descrie configuratia
		int h; // inaltimea la care se afla C in arborele de configuratii;
		int cost; // costul unei configuratii =  cate numere nu sunt la locul lor din configuratia finala
		config* tata; // parintele configuratiei
		config* urm; // legatura catre urmatorul element din lista
		config* prec; //catre precedentul element din lista
		config* fiu; // legatura catre fiu in drumul de la conf initiala la conf finala
	};

private:
	int L(int C[5][5], int, int);
	int S(int C[5][5]);
	int costC(int C[5][5]);
	int compara_final(int C[5][5]);
	int compara2(int C1[5][5], int C2[5][5]);
	void parcurge_lista2(config*);
	void PerspicoRez();


public:
	Perspico();
	
	~Perspico();
};

