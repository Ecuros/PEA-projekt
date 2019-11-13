#pragma once
#include <iostream>
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Creator
{
public:
	Creator();
	~Creator();

	vector<vector<int>> readFile(std::string name);
	void displayArray(vector<vector<int>> wektor);
	vector<int> inputPermutation(int size);
	int calculateRoad(vector<int> permutation, vector<vector<int>>);
	vector<vector<int>> table;
	

private:
	int problemSize;

};



