#include "pch.h"
#include "BF.h"
#include <iostream>
#include "Creator.h"

BF::BF()
{

}


BF::~BF()
{
}


vector<int> BF::createVector(int size)
{
	vector<int> permutation;
	for (int i = 0; i < size-1; i++)
	{
		permutation.push_back(i+1);
	}
	return permutation;
}

int BF::calculateRoad(vector<vector<int>> table, int size)
{	
	int bestRoad = 100000;
	vector <int> permutation = createVector(size);
	
	vector <int> bestPermutation;
	int currentRoad;
	
	while (!lastPermutation )
	{
		
		for (int i = 0; i < 10; i++)
		{
			clock_t begin = clock();
			permutation = nextPermutation(permutation);
			currentRoad = creator.calculateRoad(permutation, table);
			if (currentRoad < bestRoad)
			{
				bestRoad = currentRoad;
				bestPermutation = permutation;
			}
			clock_t end = clock();
			times.push_back((float)end - begin / CLOCKS_PER_SEC);
		}	
		
	}
	float average = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << times[i] << " ";
		average += times[i];
	}
	
	cout << "time: " << (float)average;
	for (int i = 0; i < permutation.size(); i++)
	{
		cout << bestPermutation[i] << " ";
	}
	return bestRoad;
}

vector<int> BF::nextPermutation(vector<int> permutation)
{
	int size = permutation.size();
	int k =-1;
	int l =0;
	int end =size-1;
				
		for (int i = 0; i < size - 1; i++)
		{
			if (permutation[i] < permutation[i + 1])
			{
				k = i;
			}
		}
		if (k == -1)
		{
			lastPermutation = true;		
		}
		else {
			for (int i = 0; i < size; i++)
			{
				if (permutation[k] < permutation[i])
				{
					l = i;
				}
			}
			swap(permutation[k], permutation[l]);
			for (k + 1; k < size - 1; k++)
			{
				int temp = permutation[k + 1];
				permutation[k + 1] = permutation[end];
				permutation[end] = temp;
				k++;
				end--;

			}
		}
		/*for (int i = 0; i < permutation.size(); i++)
		{
			cout << permutation[i] << " ";
		}
		cout << endl;
	*/
		return (permutation);
}
