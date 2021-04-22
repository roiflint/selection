#include "Fives.h"
#include "Selection.h"
#include <fstream>

fives::fives(double* ARR,int I, int N)
{
		this->arr = new double[N];
		this->n = N;
		this->i = I;
		for (int i = 0; i < N; i++)
		{
			this->arr[i] = ARR[i];
		}
}

fives::~fives()
{
	delete this->arr;
}


void fives::Swap(int num1, int num2)
{
	double temp = this->arr[num1];
	this->arr[num1] = this->arr[num2];
	this->arr[num2] = temp;
}

int fives::Partition(int left, int right, bool isLeft)
{
	
	if (left == right)	//Stop condition 
		return left;

	if (isLeft)
	{
		if (arr[left] > arr[right])
		{
			Swap(left, right);
			Partition(left + 1, right, false);
		}
		else
		{
			Partition(left, right - 1, true);
		}
	}
	else
	{
		if (arr[left] < arr[right])
		{
			Partition(left + 1, right, false);
		}
		else
		{
			Swap(left, right);
			Partition(left, right - 1, true);
		}
	}
}

void fives::BubbleSort(int l, int r)
{
	bool swapped;
	for (int i = 0; i < r-l+1; i++)
	{
		swapped = false;
		for (int j = l; j < r-i; j++)
		{
			if (this->arr[j]>this->arr[j+1])
			{
				Swap(j, j + 1);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

double fives::FivesSort(int left, int right, int inx)
{
	int size;	// size of array B 
	int currentSize = (right - left + 1);	// Current size of the array A

	if (currentSize <= 5)					// Edge case - if size of an array A is <= 5
	{
		BubbleSort(left, right);
		return (arr[inx - 1 + left]);
	}

	if (currentSize % 5 != 0)
	{
		size = currentSize / 5 + 1;
	}
	else
	{
		size = currentSize / 5;
	}

	double *B = new double[size];
	int z = 0; // index in the array B

	for (int i = left; i <= right; i += 5)	// entering the numbers into array B
	{
		int j, sizeOfSubArray;
		if (i + 4 <= right) // sub-arrays of A
		{
			j = i + 4;
		}
		else
		{
			j = right;
		}

		BubbleSort(i, j);

		sizeOfSubArray = j - i + 1;
		if (sizeOfSubArray % 5 == 0) // 5 numbers in the array B
		{
			B[z] = this->arr[(i + 2)]; // place the middle number into the array B
		}
		else if (sizeOfSubArray == 3 || sizeOfSubArray == 4)	
		{
			B[z] = this->arr[(i + 1)];
		}
		else
		{
			B[z] = this->arr[(i)];
		}
		z++;
	}

	Selection* s = new Selection(B, z / 2,z); // dummy variable to find the middle of the array

	int half = z / 2;		// In case if B array has only one item
	if (half == 0)
	{
		half++;
	}

	double middle = s->Select(0, z-1, half);
	int location = left, i=0;
	while (middle != this->arr[location])
	{
		i++;
		location++;
	}

	Swap(left, i + left); // putting the middle as pivot
	int k = Partition(left, right) - left;

	delete s;
	delete[] B;

	if (inx > k + 1)
	{
		return FivesSort(k + 1 + left, right, inx - k-1);
	}
	else if(inx < k + 1)
	{
		return FivesSort(left, k + left - 1, inx);
	}
	else
	{
		return this->arr[inx-1+left];
	}

}

void fives::tellTime()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	fives::FivesSort(0, (this->n - 1), this->i);// Here you put the name of the function you wish to measure)
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	

	ofstream myfile("Measure.txt", ios::app);
	myfile << "Time taken by function <Quintuplet algorithm> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}