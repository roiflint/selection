#include "Fives.h"
#include "Selection.h"
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
	cout << "Time taken by function <5> is : " << fixed
		<< time_taken << setprecision(9);
	cout << " sec" << endl;
}

void fives::Swap(int num1, int num2)
{
	double temp = this->arr[num1];
	this->arr[num1] = this->arr[num2];
	this->arr[num2] = temp;
}

int fives::Partition(int left, int right)
{
	double pivot = arr[right];

	int i = (left - 1);
	for (int j = left; j <= right - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			Swap(i, j);
		}
	}
	Swap(i + 1, right);
	return i + 1;
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

double fives::FivesSort(int left, int right, int inx, int k)
{
	/*if (this->realSize%5 != 0)
	{
		int n = this->realSize;
		this->realSize = this->realSize + (5 - (this->realSize % 5));
		double* tmp = new double[this->realSize];
		for (int i = 0; i < n; i++)
		{
			tmp[i] = this->arr[i];
		}
		for (int i = n; i < this->realSize; i++)
		{
			tmp[i] = 0;
		}
		delete[] arr;
		this->arr = tmp;
	}*/
	int size;
	if (this->n%5!=0 && this->n > 5)
	{
		size = this->n / 5 + 1;
	}
	else
	{
		size = this->n / 5;
	}
	double *B = new double[size];
	int z = 0;
	for (int i = left; i <= right; i+=5)
	{
		int j,place;
		if (i+4 <= right)
		{
			j = i + 4;
		}
		else
		{
			j = right;
		}
		BubbleSort(i, j);
		place = j - i + 1;
		if(place%5==0)
		{
			B[z] = this->arr[(i+2)];
		}
		else if(place%3 == 0 || place == 4)
		{
			B[z] = this->arr[(i + 1)];
		}
		else
		{
			B[z] = this->arr[(i)];
		}
		z++;
	}
	Selection* s = new Selection(B, z / 2,z);
	double middle = s->Select(0, z-1, z / 2);
	int location = left, i=0;
	while (middle != this->arr[location])
	{
		i++;
		location++;
	}
	Swap(i, right-1);
	k = Partition(left, right-1);
	if (inx > k)
	{
		setN(n - (k+1-left));
		return FivesSort(k + 1, right, inx - k-1);
	}
	else if(inx<k)
	{
		setN(n - (right - k+1));
		return FivesSort(left, k - 1, inx);
	}
	else
	{
		return this->arr[inx-1+left];
	}


}