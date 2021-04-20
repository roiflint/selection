#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

class Selection
{
public:
	/*ctor & dtor*/
	Selection(double* ARR, int I, int N);
	~Selection();

	/*methods*/
	double Select(int left, int right, int i);
	int Partition(int left, int right, bool isLeft = true);
	void Insertion(double* ARR);
	void Swap(int num1, int num2);
	void tellTime();	//Calculating the time of the program

private:
	double* arr;
	int n;
	int i;
};