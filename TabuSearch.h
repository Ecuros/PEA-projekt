#pragma once
#include<vector>
using namespace std;
class TabuSearch
{
public:
	TabuSearch();
	void calculateRoad(int size, vector<vector<int>> &roadsMatrix);
	~TabuSearch();

private: 
	vector<vector<int>>exchangesMatrix;
	vector<int> createInitialSolution(int size);
	vector<int> bestSolution;
	vector<int> initialSolution;
	
	vector<vector<int>> createExchangesMatrix(int size);
	
	int find(vector<int> &vector, int number);

	void kupa(int size);

	void decrementMatrix(vector<vector<int>>& exchangesMatrix);	

};

