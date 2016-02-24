/*
	File Utility Lab & Homework
	by Josh Guerra
	Created 02.22.16
	Modified 02.22.16

	Analysis - from book (p705-6)

	File Head Program   
		Write a program that asks the user for the name of a file. 
		The program should display the first 10 lines of the file on the 
		screen (the “head” of the file). If the file has fewer than 10 lines, 
		the entire file should be displayed, with a message indicating the 
		entire file has been displayed. 

	Tail Program   
		Write a program that asks the user for the name of a file. 
		The program should display the last 10 lines of the file on the screen 
		(the “tail” of the file). If the file has fewer than 10 lines, the 
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

*/

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc)
}