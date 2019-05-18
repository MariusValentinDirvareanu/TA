#pragma once
#include <iostream>
#include <vector>

class Submultimi
{
private:
	int n; 
	int k;
	std::vector<int> st;

private:
	void bk(int);

public:
	Submultimi();
	~Submultimi();
};

