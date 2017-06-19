#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	int const SIZE = 10;
	int intArr[SIZE];
	double dblArr[SIZE];

	string textFN = "data.txt";
	string binFN = "data.dat";

	fstream file;

	for (int i = 0; i < SIZE; i++) {
		intArr[i] = (i + 10) * 557;
		dblArr[i] = i * 128.753;
	}

	cout << "opening text output file... \n";
	file.open(textFN, ios::out);
	cout << "writing text to file... \n";
	for (int i = 0; i < SIZE; i++)
		file << intArr[i] << " " << dblArr[i] << endl;
	cout << "closing output file... \n";
	file.close();

	cout << "\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";

	cout << "opening binary output file... \n";
	file.open(binFN, ios::out | ios::binary);
	cout << "writing binary to file... \n";
	for (int i = 0; i < SIZE; i++) {
		file.write(reinterpret_cast<char *>(&intArr[i]), sizeof(int));
		file.write(reinterpret_cast<char *>(&dblArr[i]), sizeof(double));
	}
	cout << "closing output file... \n";
	file.close();

	system("pause");
}