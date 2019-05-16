#include "Perspico.h"



Perspico::Perspico()
{
	PerspicoRez();
}


int Perspico::L(int C[5][5], int i, int j)
{ // calculeaza L(C[i][j]
	int Lij = 0, r, s;
	if (j < 4)
	{
		for (s = j + 1; s <= 4; s++)
			if (C[i][s] < C[i][j])
				Lij++;
	}
	if (i < 4)
	{
		for (r = i + 1; r <= 4; r++)
			for (s = 1; s <= 4; s++)
				if (C[r][s] < C[i][j])
					Lij++;
	}
	return Lij;
}

int Perspico::S(int C[5][5])
{ // calculeaza suma S pentru o configuratie S = Suma(L(k)) pentru k de la 1 la 15 la caer se adauga
  // 1 daca linia+coloana spatiului liber este numar impar
	int i, j, suma = 0, l, c;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
		{
			suma = suma + L(C, i, j);
			std::cout << L(C, i, j) << "  ";
			if (C[i][j] == 16)
			{
				l = i; c = j;
			}
		}
	if ((l + c) % 2 == 1)
		suma = suma + 1;
	std::cout << std::endl;
	return suma;
}

int Perspico::costC(int C[5][5])
{ // calculeaaza costul configuratiei C: cate numere nu sunt la locul din configuratia finala
	int i, j, k, cost;

	k = 1;
	cost = 0;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
		{
			if (C[i][j] != k)
				cost++;
			k++;
		}
	//std::cout<<"cost="<<cost<<std::endl;
	return cost;
}

int Perspico::compara_final(int C[5][5])
{ // compara o cunfiguratie data cu configuatia finala
  // intoarce 1  daca e configuratia finala; altfel intoarce 0
	int i, j, k;

	k = 1;
	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
		{
			if (C[i][j] != k)
				return 0;
			k++;
		}
	return 1;
}

int Perspico::compara2(int C1[5][5], int C2[5][5])
{ // compara doua cunfiguratii date intre ele
  // intoarce 1  daca e configuratiile sunt diferite; altfel, daca sunt egale, intoarce 0
	int i, j;

	for (i = 1; i <= 4; i++)
		for (j = 1; j <= 4; j++)
		{
			if (C1[i][j] != C2[i][j])
				return 1;
		}
	return 0;
}

void Perspico::parcurge_lista2(config * cap)
{
	config* q;
	int i, j;
	q = cap;
	while (q)
	{
		for (i = 1; i <= 4; i++)
		{
			for (j = 1; j <= 4; j++)
				printf("%2d ", q->C[i][j]);
			std::cout << std::endl;
		}
		std::cout << std::endl;
		q = q->urm;
	}
}
void Perspico::PerspicoRez()
{
	int C0[5][5] = { 0,0,0,0,0,0,1,2,3,4,0,5,6,16,8,0,9,10,7,11,0,13,14,15,12 };
	//int C0[5][5];
	int i, j, k;
	int l, c; // (l,c) pozitia casutei libere
	int x[5] = { 0,0,-1,0,1 };
	int y[5] = { 0,-1,0,1,0 };
	config* inchisa = nullptr, * deschisa = nullptr, * ultim_i = nullptr, * ultim_d = nullptr, * q = nullptr, * a = nullptr;

	// citeste configuraia initiala
	/*int n; std::cout<<"n"; std::cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
		   std::cout<<"C0["<<i<<","<<j<<"] = ";
		   std::cin>>C0[i][j];
		}*/
		//C0[5][5]={0,1,2,3,4,0,5,6,16,8,0,9,10,7,11,0,13,14,15,12};
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
			printf("%2d ", C0[i][j]);
		std::cout << std::endl;
	}
	// Se poate verifica calculand S(C0) daca exista solutie  pentru a ajunge in configuratia finala
	// adica, daca S(C0) este numar par
	std::cout << "S(C0) = " << S(C0) << std::endl;
	if (S(C0) % 2 == 1)
	{
		std::cout << "Nu exista solutie pentru configuratia data\n";
	}
	else // exista solutie
	{
		// deschidem lista inchisa; inchisa este configuratia capatului de lista
		// lista cu capat inchisaa contine configuratiile prin care sa trecm spre configuratia finala
		inchisa = new config;
		for (i = 0; i <= 4; i++)
			for (j = 0; j <= 4; j++)
				(inchisa->C)[i][j] = C0[i][j];
		inchisa->h = 0;
		inchisa->cost = costC(C0);
		inchisa->tata = nullptr;
		inchisa->urm = nullptr;
		inchisa->prec = nullptr;
		ultim_i = inchisa; // ultimul element din lista inchisa
		std::cout << "capatul listei 'inchise' este\n";
		for (i = 1; i <= 4; i++)
		{
			for (j = 1; j <= 4; j++)
				std::cout << (inchisa->C)[i][j] << " ";
			std::cout << std::endl;
		}

		// initializam lista deschisa expandand capatul listei inchise;
		// contine posibilitatile de configuratii prin care sa treaca spre configuratia finala
		   // calculam pozitia casutei libere
		l = 1; c = 1;
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
				if (C0[i][j] == 16)
				{
					l = i; c = j;
					break;
				}

		for (k = 1; k <= 4; k++)
		{
			if ((l + x[k] <= 4) && (l + x[k] >= 1) && (c + y[k] <= 4) && (c + y[k] >= 1))
			{
				// adauga configuratie in lista deschisa
				q = new config;
				for (i = 0; i <= 4; i++)
					for (j = 0; j <= 4; j++)
						q->C[i][j] = ultim_i->C[i][j];
				// schimba pozitiile (l,c) cu (l+x[k],c+y[k])
				int aux = q->C[l][c];
				q->C[l][c] = q->C[l + x[k]][c + y[k]];
				q->C[l + x[k]][c + y[k]] = aux;
				q->h = ultim_i->h + 1;
				q->cost = costC(q->C);
				q->tata = ultim_i;
				q->fiu = nullptr;
				if (!deschisa) // deschisa nu are nici un element
				{
					q->prec = nullptr;
					q->urm = nullptr;
					deschisa = q;
					ultim_d = q;
				}
				else
				{
					q->prec = ultim_d;
					ultim_d->urm = q;
					ultim_d = q;
				}
			}
		}
		// completeaza lista inchisa cu configuratii cu costuri din ce in ce mai mici;
		std::cout << "Lista inchisa este\n";
		parcurge_lista2(inchisa);
		std::cout << std::endl;
		std::cout << "Lista deschisa este\n";
		parcurge_lista2(deschisa);
		std::cout << std::endl;
		while ((!compara_final(ultim_i->C)) && (deschisa))
		{
			// ultim_i din lista inchisa este diferit de configuratia finala si in lista deschisa mai sunt elemente
			// cauta configuratia de cost minim in lista deschisa si il aduga in lista inchisa
			std::cout << "E aici!\n";
			int cmin = 17;
			q = deschisa;
			while (q)
			{
				if (cmin >= costC(q->C))
				{
					cmin = costC(q->C);
					a = q;
				}
				q = q->urm;
			}
			std::cout << "cmin= " << cmin << std::endl;
			// adauga a in lista inchisa
			config* b = a;
			a->urm = nullptr;
			a->prec = ultim_i;
			ultim_i->urm = a;

			std::cout << "Lista inchisa este\n";
			parcurge_lista2(inchisa);
			std::cout << std::endl;
			// !!! trebuie sters b din lista deschisa si refacute legaturile ????
			if (b == deschisa)
			{
				deschisa = deschisa->urm;
				deschisa->prec = nullptr;
				delete b;
			}
			else
			{
				if (b == ultim_d)
				{
					ultim_d = ultim_d->prec;
					ultim_d->urm = nullptr;
					delete b;
				}
				else
				{
					(b->prec)->urm = b->urm;
					(b->urm)->prec = b->prec;
					delete b;
				}
			}

			std::cout << "Lista inchisa este\n";
			parcurge_lista2(inchisa);
			std::cout << std::endl;
			std::cout << "Lista deschisa este\n";
			parcurge_lista2(deschisa);
			std::cout << std::endl;

			// !!!

		   // expandeaza ultim_i in lista deschisa
		   // calculam pozitia casutei libere in ultim_i
			l = 1; c = 1;
			for (i = 1; i <= 4; i++)
				for (j = 1; j <= 4; j++)
					if (ultim_i->C[i][j] == 16)
					{
						l = i; c = j;
						break;
					}
			for (k = 1; k <= 4; k++)
			{
				if ((l + x[k] <= 4) && (l + x[k] >= 1) && (c + y[k] <= 4) && (c + y[k] >= 1))
				{
					// adauga configuratie in lista deschisa
					a = new config;
					for (i = 0; i <= 4; i++)
						for (j = 0; j <= 4; j++)
							a->C[i][j] = ultim_i->C[i][j];
					// schimba pozitiile (l,c) cu (l+x[k],c+y[k])
					int aux = a->C[l][c];
					a->C[l][c] = a->C[l + x[k]][c + y[k]];
					a->C[l + x[k]][c + y[k]] = aux;
					// verifica daca configurati din a se mai afla in lista deschisa
					q = deschisa;
					int ok = 1; // ok=1 daca configuratia din a NU se mai afla in deschisa,
							  // ok=0 daca configuratia a se mai alfa in lista deschisa
					while (q)
					{
						if (!(compara2(a->C, q->C))) // cele doua matrice sunt egale
						{
							ok = 0;
							break;
						}
						q = q->urm;
					}
					if (ok)
					{ // adauga a in lista deschisa
						a->h = ultim_i->h + 1;
						a->cost = costC(q->C);
						a->tata = ultim_i;
						a->fiu = nullptr;
						if (!deschisa) // deschisa nu are nici un element
						{
							a->prec = nullptr;
							a->urm = nullptr;
							deschisa = a;
							ultim_d = a;
						}
						else
						{
							a->prec = ultim_d;
							ultim_d->urm = a;
							ultim_d = a;
						}
					}
				}
			}

			std::cout << "Lista inchisa este\n";
			parcurge_lista2(inchisa);
			std::cout << std::endl;
			std::cout << "Lista deschisa este\n";
			parcurge_lista2(deschisa);
			std::cout << std::endl;

		}
		if (compara_final(ultim_i->C))
		{
			// a ajuns la configuratia finala
			// parcurge lista inchisa
			std::cout << "Configuratiile din lista inchisa sunt\n:";
			parcurge_lista2(inchisa);
		}
		else
		{
			std::cout << "Nu agasit solutie pentru problema data\n";
		}


		// configuratia final are cost zero
	} // if esiata solutie
}


Perspico::~Perspico()
{
}
