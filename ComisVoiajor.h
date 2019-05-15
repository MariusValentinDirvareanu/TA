#pragma once
#include <iostream>
#include <fstream>
#include <climits>

class ComisVoiajor
{
private:

	std::ifstream fin;

	int n, m;
	int ad[100][100];

	int lgMin;

	int lg;
	int trMin[100];
	int tr[100];
	bool vis[100];
	int x, y, z;

private:
	void bkt(int);

public:
	ComisVoiajor();
	~ComisVoiajor();
};

