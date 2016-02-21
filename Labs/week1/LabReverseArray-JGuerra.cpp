// Copy an array in reverse order
// File:		Reverse
// By:			JGuerra
// Created:	2.01.16
// Modified:	2.01.16

/*
	Analysis

	Create a function that accepts an array and its size. This function should make a copy 
	of the array in the reverse order. The function should return a pointer to the new array. 
*/

#include <iostream>
using namespace std;

//  Pre Condition:  n <= to the LOGICAL size of a[]
//					os must be a valid open output stream
// Post Condition:  Prints the first n elements of a[] to os, epl elements per line
void printArray(const int a[], int n, int epl = 5, ostream &os = cout);

//  Pre Condition:  n = PHYSICAL size of a[]
// Post Condition:  returns a pointer to a new int array that is a copy of a[] in reverse order
int *reverseArray(int a[], int n);

void main() {
	int const SIZE = 5;
	int a[SIZE] = { 10, 20, 30, 40, 50 };
	int *p = nullptr;

	printArray(a, SIZE);
	p = reverseArray(a, SIZE);
	printArray(p, SIZE);

	system("pause");
}

void printArray(const int a[], int n, int epl, ostream &os) {
	for (int i = 0; i < n; i++)
		os << a[i] << (i % epl == epl - 1 || i == n - 1 ? "\n" : "\t");
}

int *reverseArray(int a[], int n) {
	int *newArray = nullptr;
	newArray = new int[n];

	for (int i = 0; i < n; i++)
		newArray[i] = a[n - i - 1];

	return newArray;
}