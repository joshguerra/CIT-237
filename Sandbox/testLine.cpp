/*
	Copy constructors
	testLine.cpp
	by JGuerra
	Created 3.21.16
	Modified 3.21.16
*/

#include <iostream>
#include "Line.h"
using namespace std;

int main() {
	system("color 2f");		// set console color: green background, white text

	Line derp;
	Line derpCopy = derp;

	derp.printLine();
	cout << endl << endl;
	derpCopy.printLine();
	cout << endl << endl;

	derpCopy.pointArr[1] = { 5, 12 };

	derp.printLine();
	cout << endl << endl;
	derpCopy.printLine();
	cout << endl << endl;

	system("pause");
	return 0;
}