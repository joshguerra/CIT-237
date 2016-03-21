#include <iostream>
using namespace std;

int main() {
	int x = 1;

	cout << "only one post increment or pre increment in the statement.\n";
	cout << x++ << endl;

	x = 1;
	cout << ++x << endl;

	cout << "two post increment or pre increments in the statement.\n";
	x = 1;

	cout << x++ << " " << x++ << endl;

	x = 1;
	cout << ++x << " " << ++x << endl;

	cout << "three post increment or pre increments in the statement.\n";
	x = 1;

	cout << x++ << " " << x++ << " " << x++ << endl;

	x = 1;
	cout << ++x << " " << ++x << " " << ++x << endl;

	system("pause");
}