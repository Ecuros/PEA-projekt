#pragma once
#include<vector>
using namespace std;
class TabuSearch
{
public:
	TabuSearch(int size);
	void calculateRoad( vector<vector<bool>> &exchangesMatrix, vector<vector<int>> &roadsMatrix);
	~TabuSearch();

private: 
	vector<vector<bool>>exchangesMatrix;
	void createInitialSolution(int size, vector<int> &initialSolution);
	vector<int> bestSolution;
	vector<int> initialSolution;
	
	void createExchangesMatrix(int size, vector<vector<bool>> &exchangesMatrix);
	void addToRecentlyExchaged(int a, int b);
	void removeFromRecentlyExchanged(int a, int b);
	int find(vector<int> &vector, int number);
	

};

