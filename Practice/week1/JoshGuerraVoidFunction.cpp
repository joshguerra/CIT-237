// Basic program demonstrating variable scope when passing variable to function
//	-- declare an int variable and a void function that takes two ints
//	-- the function adds the first number to the second number
//	-- print variable value in the main (NOT IN FUNCTION)
// Author: J. Guerra
// Date Created: 1/25/16
// Last Modified: 1/25/16

#include <iostream>
using namespace std;

void adderFunction(int, int);	// pass arguements by value

int main() {
	int n = 10;		// declare and initiaze integer
	
	adderFunction(20, n);

	cout << "n: " << n << endl;

	system("pause");		// hold screen
	return 0;
}

void adderFunction(int a, int b) {
	b += a;		// b never returned
}

/*
Conclusion: the integer is passed by value and the function does not pass the result 
of the calculation back. therefor, once the function terminates the new value is lost. 
when main prints the integer, it prints the initialized value inchanged by adderFunction.
*/