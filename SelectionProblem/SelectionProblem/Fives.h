#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

class fives
{
private:
	double* arr;
	int n;
	int i;

public:
	
	/*ctor & dtor*/
	fives(double* ARR, int n, int i);
	~fives();

	/*methods*/
	int Partition(int l, int r, bool isLeft = true);
	double FivesSort(int left, int right, int i, int k=-1);
	void BubbleSort(int left, int right);
	void Swap(int num1, int num2);
	void tellTime();	//Calculating the time of the program
};
