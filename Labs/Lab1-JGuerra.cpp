// Program demonstrates modifying values of variables via pointers
// Lab1
// By JGuerra
// Created:			1.27.16
// Last Modified:	1.31.16

/*	Analysis
	Create a program with 3 decalred integer variables and one integer pointer

	the program will print out the following:
	value of a variable
	variable’s address
	value of a pointer that points to that variable
	the value at the location that the pointer is pointing to

	After you print the information change the variable by using the pointer and print it again.
*/

/*	Design
	Create and initialize each integer and the pointer

	Print:
	"value of var: " + myVar
	"address of var: " + &myVar
	"value of pointer: " + myVarPointer
	"value at location pointer references: " + *myVarPointer

	*myVarPointer = newValue

	print again

	*pointer = nextInt

	Wash. Rinse. Repeat starting at print statements for each different variable.
	use the same pointer
*/

#include <iostream>
#include <string>
using namespace std;

//  Pre Condition:  0 < n <= to the LOGICAL size of a[]    
//					os must be a valid open output stream
// Post Condition:  Prints the first n elements of a[] to os
void printStringArr(const string a[], int n, ostream &os = cout);

int main() {
	int a = 3, b = 4, c = 5;
	int *p = &a;


	int const SIZE_TITLE = 3;
	string titleArr[SIZE_TITLE] = {
		"\t\t                     Lab 1                      ",
		"\t\t                  by J. Guerra                  ",
		"\t\t        Modifying variables via pointers        "
	};

	printStringArr(titleArr, SIZE_TITLE);
	cout << "\n\n";

	cout
		<< "value1: " << a << endl
		<< "address of value1: " << &a << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p 
		<< endl << endl;

	*p = 13;

	cout
		<< "value1: " << a << endl
		<< "address of value1: " << &a << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p
		<< endl << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	p = &b;

	cout
		<< "value2: " << b << endl
		<< "address of value2: " << &b << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p 
		<< endl << endl;

	*p = 14;

	cout
		<< "value1: " << b << endl
		<< "address of value1: " << &b << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p
		<< endl << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	p = &c;

	cout
		<< "value: " << c << endl
		<< "address of value: " << &c << endl 
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p
		<< endl << endl;

	*p = 15;

	cout
		<< "value1: " << c << endl
		<< "address of value1: " << &c << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p
		<< endl << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	system("pause");
	return 0;
}

void printStringArr(const string a[], int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << "\n" << a[i];
}