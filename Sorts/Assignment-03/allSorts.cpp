#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "allSorts.h"
using namespace std;

AllSorts::AllSorts()
{
	swap = 0;
	compare = 0;
	items = 0;
	//must new the ptr before trying to 
	//assign values to it's [] "indices"
	list = new int[1];
	ordered = false;
	makeArray();
}

AllSorts::~AllSorts()
{
	delete[]list;
}



void AllSorts::makeRandom()
{
	//Makes the random number file {
	using namespace std;
	const int RANGE = 100; // Values in the file will range from 1 to RANGE
	const int HOWMANY = 10000; // How many values do you want to generate?
	const int valuesPerLine = 20; // How many values to a line?
	ofstream outFile;
	ifstream inFile;
	int aNum, count = 0;
	outFile.open("randomNumbers.data");
	if (outFile.fail()) cout << "Couldn't open the output file.\n";
	srand((unsigned)time(0)); // Seed the random number generator using time
	int random_integer;
	for (int index = 0; index < HOWMANY; index++)
	{
		random_integer = (rand() % RANGE) + 1; // Generate a random number in the range
		outFile << random_integer << " ";

		if ((index + 1) % valuesPerLine == 0) outFile << endl;
	}
	outFile.close();
}

int AllSorts::Count()
{
	return items;
}

void AllSorts::resize()
{
	int newsize = size * 2;
	int *temp = new int[newsize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}

	list = temp;
	delete[]temp;
	size = newsize;
}

void AllSorts::makeArray()
{
	size = 1;
	int a = 0;
	int k = 0;

	ifstream infile;
	infile.open("randomNumbers.data");
	while (infile >> a)
	{
		if (size <= items)
			resize();

		list[items++] = a;
	}
}

bool AllSorts::inOrder()
{
	for (int i = 0; i < items;)
	{
		//the first number
		int num1 = list[i];
		//the second number
		//increment it here because if we wait we will segfault
		int num2 = list[i++];

		if (num1 <= num2)
		{
			ordered = true;
		}
		else
		{
			ordered = false;
			break;
		}

	}

	return ordered;
}

void AllSorts::insertionSort()
{
	swap = 0;
	compare = 0;

	for (int i = 1; i < items; i++)
	{
		{
			int place = list[i];
			int j = i;
			while (j >= 1 && list[j - 1] > place)
			{
				list[j] = list[j - 1];
				j--;
				compare++;
				swap++;
			}
			compare++;
			list[j] = place;
		}
	}



}

void AllSorts::quickSort()
{
	swap = 0;
	compare = 0;
	quickSort(0, items - 1);
}

void AllSorts::quickSort(int first, int last)
{
	if (last > first) {
		int pivotIndex = partition(first, last);

		quickSort(first, pivotIndex - 1);
		quickSort(pivotIndex + 1, last);

	}
}

int AllSorts::partition(int first, int last)
{

	int pivot = list[first];
	int low = first + 1;
	int high = last;

	while (high > low) {
		while (low <= high && list[low] <= pivot)
		{
			compare++;
			low++;
		}
		while (low <= high && list[high] > pivot)
		{
			compare++;
			high--;
		}
		if (high > low)

		{
			int temp = list[high];
			list[high] = list[low];
			list[low] = temp;
			swap++;
		}
	}
	while (high > first && list[high] >= pivot)
	{
		compare++;
		high--;
	}

	if (pivot > list[high])
	{
		list[first] = list[high];
		list[high] = pivot;
		compare++;
		swap++;
		return high;
	}
	else
		return first;
}

void AllSorts::heapSort()
{
	return;
}

void AllSorts::merge(int p, int r)
{
	int mid = floor((p + r) / 2);
	int i1 = 0;
	int i2 = p;
	int i3 = mid + 1;
	const int num = (r - p) + 1;
	// Temp array
   // int temp[num];
	int *temp;
	temp = new int[num];

	// Merge in sorted form the 2 arrays
	while ( i2 <= mid && i3 <= r )
	    if ( list[i2] < list[i3] )
	        temp[i1++] = list[i2++];
	    else
	        temp[i1++] = list[i3++];

	// Merge the remaining elements in left array
	while ( i2 <= mid )
	    temp[i1++] = list[i2++];

	// Merge the remaining elements in right array
	while ( i3 <= r )
	    temp[i1++] = list[i3++];

	// Move from temp array to master array
	for ( int i = p; i <= r; i++ )
	    list[i] = temp[i-p];

	delete temp;
}

void AllSorts::merge_sort(int p, int r)
{
	if (p < r)
	{
		int mid = floor((p + r) / 2);
		merge_sort(p, mid);
		merge_sort(mid + 1, r);
		merge(p, r);
	}
}

void AllSorts::printArray()
{
	for (int i = 0; i < items; ++i)
	{
		if (i % 10 == 0)
			cout << list[i] << " " << endl;
		else
			cout << list[i] << " ";

	}
	cout << endl;
}

void AllSorts::Result()
{

	int numSwaps = swap;
	int numComparisons = compare;
	cout << endl;
	if (ordered)
		cout << "Ordered: True";
	else
		cout << "Ordered: False";
	cout << endl;
	cout << "Swaps: " << numSwaps << endl;
	cout << "Comparisons: " << numComparisons << endl;

}

class heap
{
public:
private:
};