#include <iostream>
#include <cstdlib>
using namespace std;

// compartor function

int compare(const void *a, const void *b)
{
	const int *x = (int *)a;
	const int *y = (int *)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

// main

int main()
{
	int temp, elem;

	// set size
	cout << "Enter Array Size ";
	cin >> temp;
	const int size = temp;
	int numbers[size];
	// insert

	for (int i = 0; i < size; ++i)
	{

		cout << "Enter Value for Position " << i << " : ";
		cin >> numbers[i];
	}

	cout << "Before sorting" << endl;
	for (int i = 0; i < size; i++)
		cout << numbers[i] << " ";

	// use qsort

	qsort(numbers, size, sizeof(int), compare);
	cout << endl
		 << endl;
	cout << "After sorting" << endl;

	for (int i = 0; i < size; i++)
		cout << numbers[i] << " ";

	return 0;
}
