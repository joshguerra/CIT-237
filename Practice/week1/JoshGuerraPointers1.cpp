// Basic program demonstrating use of pointers
//	-- declare an integer variable and a pointer to that variable
//	-- print the integer and pointer 
// Author: J. Guerra
// Date Created: 1/24/16
// Last Modified: 1/24/16
// Think About: ......

#include <iostream>
using namespace std;

int main() {
	int myInt = 17;				// my favorite arbitrary number
	int *myPointer = &myInt;	// declare and initiaze pointer
	
	cout
		<< "My integer is: " << myInt << endl
		<< "My pointer is: " << myPointer << endl;

	system("pause");			// hold screen
	return 0;
}