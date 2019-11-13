#include "pch.h"
#include "DynamicProgramming.h"
#include <iostream>
#include "Creator.h"

using namespace std;
DynamicProgramming::DynamicProgramming( vector<vector<int>> table )
{
	this ->table = table;
}


DynamicProgramming::~DynamicProgramming()
{
}


void DynamicProgramming::countBestPath(int size)
{
	//cout << path;
	vector <int> cities;
	for (int i = 0; i < size; i++)
	{
		cities.push_back(i);
	}
	result = solve(cities[0], cities);
	cout << result << endl;
	//cout << path;
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i];
	}
}
int DynamicProgramming::solve(int city, vector <int> remaining )
{
	vector<int> road;
	vector<int> newRemaining;
	vector<int> costs;
	//vector <int> path;
	int which_road =0;

	for (int j = 0; j < remaining.size(); j++)
		if (remaining[j] != city)
			newRemaining.push_back(remaining[j]);

	if (newRemaining.size() == 1)
	{
		int last = (table[newRemaining[0]][0] + table[city][newRemaining[0]]);
		return last;
	}

	for (int i = 0; i < newRemaining.size(); i++)
	{
		int child = solve(newRemaining[i], newRemaining);
		costs.push_back(child + table[city][newRemaining[i]]);
	}

	int min = 1000000;
	for (int i = 0; i < costs.size(); i++)
	{
		if (min > costs[i])
		{
			min = costs[i];
			cout << i;
		}
	}
	return min;
}
