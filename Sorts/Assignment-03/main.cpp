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
	ifstream infile;
	infile.open(THEFILE);
	if (!infile) 
	{
		Insertion.makeRandom();
	}
	infile.close();
	//create an array, read from file
	
	Insertion.insertionSort();
	Insertion.inOrder();
	Quick.quickSort();
	Heap.heapSort();	
	Merge.merge_sort(0, Merge.Count() - 1);
	

	
	



	printf("hello world \n");
	system("pause");
	return 0;

}