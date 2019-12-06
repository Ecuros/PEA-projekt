#include "pch.h"
#include "TabuSearch.h"
#include <vector>
#include <iostream>
#include <algorithm> 
#include <time.h>
#include "Creator.h"
using namespace std;
Creator creator;
TabuSearch::TabuSearch(int size)
{
	
	createInitialSolution(size,initialSolution);
	createExchangesMatrix(size,exchangesMatrix);
	//addToRecentlyExchaged(3, 2);
	for (int i = 0; i < size; i++)
	{
		cout << initialSolution[i] << " ";
	}
	cout << endl;
	//calculateRoad(initialSolution, exchangesMatrix,roadsMatrix);
	for (int i=0 ; i< exchangesMatrix.size() ; i++ )
	{
		for (int j = 0; j < exchangesMatrix.size(); j++)
		{
		cout << exchangesMatrix [i][j]  << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++)
	{
		cout << initialSolution[i] << " ";
	}
	//calculateRoad(initialSolution, exchangesMatrix, roadsMatrix);
	
	
}
TabuSearch::~TabuSearch()
{
}

void TabuSearch::createInitialSolution(int size,vector<int> &initialSolution)
{
	for (int i=0 ;i <size;i++)
	{
		initialSolution.push_back(i);
	}
	srand(time(0));
	random_shuffle(initialSolution.begin(), initialSolution.end());
	/*for (int i = 0; i < size; i++)
	{
		cout << initialSolution[i] << " ";
	}*/
	
}

void TabuSearch::createExchangesMatrix(int size, vector<vector<bool>> &exchangesMatrix)
{
	for (int i =0 ; i < size ; i++)
	{
		vector<bool> newColumn;
		for (int j = 0; j < size; j++)
		{
			newColumn.push_back(false);
		}
		exchangesMatrix.push_back(newColumn);
	}
}

void TabuSearch::addToRecentlyExchaged(int a, int b)
{
	exchangesMatrix[a][b] = true;
}
void TabuSearch::removeFromRecentlyExchanged(int a, int b)
{
	exchangesMatrix[a][b] = false;
}
int TabuSearch::find(vector <int> &vector, int number)
{
	for (int i=0; i < vector.size(); i++)
	{
		if (vector[i] == number)
		{
			return i;
		}
	}
	return NULL;
}

void TabuSearch::calculateRoad( vector<vector<bool>> &exchangesMatrix, vector<vector<int>> &roadsMatrix)
{
	createInitialSolution(size, initialSolution);
	int a, b;
	
	for (int i = 0; i < 3; i++)
	{
		a = rand() % 10;
		b = rand() % 10;
		while (a == b)
		{
			b = rand() % 10;
		}	
		cout << a << "," << b << endl;
		swap(initialSolution[find(initialSolution, a)], initialSolution[find(initialSolution, b)]);
		exchangesMatrix[a][b] = true;
		
		creator.calculateRoad(initialSolution, roadsMatrix);
	}

}




