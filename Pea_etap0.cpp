#include "pch.h"
#include "Creator.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "BF.h"
#include "DynamicProgramming.h"
#include "TabuSearch.h"

using namespace std;
int main()
{
	
	vector<vector<int>> table;
	vector<int>inOrder;
	vector<int>permutation;
	vector<int> cities;
	DynamicProgramming * dp;
	Creator creator;
	BF bf;
	TabuSearch tabu;
	int choice;
	string name;
	table = creator.readFile("data11.txt");
	
	bool exit = false;

	while (!exit)
	{
		
		cout << endl <<" 1: Read values from file" << endl;
		cout << " 2: Display array" << endl; 
		cout << " 3: Input permutation" << endl;
		cout << " 4: Calculate road in order" << endl;
		cout << " 5: Calculate road with choosen permutation" << endl;
		cout << " 6: Calculate with Brute Force" << endl;
		cout << " 7: Dynamic Programming" << endl;
		cout << " 8: Tabu Search" << endl;
		cout << " 0: Exit" << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
			cout << "Input file name: " << endl;
			cin >> name;
			table = creator.readFile(name);
			break;
		case 2:
			creator.displayArray(table);
			break;
		case 3: 
			permutation = creator.inputPermutation(table.size());
			break;
		case 4: 
			for (int i = 0; i < table.size(); i++)
			{
				inOrder.push_back(i);
			}
			creator.calculateRoad(inOrder, table);
			break;
		case 5:
			creator.calculateRoad(permutation, table);
			break;
		case 6:
			cout << bf.calculateRoad(table, table.size());
			break;
		case 7: 
			dp = new DynamicProgramming(table);
			dp ->countBestPath(table.size());
			break;
		case 8:
			tabu.calculateRoad(table.size(), table);
			
			break;
		case 0: exit = true;
		}
	}

}




