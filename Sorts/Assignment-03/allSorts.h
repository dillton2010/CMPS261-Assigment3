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
 

class allSorts
{
public:
    allSorts();
    ~allSorts();
    void makeArray();
    void insertionSort();
    bool inOrder();
    void resize();
    int partition(int first, int last);
    void quickSort();
    void quickSort(int first, int last);
    void merge(int p, int r);
    void merge_sort(int p, int r);
    void printarray();
    void makeRandom();
private:
    int *list;
    int items;
    int compare;
    int swap;
    int size;  
};

