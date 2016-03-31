#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "allSorts.h"
using namespace std;

allSorts::allSorts()
{
    swap = 0;
    compare = 0;
    items = 0;
}
 
allSorts::~allSorts()
{
    delete []list;
}

void allSorts::makeRandom()
{
    //Makes the random number file {
    using namespace std;
    const int RANGE = 100; // Values in the file will range from 1 to RANGE
    const int HOWMANY = 100; // How many values do you want to generate?
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

void allSorts::resize()
{
    int newsize = size*2;
    int *temp  = new int[newsize];
    for(int i = 0; i < size; i++)
    {
        temp[i] = list[i];
    }
  
   list = temp;
   delete []temp;
   size = newsize;
}
void allSorts::makeArray()
{
    size = 100000;
    int a = 0;
    int k = 0;
 
    ifstream infile;
    infile.open("randomNumbers.data");
    while (infile)
    {
        
        if(size<items )
        {
            resize();
        }
        infile >> a;
        list[items] = a;
        items++;
        
    
    }
}
 
bool allSorts::inOrder()
{
    for (int i = 0; i < items; i++) 
    {
        if (list[i] <= list[i + 1])
            continue;
        else {
            return false;
        }
    }
    return true;
}
 
void allSorts::insertionSort() 
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

void allSorts::quickSort()
{
    swap = 0;
    compare = 0;
    quickSort(0, items - 1);
}
 
void allSorts::quickSort(int first, int last) 
{
    if (last > first) {
        int pivotIndex = partition(first, last);
        
        quickSort(first, pivotIndex - 1);
        quickSort(pivotIndex + 1, last);
        
    }
}

int allSorts::partition(int first, int last) 
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
    } else
        return first;
}

void allSorts:: merge(int p, int r)
{
    int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;
	const int num = (r - p) + 1;
    // Temp array
   // int temp[num];
	int temp[5];

    //// Merge in sorted form the 2 arrays
    //while ( i2 <= mid && i3 <= r )
    //    if ( list[i2] < list[i3] )
    //        temp[i1++] = list[i2++];
    //    else
    //        temp[i1++] = list[i3++];

    //// Merge the remaining elements in left array
    //while ( i2 <= mid )
    //    temp[i1++] = list[i2++];

    //// Merge the remaining elements in right array
    //while ( i3 <= r )
    //    temp[i1++] = list[i3++];

    //// Move from temp array to master array
    //for ( int i = p; i <= r; i++ )
    //    list[i] = temp[i-p];
}

void allSorts:: merge_sort(int p, int r)
{
    if ( p < r )
    {
        int mid = floor((p + r) / 2);
        merge_sort(p, mid);
        merge_sort(mid + 1, r);
        merge(p, r);
    }
}

void allSorts::printarray()
{

    for ( int i = 0; i < items; i++ )
        cout << list[i] << " ";
    cout << endl;
}


class heap
{
public:

private:    
};