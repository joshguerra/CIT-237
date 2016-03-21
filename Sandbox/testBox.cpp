#include "Box.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Box myBox;
	myBox.setWidth(0);
	myBox.setHeight(-5);
	myBox.setLength(1);
	myBox.printBox();
	cout << "There are " << myBox.getNumBoxes() << " boxes now\n";
	{
		Box theBigBox;
		theBigBox.setWidth(10);
		theBigBox.setLength(20);
		theBigBox.setHeight(30);
		theBigBox.printBox();
		cout << "There are " << myBox.getNumBoxes() << " boxes now\n";

	}
	cout << "There are " << myBox.getNumBoxes() << " boxes now\n";


	Box sillyBox;
	sillyBox.printBox();
	cout << "There are " << myBox.getNumBoxes() << " boxes now\n";


	Box newBox(1, 1, 1);
	newBox.printBox();
	cout << "There are " << myBox.getNumBoxes() << " boxes now\n";

	// cannot access private member function newBox.checkValue(3); 
	string line(20,'~');
	cout << line << endl;
	const int BOXES = 3;
	Box boxArray1[BOXES];
	cout << "[39] There are " << myBox.getNumBoxes() << " boxes now\n";

//	for (Box b : boxArray1) { // range for-loop messes up counting
	for (int i = 0; i < BOXES; i++) {
		//b.printBox();
		boxArray1[i].printBox();
		cout << line << endl;
	}
	
	cout << "[48] There are " << myBox.getNumBoxes() << " boxes now\n";
	cout << line << endl;

	Box boxArray2[] = { 5, 10, 15 }; // constructor may require one arg
	for (int i = 0; i < 3; i++) {
		boxArray2[i].printBox();
		cout << line << endl;
	}
	Box boxArray3[] = { { Box(2, 3, 4) },
		Box(4, 5, 6),
		Box(7, 8, 9) };

	for (int i = 0; i < 3; i++) {
		boxArray3[i].printBox();
		cout << line << endl;
	}

	Box *boxPtr = new Box[3];
	boxPtr[0].printBox();
	boxPtr->printBox();
	boxPtr++;




	system("pause");
	return 0;
}