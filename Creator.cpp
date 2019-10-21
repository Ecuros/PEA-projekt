
#include "pch.h"
#include "Creator.h"
#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;
Creator::Creator()
{
}


Creator::~Creator()
{
}

vector<vector<int>> Creator::readFile(std::string name)
{
	fstream file;
	string line;
	string temp;
	stringstream ss;
	int problemSize;
	int found;
	char delim = ' ';
	file.open(name);
	getline(file, line); // Get first line.
	getline(file, line); // Get second line.
	problemSize = stoi(line);

	vector<vector<int>> table(problemSize, vector<int>(problemSize, 0));

	if (file.is_open())
	{
		for (int i = 0; i < problemSize; i++)
		{
			getline(file, line);
			ss << line;

			for (int j = 0; j < problemSize; j++)
			{
				ss >> temp;
				stringstream(temp) >> found;
				temp = "";
				table[i][j] = found;
			}
		}
	}
	return table;

}
void Creator::displayArray(vector<vector<int>> wektor)
{
	for (int i = 0; i < wektor.size() - 1; i++)
	{
		for (int j = 0; j < wektor.size() - 1; j++)
		{
			cout << setw(3) << wektor[i][j] << "  ";
		}
		cout << endl;
	}
}

vector<int> Creator::inputPermutation(int size)
{
	int value;
	bool check = false;
	vector<int>permutation(size, 0);
	cout << "Input values between 1 and " << size - 1 << " without repeating values" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> value;
		if (value < 1 || value > size - 1)
		{
			cout << "Please input a valid number" << endl;
		}
		else {
			for (int j = 0; j < permutation.size(); j++)
			{
				if (value == permutation[j])
				{
					cout << "You have arleady inputed that value, please input another one" << endl;
					check = true;
					break;
				}
			}
		}
		if (check == false) {
			permutation.push_back(value);
		}
		check = false;
	}
	return permutation;
}

void Creator::calculateRoad(vector<int> permutation, vector<vector<int>> table)
{
	int nextCity = 0;
	int road = 0;
	for (int i = 0; i < permutation.size(); i++)
	{
		if (nextCity >= permutation.size() - 1)
		{
			nextCity = 0;
		}
		else nextCity = permutation[i + 1];
		road += table[permutation[i]][nextCity];

	}
	cout << "Total road: " << road << endl;
}

