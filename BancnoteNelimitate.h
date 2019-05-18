#pragma once
#include <iostream>

class BancnoteNelimitate
{
private:
	const int n = 7;
	int i, man, inv, s, a[7] = { 1,5,10,50,100,200,500 };

public:
	BancnoteNelimitate();
	~BancnoteNelimitate();
};

