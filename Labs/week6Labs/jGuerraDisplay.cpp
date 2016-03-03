/*
	File Utility Lab & Homework
	jGuerraDisplay
	by Josh Guerra
	Created 02.22.16
	Modified 03.02.16
	Reason(s):	reworking reading and printing

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
	program –h filename		will perform the "head" operation
	program –t filename		will perform the "tail" operation
	program -l filename		will list number of lines in file

	program –h n filename	will perform the "head" operation for n lines
	program –t n filename	will perform the "tail" operation for n lines

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

	// opens file
	// finds number of lines in file
	// dynamically allocate array from pointer
	// read file text into array
	// close file
	// returns numLines
	int readFromFile(string* a, fstream &file, string fileName);

	int readFromFile(string* a, fstream &file, string fileName) {
	int numLines;

	if (openFileIn(file, fileName)) {
	numLines = getNumLines(file);
	a = new string[numLines];
	loadStringArrayFromFile(a, numLines, file);
	file.close();
	}

	return numLines;
	}


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
int getNumLines(fstream &file);

// 0 < n <= number of lines of text in file with filename  
// 0 < n <= to the PHYSICAL size of a
// file must be valid and open
// Loads first n lines from file into the first n elements of a
// clears internal state flags of file
// returns write position to beginning
void loadStringArrayFromFile(string* a, int n, fstream &file);

// 0 < n <= LOGICAL size of a   
// os must be a valid open output stream
// prints the first n elements of a[] to os
void printStringArr(string* a, int n, ostream &os = cout);

// 0 < start <= LOGICAL size of a   
// 0 < end <= LOGICAL size of a
// start < end
// os must be a valid open output stream
// prints to os from a[start](inclusively) to a[end](exlusively)
void printStringArr(string* a, int start, int end, ostream &os = cout);

void printHead(string* text, int numLines, int n = 10);
void printTail(string* text, int numLines, int n = 10);
void printMore(string* text, int numLines);

int main(int argc, char *argv[]) {
	// ~ ~ ~ ~ ~ ~ //
	//  Variables  //
	// ~ ~ ~ ~ ~ ~ //

	bool debug = false;

	string helpFileName = "fileUtilManual.txt";
	fstream helpFile;
	int numLinesHelp;

	string fileName;
	fstream file;
	int numLines;


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
			if (string(argv[1]) == "-?") {
				// display help text
				openFileIn(helpFile, helpFileName);
			}
			else {
				// more program
				fileName = argv[argc - 1];
				numLines = readFromFile(fileText, file, fileName);
				printMore(fileText, numLines);
			}
			break;

		case 3:

			fileName = argv[argc - 1];
			numLines = readFromFile(fileText, file, fileName);

			switch (argv[1][1]) {
				case 'm':
					printMore(fileText, numLines);
					break;
				case 'h':
					printHead(fileText, numLines);
					break;
				case 't':
					printTail(fileText, numLines);
					break;
				case 'l':
					cout << numLines << endl;
				default:
					// display help text
					printStringArr(helpText, numLinesHelp);
			}

			break;

		case 4:

			fileName = argv[argc - 1];
			numLines = readFromFile(fileText, file, fileName);

			switch (argv[1][1]) {
				case 'h':
					printHead(fileText, numLines, atoi(argv[2]));
					break;
				case 't':
					printTail(fileText, numLines, atoi(argv[2]));
					break;
				default:
					// display help text
					printStringArr(helpText, numLinesHelp);
			}

			break;

		case 0:
		case 1:
		default:
			printStringArr(helpText, numLinesHelp);
	}

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

int getNumLines(fstream &file) {
	int count = 0;

	while (file.ignore(100, '\n'))
		count++;

	file.clear();
	file.seekg(0L, ios::beg);

	return count;
}

void loadStringArrayFromFile(string* a, int n, fstream &file) {
	for (int i = 0; i < n; i++)
		getline(file, a[i]);

	file.clear();
	file.seekg(0L, ios::beg);
}

void printStringArr(string* a, int n, ostream &os) {
	for (int i = 0; i < n; i++)
		os << "\n" << a[i];
}

void printStringArr(string* a, int start, int end, ostream &os) {
	for (int i = start; i < end; i++)
		os << "\n" << a[i];
}

void printHead(string* text, int numLines, int n) {
	if (numLines < n)
		printStringArr(text, numLines);
	else
		printStringArr(text, n);
}

void printTail(string* text, int numLines, int n) {
	if (numLines < n)
		printStringArr(text, numLines);
	else
		printStringArr(text, numLines - n, numLines);
}

void printMore(string* text, int numLines) {
	int more = 24,		// number of lines to print at a time
		currentLine = 0,
		linesLeft = numLines;

	while (linesLeft) {
		if (linesLeft < more) {
			printStringArr(text, linesLeft);
			currentLine += linesLeft;
			linesLeft = 0;
		}
		else {
			printStringArr(text, currentLine, currentLine + more);
			currentLine += more;
			linesLeft -= more;
		}

	}

}