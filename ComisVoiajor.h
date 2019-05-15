#pragma once
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>

class ComisVoiajor
{
private:

	std::ifstream fin;

	int n, m;
	std::vector<std::vector<int>> ad;

	int lgMin;
	std::vector<int> trMin;

	int lg;
	std::vector<int> tr;
	std::vector<bool> vis;
	int x, y, z;

private:
	void bkt(int);

public:
	ComisVoiajor();
	~ComisVoiajor();
};

