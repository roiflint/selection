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
	int realSize;

public:
	fives(int n, int i);
	~fives();
	int Partition(int l, int r);
	void Insertion(double* ARR);
	void Swap(int num1, int num2);
	void tellTime();	//Calculating the time of the program
	int FivesSort(int left, int right, int i, int k=-1);
	void BubbleSort(int l, int r);
};
