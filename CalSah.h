#pragma once
#include <iostream>

class CalSah
{
private:
	const int N = 8;
	int k, next_x, next_y;
	int sol[8][8] = { -1 };

private:
	bool isSafe(int x, int y, int sol[8][8]);
	void printSolution(int sol[8][8]);
	bool solveKT();
	int solveKTUtil(int x, int y, int movei, int sol[8][8], int xMove[8], int yMove[8]);

public:
	CalSah();
	~CalSah();
};

