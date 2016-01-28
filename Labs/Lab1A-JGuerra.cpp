// Program demonstrates modifying values of multiple variable types via pointers
// Lab1A
// By JGuerra
// Created:			1.27.16
// Last Modified:	1.27.16

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
using namespace std;

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

	float myFloat = 1.2;
	float *myFloatPointer = &myFloat;

	cout
		<< "myChar: " << myChar << endl
		<< "address of myChar: " << &myChar << endl
		<< "myCharPointer: " << myCharPointer << endl
		<< "value myCharPointer is looking at: " << *myCharPointer
		<< endl << endl;

	*myCharPointer = 'g';

	cout
		<< "myChar: " << myChar << endl
		<< "address of myChar: " << &myChar << endl
		<< "myCharPointer: " << myCharPointer << endl
		<< "value myCharPointer is looking at: " << *myCharPointer
		<< endl << endl;



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
		<< endl << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;

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
		<< endl << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;

	system("pause");
	return 0;
}