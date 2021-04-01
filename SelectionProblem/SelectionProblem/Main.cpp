#include "InsertionSort.h"
#include "Selection.h"


int main()
{

	int size, i;
	cout << "Enter the size of the array" << endl;
	cin >> size;

	cout << "Enter i" << endl;
	cin >> i;

	double* arr = new double[size];
	cout << "Enter the numbers into the array" << endl;
	for (int j = 0; j < size; j++)
	{
		cin >> arr[j];
	}
	
	InsertionSort Is(arr, i, size);
	Selection Sel(arr, i, size);

	cout << "The magic number is(Insertion sort) : " << Is.Sort(i) << endl;
	cout << "The magic number is(Selection) : " << Sel.Select(0, size-1, i) << endl;
	
	Is.tellTime();
	Sel.tellTime();

}
