#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

class InsertionSort
{
public:
	InsertionSort(double* ARR, int I, int N);
	~InsertionSort();
	double Sort(int I);
	void Insertion(double* ARR);
	void tellTime();	//Calculating the time of the program

private:
	double* arr;
	int n;
	int i;
};



