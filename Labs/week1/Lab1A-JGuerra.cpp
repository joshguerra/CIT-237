// Program demonstrates modifying values of multiple variable types via pointers
// Lab1A
// By JGuerra
// Created:			1.27.16
// Last Modified:	1.31.16

/*
ANALYSIS

Create a program that can print out the following:
	value of a variable
	variable’s address
	value of a pointer that points to that variable
	the value at the location that the pointer is pointing to

After you print the information change the variable by using the pointer and print it again.

Repeat the above once for each variable type:
	character
	int
	short
	long
	double
	float
*/

/*
DESIGN

Create and initialize each variable and its pointer

Print:
	"value of var: " + myVar
	"address of var: " + &myVar
	"value of pointer: " + myVarPointer
	"value at location pointer references: " + *myVarPointer

*myVarPointer = newValue

print again

Wash. Rinse. Repeat starting at print statements for each different variable and its corresponding pointer.
*/

#include <iostream>
#include <string>
using namespace std;

//  Pre Condition:  0 < n <= to the LOGICAL size of a[]    
//					os must be a valid open output stream
// Post Condition:  Prints the first n elements of a[] to os
void printStringArr(const string a[], int n, ostream &os = cout);

int main() {
	char myChar = 'j';
	char *myCharPointer = &myChar;

	int myInt = 27;
	int *myIntPointer = &myInt;

	short myShort = 42;
	short *myShortPointer = &myShort;

	long myLong = 123456789;
	long *myLongPointer = &myLong;
	
	double myDouble = 123.45;
	double *myDoublePointer = &myDouble;

	float myFloat = 1.2f;
	float *myFloatPointer = &myFloat;
	

	int const SIZE_TITLE = 3;
	string titleArr[SIZE_TITLE] = {
		"\t\t                     Lab 1A                     ",
		"\t\t                  by J. Guerra                  ",
		"\t\t        Modifying variables via pointers        "
	};

	printStringArr(titleArr, SIZE_TITLE);
	cout << "\n\n";

	cout
		<< "myChar: " << myChar << endl
		<< "address of myChar: " << int(&myChar) << endl
		<< "myCharPointer: " << int(myCharPointer) << endl
		<< "value myCharPointer is looking at: " << *myCharPointer
		<< endl << endl;

	*myCharPointer = 'g';

	cout
		<< "myChar: " << myChar << endl
		<< "address of myChar: " << int(&myChar) << endl
		<< "myCharPointer: " << int(myCharPointer) << endl
		<< "value myCharPointer is looking at: " << *myCharPointer
		<< endl << endl;

	cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	cout
		<< "myInt: " << myInt << endl
		<< "address of myInt: " << &myInt << endl
		<< "myIntPointer: " << myIntPointer << endl
		<< "value myIntPointer is looking at: " << *myIntPointer
		<< endl << endl;

	*myIntPointer = 17;

	cout
		<< "myInt: " << myInt << endl
		<< "address of myInt: " << &myInt << endl
		<< "myIntPointer: " << myIntPointer << endl
		<< "value myIntPointer is looking at: " << *myIntPointer
		<< endl << endl;

	cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	cout
		<< "myShort: " << myShort << endl
		<< "address of myShort: " << &myShort << endl
		<< "myShortPointer: " << myShortPointer << endl
		<< "value myShortPointer is looking at: " << *myShortPointer
		<< endl << endl;

	*myShortPointer = 3;

	cout
		<< "myShort: " << myShort << endl
		<< "address of myShort: " << &myShort << endl
		<< "myShortPointer: " << myShortPointer << endl
		<< "value myShortPointer is looking at: " << *myShortPointer
		<< endl << endl;

	cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	cout
		<< "myLong: " << myLong << endl
		<< "address of myLong: " << &myLong << endl
		<< "myLongPointer: " << myLongPointer << endl
		<< "value myLongPointer is looking at: " << *myLongPointer
		<< endl << endl;

	*myLongPointer = 987654321;

	cout
		<< "myLong: " << myLong << endl
		<< "address of myLong: " << &myLong << endl
		<< "myLongPointer: " << myLongPointer << endl
		<< "value myLongPointer is looking at: " << *myLongPointer
		<< endl << endl;

	cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	cout
		<< "myDouble: " << myDouble << endl
		<< "address of myDouble: " << &myDouble << endl
		<< "myDoublePointer: " << myDoublePointer << endl
		<< "value myDoublePointer is looking at: " << *myDoublePointer
		<< endl << endl;

	*myDoublePointer = 67.89;

	cout
		<< "myDouble: " << myDouble << endl
		<< "address of myDouble: " << &myDouble << endl
		<< "myDoublePointer: " << myDoublePointer << endl
		<< "value myDoublePointer is looking at: " << *myDoublePointer
		<< endl << endl;

	cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	cout
		<< "myFloat: " << myFloat << endl
		<< "address of myFloat: " << &myFloat << endl
		<< "myFloatPointer: " << myFloatPointer << endl
		<< "value myFloatPointer is looking at: " << *myFloatPointer
		<< endl << endl;

	*myFloatPointer = 3.4f;

	cout
		<< "myFloat: " << myFloat << endl
		<< "address of myFloat: " << &myFloat << endl
		<< "myFloatPointer: " << myFloatPointer << endl
		<< "value myFloatPointer is looking at: " << *myFloatPointer
		<< endl << endl;

	cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl << endl;

	system("pause");
	return 0;
}

void printStringArr(const string a[], int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << "\n" << a[i];
}