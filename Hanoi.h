#pragma once
#include <iostream>

class Hanoi
{
private:
	char a, b, c;
	int n;

private:
	void hanoiRez(int, char, char, char);

public:
	Hanoi();
	
	~Hanoi();
};

