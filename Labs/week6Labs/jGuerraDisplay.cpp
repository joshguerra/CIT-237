/*
	File Utility Lab & Homework
	jGuerraDisplay
	by Josh Guerra
	Created 02.22.16
	Modified 02.25.16
	Reason(s):	Modified analysis to include new case.
				Completed design

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
		program -m filename		will perform "more" operation

		program -?				will print out directions for running the file from the command prompt

		program -l filename		will list number of lines in file

		program –h filename		will perform the "head" operation
		program –h n filename	will perform the "head" operation for n lines 

		program –t filename		will perform the "tail" operation
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


*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
//	Function Prototypes	 //
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

// returns true if file successfully opens, else returns false
bool openFileIn(fstream &file, string name);

void printHead(ifstream &file);
void printTail();
void printHead();	// overload
void printTail();	// overload
void printMore();
void printHelp();
void printFileLength();


int main(int argc, char *argv[]) {
	cout << "arguments: " << argc << endl;
	for (int i = 0; i < argc; i++) {
		cout << i << ": " << argv[i] << endl;
	}

	system("pause");
	return 0;
}

bool openFileIn(fstream &file, string name) {
	file.open(name, ios::in);

	if (file.fail())
		return false;
	return true;
}