#pragma once
#include <iostream>

using namespace std;



class AckermannListe
{

private:
	struct v {
		int val;
		v* prec;
		v* urm;
	};

public:
	AckermannListe();
	AckermannListe(int, int);
	~AckermannListe();
	void parcurgere_lista(v*, v*);
	int Ackermann_liste(int, int);
};

