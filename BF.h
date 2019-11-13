#pragma once
#include <vector>
#include "Creator.h"

using namespace std;
class BF
{
public:
	BF();
	~BF();

	bool lastPermutation = false;

	Creator creator;

	vector<int> createVector(int size);

	int calculateRoad(vector<vector<int>> table, int size);
	vector <int> nextPermutation(vector<int>permutation);
};

