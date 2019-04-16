#include "Binar.h"



Binar::Binar(int n){
	B1 = new lista;
	p = new nod;
	p->val = 0;
	p->next = nullptr;
	B1->v = p;
	q = new nod;
	q->val = 1;
	q->next = nullptr;
	C = new lista;
	C->v = q;
	C->urm = nullptr;
	B1->urm = C;
	B2 = new lista;
	for (int i = 2; i <= n; ++i) {
		q = new nod;
		q->val = 0;
		q->next = B1->v;
		B2->urm = nullptr;
		B2->v = q;
		C = B1;
		U = B2;
		bin(0);
		}
	print(B2);
	}


void Binar::bin(int factor)
{
	while (C->urm) {
		q = new nod;
		q->val = factor;
		q->next = C->urm->v;
		V = new lista;
		V->v = q;
		V->urm = nullptr;
		U->urm = V;
		U = V;
		C = C->urm;
	}
}

void Binar::print(lista* B) {
	if (!B) {
		cout << "Lista vida\n";
	}
	else {
		C = B;
		while (C) {
			q = C->v;
			while (q) {
				cout << q->val;
				q = q->next;
			}
			cout << '\n';
			C = C->urm;
		}
	}
}


Binar::~Binar()
{
}
