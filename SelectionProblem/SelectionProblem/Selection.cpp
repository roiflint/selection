#include "Selection.h"

double Selection::Select(int left, int right, int i)
{
	int pivot; //location of pivot
	int leftPart; //size of part left ot pivot (including pivot)

	pivot = Partition(left, right);

	leftPart = pivot - left + 1;
	if (i == leftPart)
		return arr[pivot];
	if (i < leftPart)
		return Select(left, pivot - 1, i);
	else
		return Select(pivot + 1, right, i - leftPart);

}

Selection::Selection(double* ARR, int I, int N)
{
	this->arr = new double[N];
	this->n = N;
	this->i = I;

	Insertion(ARR);

}

Selection::~Selection()
{
	delete this->arr;
}

int Selection::Partition(int l, int r)
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
	/*if (left == right)	//Stop condition 
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
			Partition(left, right -1, true);
		}
	}*/

}

void Selection::Swap(int num1, int num2)
{
	double temp = this->arr[num1];
	this->arr[num1] = this->arr[num2];
	this->arr[num2] = temp;
}

void Selection::Insertion(double* ARR)
{
	for (int i = 0; i < this->n; i++)
	{
		this->arr[i] = ARR[i];
	}
}

void Selection::tellTime()
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	Selection::Select(0, (this->n - 1), this->i);// Here you put the name of the function you wish to measure)
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by function <Selection> is : " << fixed
		<< time_taken << setprecision(9);
	cout << " sec" << endl;
}

void Selection::printArr()
{
	for (int i = 0; i < this->n; i++)
		cout << this->arr[i] << " ";
	cout << endl;
}

