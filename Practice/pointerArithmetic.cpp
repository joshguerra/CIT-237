#include <iostream>
using namespace std;

int main() {
	int x = 25, y = 50, z = 75;
	int *ptr = nullptr;		// init pointer to null

	cout
		<< "Here are the variables: " << endl
		<< "x: " << x << "\ty: " << y << "\tz: " << z << endl
		<< "Here is the value of ptr: " << ptr << endl << endl;

	// modify x via pointer
	ptr = &x;
	*ptr += 100;

	// modify y via pointer
	ptr = &y;
	*ptr *= 10;

	// modify z via pointer
	ptr = &z;
	*ptr /= 25;

	// reprint
	cout
		<< "Here are the variables  now: " << endl
		<< "x: " << x << "\ty: " << y << "\tz: " << z << endl
		<< "Here is the value of ptr: " << ptr << endl;

	system("pause");
	return 0;
}