#include "pch.h"
#include "GeneticAlgorithm.h"
#include <vector>
#include <algorithm>  
#include <iostream>
#include <random>
#include <ctime>
#include "Creator.h"
using namespace std;
GeneticAlgorithm::GeneticAlgorithm()
{
}


GeneticAlgorithm::~GeneticAlgorithm()
{
}

vector<vector<int>> GeneticAlgorithm::generateChromosomes(int size, int quantity)
{
	srand(time(NULL));
	vector<vector<int>> chromosomesMatrix;
	for (int i = 0; i < quantity; i++)
	{
		vector <int> chromosome;
		for (int j = 0; j <= size; j++)
		{
			chromosome.push_back(j);
		}
		random_shuffle(chromosome.begin(), chromosome.end());
		/*for (int j = 0; j < size; j++)
		{
			cout << chromosome[j];
		}
		cout << endl;*/
		chromosomesMatrix.push_back(chromosome);
	}
	
	return chromosomesMatrix;

}

void  GeneticAlgorithm::orderCrossover(vector<int> parent1, vector<int>parent2,vector<vector<int>> &childrenMatrix)
{
	//srand(time(NULL));
	vector<int> child1;
	vector<int> child2;
	vector<int> parent2withoutParent1;
	vector<int> parent1withoutParent2;

	int geneStart = rand() % (parent1.size()-2);
	int geneEnd = rand() % (parent1.size() -geneStart)+geneStart;
	if (geneEnd == geneStart)
	{
		geneEnd = rand() % (parent1.size() - geneStart) + geneStart;
	}
	//cout << geneStart << " " << geneEnd << endl;
	/*for (int c = 0; c < parent1.size(); c++)
	{
		cout << parent1[c] << ",";
	}
	cout << endl;
	for (int c = 0; c < parent1.size(); c++)
	{
		cout << parent2[c] << ",";
	}
	*/
	for (int i = 0; i < parent1.size(); i++)
	{
		bool canCopy1 = true;
		bool canCopy2 = true;
		for (int j= geneStart; j<=geneEnd;j++)
		{ 
			if (parent2[i] == parent1[j])
			{
				canCopy1 = false;
			}
			if (parent1[i] == parent2[j])
			{
				canCopy2 = false;
			}
		}
		if (canCopy1)
		{
			parent2withoutParent1.push_back(parent2[i]);
		}
		if (canCopy2)
		{
			parent1withoutParent2.push_back(parent1[i]);
		}
	}
	for (int i = geneStart; i <= geneEnd; i++) //kopiowanie pierwszych genów z rodziców
	{
		child1.push_back(parent1[i]);
		child2.push_back(parent2[i]);
	}
	int u = 0;
	for (int i = geneEnd+1 ; i < parent1.size(); i++)
	{		
			child1.push_back(parent2withoutParent1[u]);
			child2.push_back(parent1withoutParent2[u]);
			u++;
	}
	u = parent1withoutParent2.size()-1;
	for (int i= 0; i< geneStart;  i++)
	{
		child1.insert(child1.begin(), parent2withoutParent1[u]);
		child2.insert(child2.begin(), parent1withoutParent2[u]);
		u--;
	}
	childrenMatrix.push_back(child1);
	childrenMatrix.push_back(child2);
}

vector<vector<int>> classChromosomes(vector<vector<int>> &chromosomes, vector<vector<int>> &roadsMatrix, vector<int> &bestRoad,int &bestRoadCost)
{
	Creator creator;
	vector<vector<int>> classedChromosomes;
	
	classedChromosomes.push_back(chromosomes[0]);
	for (int i = 1; i < chromosomes.size(); i++)
	{

		int roadI = creator.calculateRoad(chromosomes[i], roadsMatrix);
		if (roadI < bestRoadCost)
		{
			bestRoadCost = roadI;
			bestRoad = chromosomes[i];
		}
		for (int j = 0; j < classedChromosomes.size(); j++) {
			int roadJ = creator.calculateRoad(classedChromosomes[j], roadsMatrix);
			int roadJ1 = creator.calculateRoad(classedChromosomes[classedChromosomes.size() - 1], roadsMatrix);
			
			if (roadI > roadJ1 ){
				classedChromosomes.push_back(chromosomes[i]);
				break;
			}
			else
			if (roadI > roadJ)
			{
				continue;
			}
			else {
				classedChromosomes.insert(classedChromosomes.begin() + j, chromosomes[i]);
				//cout << "added" << endl;
				break;
			}
		}
	}
	/*for (int i = 0; i < classedChromosomes.size(); i++)
	{
		/*for (int f = 0; f < classedChromosomes[i].size(); f++)
		{
			cout << classedChromosomes[i][f] << " ";
		}
		cout << "Road: " <<creator.calculateRoad(classedChromosomes[i], roadsMatrix);
		cout << endl;
	}*/
	return classedChromosomes;
}

void GeneticAlgorithm::inverseMutation(vector<int> &chromosome)
{
	
	int mutationBegin = rand() % (chromosome.size()-2);
	int mutationEnd = rand()%(chromosome.size() - mutationBegin) + mutationBegin;
	if(mutationEnd == mutationBegin)
	{
		int mutationEnd = rand() % (chromosome.size() - mutationBegin) + mutationBegin;
	}
	reverse(chromosome.begin() + mutationBegin, chromosome.begin() + mutationEnd);
}
void GeneticAlgorithm::swapMutation(vector<int> &chromosome)
{

	int mutationBegin = rand() % (chromosome.size() );
	int mutationEnd = rand() % (chromosome.size() );
	if (mutationBegin == mutationEnd)
	{
		int mutationEnd = rand() % (chromosome.size());
	}
	
	swap(chromosome[mutationBegin], chromosome[mutationEnd]);
}
void GeneticAlgorithm::insertMutation(vector<int> &chromosome)
{

	int mutationBegin = rand() % (chromosome.size());
	int mutationEnd = rand() % (chromosome.size());
	if (mutationBegin == mutationEnd)
	{
		int mutationEnd = rand() % (chromosome.size());
	}
	int chromosomeToRemove = chromosome[mutationEnd];
	chromosome.erase(chromosome.begin() + mutationEnd);

	chromosome.insert(chromosome.begin() + mutationEnd,chromosomeToRemove);
}

void GeneticAlgorithm::run(int iterations, int size, vector<vector<int>> &roadsMatrix, 
	int startingQuantity, float mutationProbability, int mutationNumber)
{
	vector<int> bestRoad;
	vector<vector<int>> orderedParents;
	srand(time(NULL));
	int bestRoadCost=INT_MAX;
	vector<vector<int>> chromosomesMatrix = generateChromosomes(size, startingQuantity);
	cout << "Generated" << endl;
	//vector<vector<int>> childrenMatrix;
	
	for (int g = 0; g < iterations; g++)
	{
		vector<vector<int>> childrenMatrix;
		//cout << "beginning next gen" << endl;
		/*for (int i = 0; i < chromosomesMatrix.size(); i++)
		{
			for (int f = 0; f < chromosomesMatrix[i].size(); f++)
			{
				cout << chromosomesMatrix[i][f] << " ";
			}
			cout << endl;
		}*/
		orderedParents = classChromosomes(chromosomesMatrix, roadsMatrix, bestRoad, bestRoadCost);
		//cout << endl;
		for (int i = 0; i < orderedParents.size() /2; i += 2)
		{
			orderCrossover(orderedParents[i], orderedParents[i + 1], childrenMatrix);
		}
		for (int i = 0; i < childrenMatrix.size(); i++)
		{
			orderedParents.push_back(childrenMatrix[i]);
			float mutateOrNotMutate = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			if (mutateOrNotMutate < mutationProbability)
			{
				if(mutationNumber ==1)
				inverseMutation(orderedParents[i]);
				//cout << "mutated" << endl;
				else if (mutationNumber == 2)swapMutation(orderedParents[i]);
				else insertMutation(orderedParents[i]);
			}
		}

		childrenMatrix = classChromosomes(orderedParents, roadsMatrix,bestRoad,bestRoadCost);
		
		vector<vector<int>> nextGeneration;
		for (int i = 0; i < startingQuantity ; i++) //obcinanie ilosci
		{
			nextGeneration.push_back(childrenMatrix[i]);
		}
		//cout << "nextgen" << endl;
		/*for (int i = 0; i < startingQuantity; i++)
		{
			for (int f = 0; f < nextGeneration[i].size(); f++)
			{
				cout << nextGeneration[i][f] << " ";
			}
			cout << endl;
		}*/
		chromosomesMatrix = nextGeneration;
	}
	cout << "cost: " << bestRoadCost;
	cout << endl;
	for (int c = 0; c < bestRoad.size(); c++)
	{
		cout <<bestRoad[c] << ",";
	}

}
