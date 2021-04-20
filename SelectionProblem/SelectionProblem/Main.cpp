#include "InsertionSort.h"
#include "Selection.h"
#include "Fives.h"

bool inputCheck(string& str);	// Function to check if the input was legal

int main()
{
	int size, i;

	cin >> size;            // Enter the size of the array
	cin >> i;               // Enter which element you want to find

	bool correct = true;	// Variables to check if the input was correct
	string checkInput;

	if (i <= size && i > 0)	// Check if i that was entered is in the right range (0 < i <= size)
	{
		double* arr = new double[size];
		for (int j = 0; j < size; j++)
		{
			cin >> checkInput;
			if (inputCheck(checkInput))	// Check if the input was legal
			{
				arr[j] = stod(checkInput);
			}
			else // Illegal input
			{
				correct = false;
				cout << "wrong input" << endl;
			}
		}
		if (correct)
		{
			InsertionSort Is(arr, i, size);	// Insertion sort algorithm
			Selection Sel(arr, i, size);	// Selection algorithm
			fives Five(arr, i, size);		// Quintuplet algorithm

			cout.precision(4);
			cout << fixed;
			cout << "Insertion sort i'th element: " << Is.Sort(i) << endl;
			cout << "Selection i'th element: " << Sel.Select(0, size - 1, i) << endl;
			cout << "Quintuplet algorithm i'th element: " << Five.FivesSort(0, (size - 1), i) << endl;


			
			
			/*For the purpose of writing to file the time of the algorithm:*/

			/*fives timeFives(arr, i, size);*/
			Is.tellTime();
			Sel.tellTime();
			Five.tellTime();

			
		}
	}

	else   // In case if i wasn't in range 0 < i < size
	{
		cout << "wrong input" << endl;
	}
}

bool inputCheck(string& str)
{
	bool rightInput = true;	// Loop works if rightInput is true
	bool point = false;		// Maximum amount of points in the string is 1
	int numberAfterPoint = 0;
	int i = 0;
	while (i != (str.size() - 1) && rightInput)
	{
		char c = str[i];
		if ((c < '0' || c > '9') && c != '.' && c != '-')	// Checks if input contains only numbers, point, or minus
		{
			rightInput = false;
		}

		if (c == '.')						// Checks if there is only one point in the input 
		{

			if (!point)
			{
				point = true;
			}

			else							// There was more than one points
			{
				rightInput = false;
			}

			if (i + 1 >= str.size() || i + 5 < str.size() || i == 0)	// Example: 8. or 8.12345 is illegal input 8.12ab
			{
				rightInput = false;
			}
		}

		if (c == '-')	// Can't have minus symble in the middle of the number!
		{
			if (i != 0)
			{
				rightInput = false;
			}
		}
		i++;
	} // while

	return rightInput;
}