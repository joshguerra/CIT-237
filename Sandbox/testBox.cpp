#include <iostream>
#include "Box.h"
using namespace std;

int main() {
	Box test1;
	test1.setLength(0);
	test1.setWidth(7);
	test1.setHeight(-3);
	test1.printBox();

	{
	Box test2;
	test2.setLength(4);
	test2.setWidth(7);
	test2.setHeight(3);
	test2.printBox();
	}

	Box sillyBox;
	sillyBox.printBox();

	const int BOXES = 3;
	Box boxArray1[BOXES];
	cout << "[31] There are " << sillyBox.getNumBoxes() << " number of boxes" << endl;

// for (Box b : boxArray)

	system("pause");
	return 0;
}