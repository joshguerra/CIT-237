/*
	File Utility Lab & Homework
	jGuerraDisplay
	by Josh Guerra
	Created 02.22.16
	Modified 03.02.16
	Reason(s):	finished implementing non array version

	Analysis - from book (p705-6)

	File Head Program
		Write a program that asks the user for the name of a file.
		The program should display the first 10 lines of the file on the
		screen (the "head" of the file). If the file has fewer than 10 lines,
		the entire file should be displayed, with a message indicating the
		entire file has been displayed.

	Tail Program
		Write a program that asks the user for the name of a file.
		The program should display the last 10 lines of the file on the screen
		(the "tail" of the file). If the file has fewer than 10 lines, the
		entire file should be displayed, with a message indicating the
		entire file has been displayed.

	File More Program
		Write a program that asks the user for the name of a file.
		The program should display the contents of the file on the screen.
		If the file’s contents won’t fit on a single screen, the program
		should display 24 lines of output at a time, and then pause. Each
		time the program pauses, it should wait for the user to strike a
		key before the next 24 lines are displayed.

	Modifications (not in book):
	the file name will be passed as a command line argument.
	the program will do all three functions. it will decide which one
	based on the options given when executed from the command line.

	Cases:
		program filename
		program -?				will print out directions for running the file from the command prompt

		program -m filename		will perform "more" operation
		program -h filename		will perform the "head" operation
		program -t filename		will perform the "tail" operation
		program -l filename		will list number of lines in file

		program -h n filename	will perform the "head" operation for n lines
		program -t n filename	will perform the "tail" operation for n lines

	Design

	declare an fstream, string, and int variable
	declare a string pointer to create dynamically allocated array

	declare separate fstream and string variables for help text
	read help text into string array from input file

	open user provided file and count the number of lines (store in int)
	clear file and reset read position
	read each line into string array (allocate space using int)

	create functions for the head, tail, and more operations
	overload head and tail functions to change number of lines printed
	create function to print help instructions
	create function to count num lines in file

	assign each case an internal code 1-6
	make a switch case to decide which function to call and which arguments to use

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
//	Function Prototypes	 //
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

// return minimum of a and b
int min(int a, int b);

// returns true if file successfully opens, else returns false
bool openFileIn(fstream &file, string name);

// file stream must be valid and open
// returns number of lines in the file
// clears internal state flags 
// returns write position to beginning
int getNumLines(fstream &file, string name);

// open file
// print first n lines of file
// close file
void printHead(fstream &file, string name, int n = 10);

// open file
// print last n lines of file
// close file
void printTail(fstream &file, string name, int n = 10);

// open file
// print file, 24 lines at a time
// pause console each 24 lines
// clear console after pause
// close file
void printMore(fstream &file, string name);

// open file
// print whole file
// close file
void printFile(fstream &file, string name);

int main(int argc, char *argv[]) {
	// ~ ~ ~ ~ ~ ~ //
	//  Variables  //
	// ~ ~ ~ ~ ~ ~ //

	bool debug = false;

	string helpFileName = "fileUtilManual.txt";
	fstream helpFile;

	string fileName;
	fstream file;

	string text;

	// ~ ~ ~ ~ ~ ~ //
	//  Procedure  //
	// ~ ~ ~ ~ ~ ~ //

	if (debug) {
		cout << "arguments: " << argc << endl;
		for (int i = 0; i < argc; i++)
			cout << i << ": " << argv[i] << endl;
	}

	switch (argc) {
		case 2:
			// program -?			print help
			if (string(argv[1]) == "-?") {
				printFile(helpFile, helpFileName);
			}

			// program filename		print more
			else {
				fileName = argv[argc - 1];
				printMore(file, fileName);
			}

			break;

		case 3:
			fileName = argv[argc - 1];

			switch (argv[1][1]) {
				// program -m filename		print more
				case 'm':
					printMore(file, fileName);
					break;

				// program -h filename		print head
				case 'h':
					printHead(file, fileName);
					break;

				// program -t filename		print tail
				case 't':
					printTail(file, fileName);
					break;

				// program -l filename		print number of lines
				case 'l':
					openFileIn(file, fileName);
					cout << getNumLines(file, fileName) << endl;
					file.close();
					break;

				// help text if invalid switches used
				default:
					printFile(helpFile, helpFileName);
			}

			break;

		case 4:

			fileName = argv[argc - 1];
			switch (argv[1][1]) {
				// program -h filename		print head
				case 'h':
					printHead(file, fileName, atoi(argv[2]));
					break;

				// program -t filename		print tail
				case 't':
					printTail(file, fileName, atoi(argv[2]));
					break;
				
				// help text if invalid switches used
				default:
					printFile(helpFile, helpFileName);
			}

			break;

		// help text if invalid number of arguments used
		case 0:
		case 1:
		default:
			printFile(helpFile, helpFileName);
	}

	cout << endl;
	system("pause");
	return 0;
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
//	Function Definitions   //
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

bool openFileIn(fstream &file, string name) {
	file.open(name, ios::in);

	if (file.fail())
		return false;
	return true;
}

int getNumLines(fstream &file, string name) {
	int count = 0;

	while (file.ignore(100, '\n'))
		count++;

	file.clear();
	file.seekg(0L, ios::beg);

	return count;
}

void printHead(fstream &file, string name, int n) {
	string text;

	openFileIn(file, name);

	// print first n lines or until end of file
	for (int i = 0; i < n && getline(file, text); i++)
		cout << text << endl;

	file.close();
}

void printTail(fstream &file, string name, int n) {
	string text;
	int numLines;

	openFileIn(file, name);
	numLines = getNumLines(file, name);

	// ignore all but last n lines
	for (int i = 0; i < (numLines - n); i++)
		file.ignore(100, '\n');
	
	// print whats left
	while (getline(file, text)) {
		cout << text << endl;
	}
	file.close();
}

void printMore(fstream &file, string name) {
	string text;
	int more = 24;		// number of lines to print at a time
	int count = 0;

	openFileIn(file, name);
	while (getline(file, text)) {
		cout << text << endl;
		if (count++ % more == more - 1) {
			cout << endl;
			system("pause");
			system("cls");
		}
	}
	file.close();
}

void printFile(fstream &file, string name) {
	string text;

	openFileIn(file, name);
	while (getline(file, text)) {
		cout << text << endl;
	}
	file.close();
}