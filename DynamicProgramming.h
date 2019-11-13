#pragma once
#include <vector>
using namespace std;
class DynamicProgramming
{
public:
	DynamicProgramming(vector<vector<int>> table);
	~DynamicProgramming();


	int solve(int city, vector <int> remaining);
	vector<vector<int>> setTable(vector<vector<int>>oldTable);
	vector<vector<int>> table;
	void countBestPath(int size);
	int result;
	vector<int> path;
	
};

