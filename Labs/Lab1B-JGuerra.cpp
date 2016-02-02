/*
	Grocery List - dynamically loading arrays
	FILE: Lab1B-1-JGuerra
	BY: JGuerra
	CREATED:	02.01.16
	MODIFIED:	02.01.16
*/

/*
	Analysis

	Make a grocery list stored in a string array of unknown length

	Part 1:
	User provides the length of the array
	User provides the items for the list
	Print the list back to the user
*/

/*
	Design:

	Declare a string pointer and an int to hold user input

	prompt user for length of grocery list
	use input and pointer to dynamically create array

	make function to load grocery list:
	for loop through length of list and prompt for next item
	add string input to array through pointer

	make function for printing the array

	make input functions

	Testing:
	I will be printing out what I input, so testing is taken care of
*/

#include <iostream>
#include <string>
using namespace std;

//  Pre Condition:  n <= to the LOGICAL size of a[]
//					os must be a valid open output stream
// Post Condition:  Prints the first n elements of a[] to os
void printStringArray(string a[], int n, ostream &os = cout);


//  Pre Condition:  0 < n
// Post Condition:  Creates a new string array starting at p with length of n
//					Prompts user for string (and loads it into the new array) n times
//					Sets isLoaded to true
void loadStringArray(string a[], int n);

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
	int length;

	int const SIZE_TITLE = 4;
	string title[SIZE_TITLE] = 
	{
		"\t\t      Lab 1B Part 1      ",
		"\t\t       Grocery List      ",
		"\t\t        by JGuerra       ",
		"\t\t Dynamically sized Array "
	};

	string *groceryList = nullptr;
	/*length = 3;
	groceryList = new string[length];
	groceryList[0] = "beans";
	groceryList[1] = "rice";
	groceryList[2] = "tortillas";*/

	printStringArray(title, SIZE_TITLE);
	cout << "\n\n";

	// prompt for list length
	cout << "How many items will be on your grocery list? ";
	length = getPosInt();
	cout << endl;

	loadStringArray(groceryList, length);
	printStringArray(groceryList, length);

	system("pause");
}

void printStringArray(string a[], int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << "\n" << a[i];
}

void loadStringArray(string a[], int n) {
	a = new string[n];

	for (int i = 0; i < n; i++) {
		cout << "What would you like to add to the grocery list? ";
		getline(cin >> ws, a[i]);
	}
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
