#include "AckermannListe.h"



AckermannListe::AckermannListe() {
}

AckermannListe::AckermannListe(int m, int n)
{
	cout << "ac(" << m << "," << n << ") = " << Ackermann_liste(m, n) << '\n';
}

// pentru functia Ackermann

void AckermannListe::parcurgere_lista(v* p, v* u)
{
	v* q;
	if (p == nullptr)
		cout << "Lista este vida!" << endl;
	else
	{
		q = p;
		while (q != nullptr)
		{
			cout << q->val << " ";
			q = q->urm;
		}
		cout << endl;
	}
}

int AckermannListe::Ackermann_liste(int m, int n)
{
	v* p, * u, * q;

	//initializare lista dublu inlantuita
	//primul element
	p = new v;
	p->val = m;
	p->prec = nullptr;
	//ultimul element
	u = new v;
	u->val = n;
	u->urm = nullptr;
	p->urm = u;
	u->prec = p;
	parcurgere_lista(p, u);

	int k = 2; // numarul de elemnte din lista
	while (k > 1)
	{
		if (u->prec->val == 0) // ac(0,n)=n+1
		{
			u->prec->val = u->val + 1;
			q = u;
			u = u->prec;
			u->urm = nullptr;
			k--;
			delete q;
		}
		else
		{
			if (u->val == 0) // ac(m,0)=ac(m-1,1)
			{
				u->val = 1;
				u->prec->val = u->prec->val - 1;
			}
			else  // ac(m,n)=ac(m-1,ac(m,n-1))
			{
				q = new v;
				q->val = u->val - 1;
				q->prec = u;
				q->urm = nullptr;
				u->val = u->prec->val;
				u->prec->val = u->prec->val - 1;
				u->urm = q;
				u = q;
				k++;
			}
		}
		parcurgere_lista(p, u);
	}
	return p->val;
}


AckermannListe::~AckermannListe()
{
}
