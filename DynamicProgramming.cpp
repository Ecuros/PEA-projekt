#include "pch.h"
#include "DynamicProgramming.h"
#include <iostream>
#include "Creator.h"
#include <ctime>

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
	//float average = 0;
	vector <int> cities;
	for (int i = 0; i < size; i++)
	{
		cities.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		//clock_t begin = clock();

		result = solve(cities[0], cities);
		//clock_t end = clock();
		//average += end - begin / CLOCKS_PER_SEC;
	}
	
	//for (int i = 0; i < times.size(); i++)
	//{
	//	cout << times[i] << " ";
		//average += times[i];
	//}
	//average = average / 10;
	cout << result << endl;
	//cout << "time: " << average;
	
}
int DynamicProgramming::solve(int city, vector <int> remaining )
{
	vector<int> road;
	vector<int> newRemaining;
	vector<int> costs;


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
		}
	}
	return min;
}
