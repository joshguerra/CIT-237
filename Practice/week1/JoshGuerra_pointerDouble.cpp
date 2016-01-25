// Basic program demonstrating use of pointers
//	-- declare a double variable and a pointer to that variable
//	-- print the double and pointer 
// Author: J. Guerra
// Date Created: 1/25/16
// Last Modified: 1/25/16
// Think About: this program is the same as before but with different variable type

#include <iostream>
using namespace std;

int main() {
	double myDouble = 17.3;
	double *myPointer = &myDouble;		// declare and initiaze pointer

	cout
		<< "My double is: " << myDouble << endl
		<< "My pointer is: " << myPointer << endl;

	system("pause");		// hold screen
	return 0;
}