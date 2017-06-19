#include <iostream>
#include <vector>
using namespace std;

template <class T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <class T>
T min(T a, T b) {
	return (a < b ? a : b);
}

template <class T1, class T2>
bool isBigger(T1 a, T2 b) {
	return a > b;
}

void main() {

	int one, two;
	double a, b;
	char x, y;

	system("color 2f");

	cout
		<< "\t\tsimple template program\n"
		<< "\t\t min and max functions \n"
		<< "\t\t     by J. Guerra      \n\n";

	cout << "Please provide two integers: ";
	cin >> one >> two;
	cout << "Min: " << min(one, two) << "\t\tMax: " << max(one, two) << endl << endl;

	cout << "Please provide two doubles: ";
	cin >> a >> b;
	cout << "Min: " << min(a, b) << "\t\tMax: " << max(a, b) << endl << endl;

	cout << "Please provide two characters: ";
	cin >> x >> y;
	cout << "Min: " << min(x, y) << "\t\tMax: " << max(x, y) << endl << endl;

	vector <int> numbers(10, 5);
	vector <char> letters(10, 'q');
	cout 
		<< "Comparing vector of ten 5's and vector of ten q's: " << endl
		<< "The vector of " << (isBigger(numbers, letters) ? "numbers" : "letters") 
		<< " is bigger." << endl << endl;

	system("pause");
}