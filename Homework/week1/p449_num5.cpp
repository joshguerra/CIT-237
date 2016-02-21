/*
	Monkey Business - Exercise #5 on p449 of SOW C++
	Author: Josh Guerra
	Created: 02.21.16
	Modified: 02.21.16

	Analysis

	Taken from the book:
	A local zoo wants to keep track of how many pounds of food each of its three monkeys
	eats each day during a typical week. Write a program that stores this information in a
	two-dimensional 3 × 5 array, where each row represents a different monkey and each
	column represents a different day of the week. The program should first have the user
	input the data for each monkey. Then it should create a report that includes the following
	information:
	Average amount of food eaten per day by the whole family of monkeys.
	The least amount of food eaten during the week by any one monkey.
	The greatest amount of food eaten during the week by any one monkey.
	Input Validation: Do not accept negative numbers for pounds of food eaten.

	Since monkeys need to eat 7 days a week I'm going to make the array 3 x 7
	The program should read input in a total of 21 times to fill the array using doubles
	Ouptut only requires three steps


	Design

	declare a 2D array of doubles [3 x 7] to store input
	loop through rows
	loop troughs cols
	prompt user for input
	calculate avg
	find index of min and max

	display results

	functions:
	input validation [getPosNum]
	calculate total of each day
	should accept a 2D array and return a 1D array
	get avg of array
	get index of minimum element of 2d array
	get index of maximum element of 2d array

	Testing
	Monkies = {
	[3.0, 4.0, 3.5, 5.0, 4.8, 3.4, 3.6],
	[4.4, 4.2, 4.8, 4.4, 3.0, 3.8, 3.2],
	[4.7, 3.9, 4.1, 4.9, 3.9, 3.2, 4.2]
	}

	totals = [12.1, 12.1, 12.4, 14.3, 11.7, 10.4, 11.0]
	Avg = 12.0 // rounded to nearest 0.1
	Min = monkies[0][0] = 3.0
	Max = monkies[0][3] = 5.0

	Also, going to need a function for printing a 2D & 1D array

	*/

#include <iostream>
#include <string>
using namespace std;

int const NUM_MONKIES = 3, DAYS = 7;

//  Pre Condition:  0 < n <= to the LOGICAL size of a
//					os must be a valid open output stream
// Post Condition:  Prints the first n elements of a to os
void printStringArr(string a[], int n, ostream &os = cout);

//  Pre Condition:  0 < n <= to the PHYSICAL size of the first dimension of a
//					0 < m <= to the PHYSICAL size of the second dimension of a
//					os must be a valid open output stream
// Post Condition:  Prints out the contents of a, m per line
void print2DArrOfDbl(double a[][DAYS], int n, int m, ostream &os = cout);

//  Pre Condition:  0 < n <= to the PHYSICAL size of a
//					os must be a valid open output stream
// Post Condition:  Prints out the contents of a
void printArrOfDbl(double a[], int n, ostream &os = cout);

//  Pre Condition:	NONE
// Post Condition:	Returns a valid positive number
//					Prints descriptive error messages
//					Removes everything from the cin buffer
//					Restores the cin object if needed
double getPosNum();

//  Pre Condition:	NONE
// Post Condition:	Returns a valid number
//					Prints descriptive error messages
//					Removes everything from the cin buffer
//					Restores the cin object if needed
double getNum();

//  Pre Condition:	a is 2D array with 2nd dim size equal to DAYS
//					n is size of 1st dim
//					m is size of 2nd dim
// Post Condition:	Returns a pointer to a new array of length m
//					each element is the total of all elements with the same 1st dim index
double* getTotalOfEachCol(double a[][DAYS], int n, int m);

//  Pre Condition:	0 < n <= to the LOGICAL size of a
// Post Condition:	Returns the average of the array's contents
double calcAvg(double a[], int n);

//  Pre Condition:	a is 2D array with 2nd dim size equal to DAYS
//					n is size of 1st dim
//					m is size of 2nd dim
// Post Condition:	sets the values of index1 and index2 to the indexes of the lowest value in a
void findIndexOfMin(double a[][DAYS], int n, int m, int &index1, int &index2);

//  Pre Condition:	a is 2D array with 2nd dim size equal to DAYS
//					n is size of 1st dim
//					m is size of 2nd dim
// Post Condition:	sets the values of index1 and index2 to the indexes of the highest value in a
void findIndexOfMax(double a[][DAYS], int n, int m, int &index1, int &index2);

void main() {
	bool debug = false;

	const int SIZE_TITLE = 4;
	string title[SIZE_TITLE] = {
		"\t\tMonkey Business",
		"\t\tSOW C++ p449 #5",
		"\t\t  by J Guerra  ",
		"\n"
	};

	string days[DAYS] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	double monkies[NUM_MONKIES][DAYS];
	double* totals;
	double avg;
	int indexOfMin1, indexOfMin2, indexOfMax1, indexOfMax2;

	// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

	printStringArr(title, SIZE_TITLE);
	for (int i = 0; i < NUM_MONKIES; i++) {
		for (int j = 0; j < DAYS; j++) {
			cout << "Enter the amount that monkey " << i + 1 << " ate on " << days[j] << " : ";
			monkies[i][j] = getPosNum();
		}
		cout << endl;
	}

	totals = getTotalOfEachCol(monkies, NUM_MONKIES, DAYS);
	avg = calcAvg(totals, DAYS);
	findIndexOfMin(monkies, NUM_MONKIES, DAYS, indexOfMin1, indexOfMin2);
	findIndexOfMax(monkies, NUM_MONKIES, DAYS, indexOfMax1, indexOfMax2);

	if (debug) {
		cout << "Here is your array of monkey eating ammounts:\n";
		print2DArrOfDbl(monkies, NUM_MONKIES, DAYS);
	}

	if (debug) {
		cout << "Here is your array of daily monkey eating totals:\n";
		printArrOfDbl(totals, DAYS);
	}

	cout
		<< "Average daily amount of food eaten by all the monkies: " 
		<< avg << endl
		<< "Least amount of food eaten in one day by a single monkey: "
		<< monkies[indexOfMin1][indexOfMin2] << endl
		<< "Most amount of food eaten in one day by a single monkey: "
		<< monkies[indexOfMax1][indexOfMax2] << endl << endl;

	system("pause");
}

void printStringArr(string a[], int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << "\n" << a[i];
}

void print2DArrOfDbl(double a[][DAYS], int n, int m, ostream &os) {
	cout << "\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << "\t" << a[i][j] << (j % m == m - 1 ? "\n" : ", ");
}

void printArrOfDbl(double a[], int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << "\t" << a[i] << (i % n == n - 1 ? "\n" : ", ");
}

double getPosNum() {
	double x = getNum();

	while (x < 0) {
		cout << "\a\tPlease no negative numbers \n\tTry again: ";
		x = getNum();
	}

	return x;
}

double getNum() {
	double x;

	while (!(cin >> x)) {
		cin.clear();	cin.ignore(30, '\n');
		cout << "\a\tPlease no inapropriate characters! \n\tTry again: ";
	}
	cin.ignore(80, '\n');

	return x;
}

double* getTotalOfEachCol(double a[][DAYS], int n, int m) {
	double* totals = new double[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0)
				totals[j] = a[0][j];
			else
				totals[j] += a[i][j];
		}
	}

	return totals;
}

double calcAvg(double a[], int n) {
	double total = 0;

	for (int i = 0; i < n; i++)
		total += a[i];

	return total / n;
}

void findIndexOfMin(double a[][DAYS], int n, int m, int &index1, int &index2) {
	index1 = index2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < a[index1][index2]) {
				index1 = i;
				index2 = j;
			}
		}
	}
}

void findIndexOfMax(double a[][DAYS], int n, int m, int &index1, int &index2) {
	index1 = index2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > a[index1][index2]) {
				index1 = i;
				index2 = j;
			}
		}
	}
}