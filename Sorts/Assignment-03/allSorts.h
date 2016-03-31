/* 
 * File:   allSorts.h
 * Author: dillon
 *
 * Created on March 16, 2016, 12:23 PM
 */


#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
 
class AllSorts
{
public:
	
    AllSorts();
    ~AllSorts(); 
    void makeArray();
    void insertionSort();
    bool inOrder();
    void resize();
    int partition(int first, int last);
	void heapSort();
    void quickSort();
    void quickSort(int first, int last);
    void merge(int p, int r);
    void merge_sort(int p, int r);
    void printArray();
	void Result();
    void makeRandom();
	bool ordered;
	int Count();
private:
    int *list;
    int items;
    int compare;
    int swap;
    int size;  
	
};

