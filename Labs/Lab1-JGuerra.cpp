#include <iostream>
using namespace std;

int main() {
	int a = 3, b = 4, c = 5;
	int *p = &a;

	cout
		<< "value1: " << a << endl
		<< "address of value1: " << &a << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p 
		<< endl << endl;

	*p = 13;

	cout
		<< "value1: " << a << endl
		<< "address of value1: " << &a << endl
		<< "value of pointer: " << p << endl
		<< "value where pointer is looking: " << *p
		<< endl << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;

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