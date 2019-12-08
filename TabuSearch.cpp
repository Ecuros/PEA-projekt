#include "pch.h"
#include "TabuSearch.h"
#include <vector>
#include <iostream>
#include <algorithm> 
#include <time.h>
#include "Creator.h"
using namespace std;
Creator creator;
TabuSearch::TabuSearch()
{
	//kupa(10);
	
}
TabuSearch::~TabuSearch()
{
}

vector<int> TabuSearch::createInitialSolution(int size)
{
	vector<int> initialSolution;
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
	
	return initialSolution;
}

vector<vector<int>> TabuSearch::createExchangesMatrix(int size)
{
	vector<vector<int>> exchangesMatrix;
	for (int i =0 ; i < size ; i++)
	{
		vector<int> newColumn;
		for (int j = 0; j < size; j++)
		{
			newColumn.push_back(0);
		}
		exchangesMatrix.push_back(newColumn);
	}
	return exchangesMatrix;
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
void TabuSearch::kupa (int size)
{
	vector<int> initialSolution;
	vector<int> temporalSolution;
	
	int k = 0;
	int i = 0;
	for (int i = 0; i < size; i++)
	{
		initialSolution.push_back(i);
	}
	temporalSolution = initialSolution;
		
		for (0; i < size; i++)
		{		
			//temporalSolution = initialSolution;
			for (k=i; k < size; k++)
			{
				temporalSolution = initialSolution;
				swap(temporalSolution[i], temporalSolution[k]);
				for (int u = 0; u < size; u++)
				{
					cout << temporalSolution[u];
				}
				cout << endl;
			}			
		}
}
void TabuSearch::decrementMatrix(vector<vector<int>> &exchangesMatrix)
{
	for (int i = 0; i < exchangesMatrix.size(); i++)
	{
		for (int j = 0; j < exchangesMatrix.size(); j++)
		{
			if (exchangesMatrix[i][j] != 0 || exchangesMatrix[j][i] != 0)
			{
				exchangesMatrix[i][j]--;
				exchangesMatrix[j][i]--;
			}
		}
	}
}

void TabuSearch::calculateRoad(int size, vector<vector<int>> &roadsMatrix)
{
	vector<vector<int>> exchangesMatrix = createExchangesMatrix(size);
	vector<int> initialSolution = createInitialSolution(size);
	vector<int> temporalPath(size);
	vector<int> bestNeighbourPath(size);

	int j;
	int i;
	int bestRoad=INT_MAX;
	int currentRoad = 0;
	int counter = 0;
	int swappedA;
	int swappedB;
	int bestNeighbourCost = INT_MAX;
	//cout << endl;
	int a, b;
	for (int k = 0; k < initialSolution.size(); k++)
	{
		cout << initialSolution[k] << " ";
	}
	cout << endl;

	for (int k = 0; k < 250; k++)
	{
			//bestNeighbourCost = INT_MAX;
			i = 0;
			decrementMatrix(exchangesMatrix);
			bestNeighbourCost = INT_MAX;
			for (i; i < size; i++) // wybieranie najlepszego sasiada
			{		
				for (j=i; j < size; j++)
				{
					temporalPath = initialSolution;
					swap(temporalPath[i], temporalPath[j]);
					for (int u = 0; u < size; u++)
					{
						cout << temporalPath[u] << " ";
					}
					cout << endl;
					currentRoad = creator.calculateRoad(temporalPath, roadsMatrix);
					if (exchangesMatrix[temporalPath[i]][temporalPath[j]] == 0  )
					{
						//cout << "dupaaaaaaaaaa" << endl;
						if (currentRoad < bestNeighbourCost)
						{
							bestNeighbourCost = currentRoad;
							bestNeighbourPath = temporalPath;
							swappedA = temporalPath[i];
							swappedB = temporalPath[j];
							cout << "new best neighbour : " << currentRoad << endl ;
							counter = 0;
						}
						else counter++;
						if (currentRoad < bestRoad)
						{	
							bestSolution = temporalPath;
							bestRoad = currentRoad;
						}
					}
					else if (currentRoad < bestRoad)
					{
						bestRoad = currentRoad;
						bestSolution = temporalPath;
						bestNeighbourPath = temporalPath;					
						swappedA = temporalPath[i];
						swappedB = temporalPath[j];
					}	
					else counter++;		
					
				}					
			}	
		
			initialSolution = bestNeighbourPath;
			exchangesMatrix[swappedA][swappedB] += 5;
			exchangesMatrix[swappedB][swappedA] += 5;
			if (counter > 20)
			{
				initialSolution = createInitialSolution(size);
				exchangesMatrix = createExchangesMatrix(size);
			}
		//	cout << "iteracja zakonczona, najlepszy somsiad:  " << endl;
			//for (int u = 0; u < size; u++)
			{
			//	cout << initialSolution[u] << " ";
			}
			//cout << endl;
			
	}
	for (int u=0;u<size;u++)
	{
		cout << bestSolution[u]<< " ";
	}
	cout << endl << "Best road found: "<< bestRoad;
}




