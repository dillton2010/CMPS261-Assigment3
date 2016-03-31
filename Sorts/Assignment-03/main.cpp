/*
 * File:   main.cpp
 * Author: dillon
 *
 * Created on March 16, 2016, 12:22 PM
 */

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "allSorts.h"
using namespace std;
#define THEFILE "randomnumbers.data"

int main()
{

	AllSorts Insertion;
	AllSorts Quick;
	AllSorts Merge;
	AllSorts Heap; 
	 

	Insertion.makeRandom();

 
	//create an array, read from file

	Insertion.insertionSort();
	Insertion.inOrder();
	Quick.quickSort();
	Quick.inOrder();
	Heap.heapSort();
	Merge.merge_sort(0, Merge.Count() - 1);
	Merge.inOrder();

	printf("###### TEST RESULTS #### \n");
	cout << "Insertion: ";
	Insertion.Result();
	cout << endl;
	cout << "Quick: ";
	Quick.Result();
	cout << endl;
	cout << "Heap: ";
	Heap.Result();
	cout << endl;
	cout << "Merge: ";
	Merge.Result();
	cout << endl;

	system("pause");
	return 0;

}
