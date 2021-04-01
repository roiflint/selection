#include "Fives.h"
#include "Selection.h"
fives::fives(int N, int I)
{
	if (N%5!=0)
	{
		this->realSize = N + N % 5;
		this->arr = new double[this->realSize];
		this->n = N;
		this->i = I;
	}
	else
	{
		this->arr = new double[N];
		this->n = N;
		this->i = I;
		this->realSize = N;
	}
}

fives::~fives()
{
	delete this->arr;
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
	cout << "Time taken by function <Selection> is : " << fixed
		<< time_taken << setprecision(9);
	cout << " sec" << endl;
}

void fives::Swap(int num1, int num2)
{
	double temp = this->arr[num1];
	this->arr[num1] = this->arr[num2];
	this->arr[num2] = temp;
}

void fives::Insertion(double* ARR)
{
	for (int i = 0; i < this->n; i++)
	{
		this->arr[i] = ARR[i];
	}
	for (int i = this->n; i < this->realSize; i++)
	{
		this->arr[i] = 0;
	}
}

int fives::Partition(int l, int r)
{
	int x = this->arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (this->arr[j] <= x) {
			swap(i, j);
			i++;
		}
	}
	swap(i, r);
	return i;
}

void fives::BubbleSort(int l, int r)
{
	bool swapped;
	for (int i = l; i < r; i++)
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

int fives::FivesSort(int left, int right, int i, int k)
{
	double* B = new double[this->realSize];
	int z = 0;
	for (int i = 0; i < this->realSize/5; i+=5)
	{
		int j = i + 4;
		BubbleSort(i, j);
		B[z] = this->arr[i + 2];
		z++;
	}
	Selection* s = new Selection(B,i,this->realSize);
	double middle = s->Select(0, this->realSize, this->realSize / 2);
	i = 0;
	while (middle != this->arr[i])
	{
		i++;
	}
	Swap(i, 0);
	k = Partition(0, this->realSize);
	if (i > k)
	{
		return FivesSort(k + 1, right, i - k);
	}
	else if(i<k)
	{
		return FivesSort(left, k - 1, i);
	}
	else
	{
		return this->arr[i];
	}
}