#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

void main() {
	int myInt, index;
	double myDbl;
	
	srand(time(NULL));

	string textFN = "data.txt";
	string binFN = "data.dat";

	fstream file;

	cout << "opening text input file... \n";
	file.open(textFN, ios::in);
	cout << "reading text from file: \n\n";
	while (file) {
		file >> myInt >> myDbl;
		if (!file.eof())
			cout << '\t' << myInt << " " << myDbl << endl;
	}
	file.close();
	cout << "\nclosing input file... \n";

	cout << "\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";

	cout << "opening binary input file... \n";
	file.open(binFN, ios::in | ios::binary);
	cout << "reading binary from file: \n\n";
	while (file) {
		file.read(reinterpret_cast<char *>(&myInt), sizeof(int));
		file.read(reinterpret_cast<char *>(&myDbl), sizeof(double));
		if (!file.eof())
			cout << '\t' << myInt << " " << myDbl << endl;
	}

	cout << "\nRandomly accessing data from file: \n\n";
	for (int i = 0; i < 20; i++) {
		// clear flags and reset read position to random entry
		file.clear();
		index = rand() % 10;
		file.seekg(long(index * (sizeof(int) + sizeof(double))));

		// read int and double
		file.read(reinterpret_cast<char *>(&myInt), sizeof(int));
		file.read(reinterpret_cast<char *>(&myDbl), sizeof(double));

		// print to console
		cout 
			<< "\treading " << i + 1 << ": \t" << "index " << index << " "
			<< myInt << " " << myDbl << endl;
	}

	cout << "\nclosing input file... \n\n";
	file.close();

	system("pause");
}