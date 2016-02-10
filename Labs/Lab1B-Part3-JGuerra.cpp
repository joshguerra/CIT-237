/*
	Grocery List - dynamically loading arrays
	FILE: Lab1B-Part3-JGuerra
	BY: JGuerra
	CREATED:	02.03.16
	MODIFIED:	02.09.16
*/

/*
	Analysis

	Make a grocery list stored in a string array of unknown length

	Part 3:
	If groceries.txt exists, read it into the program
	print it for the user
	User provides number of additional items
	User provides additional items 
	Print the list back to the user
	Print list to groceries.txt
*/

/*
	Design:

	Declare a string pointer and an int to hold user input
	Declare an input file stream object and an output one too

	if groceries.txt exists:
		open groceries.txt and read into dynamically created array
		don't forget to close the file 
		
		prompt user for extention length of grocery list
		use input and pointer to dynamically extend the array

		make function to extend grocery list:
		for loop through extention length and prompt for next item
		add string input to array through pointer
	else
		prompt user for length of grocery list
		use input and pointer to dynamically create array

		make function to load grocery list:
		for loop through length of list and prompt for next item
		add string input to array through pointer

	make input functions
	make function for printing the array

	open file
	print to it using print function
	close file

	Testing:
	I will be printing out what I input, so testing is taken care of
	also can open file and view contents in windows file explorer
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//  Pre Condition:  n <= to the LOGICAL size of a[]
//					os must be a valid open output stream
// Post Condition:  Prints the first n elements of a[] to os
void printStringArray(string a[], int n, ostream &os = cout);

//  Pre Condition:  0 < n
// Post Condition:  Creates a new string array with length of n
//					Prompts user for string (and loads it into the new array) n times
string* makeStringArray(int n);

//  Pre Condition:  ifs must be a valid input file stream 
// Post Condition:  Creates a new string array and reads into it from ifs
//					Closes ifs
//					Returns a pointer to the new array
//					Sets n to length of the new array
string* connectFileAndReadStringArray(ifstream &ifs, int &n);

//  Pre Condition:  n is the physical size of a 
// Post Condition:  appends m elements to a
//					prompts user for the strings to append
//					Sets n to the new length of the array
//					returns the pointer for the array
string* extendStringArray(string* a, int &n, int m);

//  Pre Condition:	NONE
// Post Condition:	Returns a valid positive integer
//					Prints descriptive error messages
//					Removes everything from the cin buffer
//					Restores the cin object if needed
int getPosInt();

//  Pre Condition:	NONE
// Post Condition:	Returns a valid Integer
//					Prints descriptive error messages
//					Removes everything from the cin buffer
//					Restores the cin object if needed
int getInt();

//  Pre Condition:	NONE
// Post Condition:	Returns a valid number
//					Prints descriptive error messages
//					Removes everything from the cin buffer
//					Restores the cin object if needed
double getNum();

void main() {
	int numLines;
	int const SIZE_TITLE = 4;
	
	string fileName = "groceries.txt";
	string *groceryList = nullptr;

	string title[SIZE_TITLE] = {
		"\t\t      Lab 1B Part 3      ",
		"\t\t       Grocery List      ",
		"\t\t        by JGuerra       ",
		"\t\t Dynamically sized Array "
	};

	ifstream ifs;
	ofstream ofs;

	// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 

	// print title
	cout << endl;
	printStringArray(title, SIZE_TITLE);
	cout << "\n\n";

	// check for groceries.txt
	cout << "\n\tChecking for " << fileName << "...";
	ifs.open(fileName);

	// if open fails, make new array
	if (ifs.fail()) {
		// tell user what is happening
		cout
			<< "\n\tCould not find groceries.txt"
			<< "\n\tCreating new grocery list..."
			<< "\n\n";

		// prompt for list length
		cout << "How many items will be on your grocery list? ";
		numLines = getPosInt();

		// add items to list
		groceryList = makeStringArray(numLines);
	}

	// else, read in array and extend
	else {
		// tell user what is happening
		cout << "\n\tLoading list from groceries.txt...\n\n";
		groceryList = connectFileAndReadStringArray(ifs, numLines);

		// print to console
		cout << "\nHere is your grocery list: \n";
		printStringArray(groceryList, numLines);
		cout << "\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";
	}


	// print to console
	cout << "\nHere is your grocery list: \n";
	printStringArray(groceryList, numLines);
	
	// print to file
	cout << "\n\nPrinting list to " << fileName << "...";
	ofs.open(fileName);
	printStringArray(groceryList, numLines, ofs);
	ofs.close();
	cout << "\nDone printing list\n\n";

	system("pause");
}

void printStringArray(string a[], int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << (i == 0 ? "" : "\n") << a[i];
}

string* makeStringArray(int n) {
	string *a = new string[n];

	for (int i = 0; i < n; i++) {
		cout << "What would you like to add to the grocery list? ";
		getline(cin >> ws, a[i]);
	}

	return a;
}

string* connectFileAndReadStringArray(ifstream &ifs, int &n) {
	string *a = new string[];

	while (!ifs.eof()) {
		getline(ifs >> ws, a[n++]);
	}
	ifs.close();

	// n increments after each use to make room for next element of a
	// n results in a value 1 more than the physical size
	// the next line corrects the value
	n--;
	return a;
}

//  Pre Condition:  n is the physical size of a 
// Post Condition:  appends m elements to a
//					prompts user for the strings to append
//					Sets n to the new length of the array
//					returns the pointer for the array
string* extendStringArray(string* a, int &n, int m) {

}

int getPosInt() {
	int x = getInt();

	while (x < 1) {
		cout << "Please enter a positive integer bigger than 0: ";
		x = getInt();
	}

	return x;
}

int getInt() {
	double x = getNum();

	while (int(x) != x) {
		cout << "Please enter an integer: ";
		x = getNum();
	}

	return int(x);
}

double getNum() {
	double x;

	while (!(cin >> x)) {
		cin.clear();	cin.ignore(30, '\n');
		cout << "\tPlease no inapropriate characters! \n\tTry again: ";
	}
	cin.ignore(80, '\n');

	return x;
}