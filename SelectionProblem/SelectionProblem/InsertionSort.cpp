#include "InsertionSort.h";
#include <fstream>

InsertionSort::InsertionSort(double* ARR, int I, int N) // ctor
{
	this->n = N;
	this->i = I;
	this->arr = new double[N];

	Insertion(ARR);	// insert the original array
}

InsertionSort::~InsertionSort()							// dtor
{
	delete arr;
}


double InsertionSort::Sort(int I)
{
	int j;
	double val;
	for (int i = 1; i < this->n; i++)
	{
		val = this->arr[i];
		j = i - 1;
		while (j>=0 && this->arr[j] > val)
		{
			this->arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = val;
	}
	return this->arr[I-1];
}

void InsertionSort::Insertion(double* ARR)	
{
	for (int i = 0; i < this->n; i++)
	{
		this->arr[i] = ARR[i];
	}
}

void InsertionSort::tellTime()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	InsertionSort::Sort(this->i);// Here you put the name of the function you wish to measure)
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	

	ofstream myfile("Measure.txt");
	myfile << "Time taken by function <Insertion Sort> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}
