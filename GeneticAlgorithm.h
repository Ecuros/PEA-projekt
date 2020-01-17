#pragma once
#include <vector>

using namespace std;
class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	~GeneticAlgorithm();

 

	vector<vector<int>> generateChromosomes(int size, int quantity);
	void orderCrossover(vector<int> parent1, vector<int> parent2, vector<vector<int>> &childrenMatrix);
	void inverseMutation(vector<int> &chromosome);
	void swapMutation(vector<int> &chromosome);
	void insertMutation(vector<int>& chromosome);
	void run(int iterations, int size ,vector<vector<int>>& roadsMatrix
		, int startingQuantity, float mutationProbability, int mutationNumber);
};

