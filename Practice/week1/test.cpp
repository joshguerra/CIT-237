// Basic main program with single function
//	-- prompts user for an integer and prints it out in function
// Author: J. Guerra
// Date Created: 1/24/16
// Last Modified: 1/24/16
// Think About: removing the print statement in the main to avoid double printing

#include <iostream>
using namespace std;

void functionOne(int n);

int main() {
	int myVar = 0;	// initialize a variable

	cout << "Enter an integer value: ";
	cin >> myVar;

	cout << "You entered " << myVar << endl;

	functionOne(myVar);
	
	system("pause");

	return 0;
}

void functionOne(int n) {
	cout << "in function one, the variable is: " << n << endl;
}