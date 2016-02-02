#include <iostream>
using namespace std;

void main() {
	int const SIZE = 5;
	int arr[SIZE] = {
		10, 20, 30, 40, 50
	};

	cout << "printing array normally:\n";
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << '\t';

	cout << "\n\n";

	cout << "printing array using pointer arithmetic:\n";
	for (int i = 0; i < SIZE; i++)
		cout << *(arr + i) << '\t';

	cout << "\n\n";

	cout << "printing array using bad pointer arithmetic:\n";
	for (int i = 0; i < SIZE; i++)
		cout << *arr + i << '\t';
		// doesn't actually change the value: adds i after reference, before print

	cout << "\n\n";

	cout << "printing array normally again:\n";
	for (int i = 0; i < SIZE; i++)
		cout << arr[i] << '\t';

	cout << "\n\n";

	system("pause");
}