#pragma once
#include <iostream>



class Binar
{
private:
	struct nod {
		int val;
		nod* next;
	};
	struct lista {
		nod* v;
		lista* urm;
	};
	int n;
	lista* C, * U, * V, * B1, * B2;
	nod* q, * p;

public:
	Binar();
	Binar(int);
	void bin(int);
	void print(lista*);
	~Binar();
};

