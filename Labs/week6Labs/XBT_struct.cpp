/*
	Read XBT data into structs and output to binary
	XBT_struct
	by JGuerra
	Created 02.24.16
	Modified 02.24.16

	1  - open file
	2  - read in all good data once
	3  - parse date and time
	4  - find number of valid records
	5  - allocate array
	6  - file.clear and file.seekg
	7  - fill arrays
	8  - write struct to binary file
	9  - read binary back
	10 - print data to console

	*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// ~ ~ ~ ~ ~ ~ ~ //
//	Structures   //
// ~ ~ ~ ~ ~ ~ ~ //

struct Date {
	short year;
	short month;
	short day;
};

struct Time {
	short hours;
	short minutes;
};

struct Position {
	double lon;
	double lat;
};

struct DataPoint {
	double depth;
	double temp;
};

struct XBT {
	int seqNum;
	Date date;
	Time time;
	Position pos;
	int numRecords;
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
//	Function Prototypes	 //
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

// returns true if file successfully opens, else returns false
bool openFileIn(fstream &file, string name);

// requires valid open file
// returns number of valid xbt data points
// does not count first line of file (header line)
// stops counting entries once temp reaches 30
int findNumValidEntries(fstream &file);

// raw must contain a valid date in the format YYYYMMDD
// returns a Date structure initialized with date from raw
Date parseDate(long raw);

// raw must contain a valid time in the format HHMM
// returns a Time structure initialized with time from raw
Time parseTime(int raw);

// dataArray must be declared and of size n
// file must be open and read position at beginning of file
// reads in data from file to dataArray
void loadXBTdata(fstream &file, DataPoint* dataArray, int n);

// xbt and data must be initialized
// data points to array of length xbt.numRecords
// opens file with filename of name 
// file opened with access flags out and binary
// contents of xbt and data are written to file
// file is closed
void writeToBinary(fstream &file, string name, XBT xbt, DataPoint* data);

void printFromBinary(fstream &file, string name, XBT xbt, DataPoint* data);

int main() {
	// ~ ~ ~ ~ ~ ~ //
	//	Variables  //
	// ~ ~ ~ ~ ~ ~ //

	bool debug = false;

	// input file
	string fileName = "32XBT.flat1.txt";
	fstream xbtFile;

	// output file
	string datFile = "32XBT.dat";
	fstream xbtDatFile;
	fstream xbtBinFile;

	// pre-parsed input data
	long rawDate;
	int rawTime;

	// for dynamically allocated array
	DataPoint *data = nullptr;

	string xbtHeader;

	XBT xbtData;
	XBT xbtBinData = {};

	// ~ ~ ~ ~ ~ ~ //
	//	Procedure  //
	// ~ ~ ~ ~ ~ ~ //

	if (openFileIn(xbtFile, fileName)) {
		// get num of valid entries and declare array to hold them
		xbtData.numRecords = findNumValidEntries(xbtFile);
		data = new DataPoint[xbtData.numRecords];

		// read in data that is shared for all entries
		xbtFile >> xbtData.seqNum;
		xbtFile >> rawDate;
		xbtFile >> rawTime;
		xbtFile >> xbtData.pos.lon;
		xbtFile >> xbtData.pos.lat;

		// parse date and time
		xbtData.date = parseDate(rawDate);
		xbtData.time = parseTime(rawTime);

		if (debug) {
			cout
				<< "Number of Records: " << xbtData.numRecords << endl
				<< "Sequence #: " << xbtData.seqNum << endl
				<< "Date: " << long(xbtData.date.year) * 10000 +
				long(xbtData.date.month) * 100 + long(xbtData.date.day) << endl
				<< "Time: " << int(xbtData.time.hours) * 100 + int(xbtData.time.minutes) << endl
				<< "Longitude: " << xbtData.pos.lon << endl
				<< "Latitude: " << xbtData.pos.lat << endl;
		}

		// reset file and move read position to beg
		xbtFile.clear();
		xbtFile.seekg(0L, ios::beg);

		// read data into array
		loadXBTdata(xbtFile, data, xbtData.numRecords);

		// done with file
		xbtFile.close();

		if (debug) {
			for (int i = 0; i < xbtData.numRecords; i++)
				cout
				<< "Record #" << i << ": \tDepth: " << data[i].depth
				<< "\tTemp: " << data[i].temp << endl;
		}

		// write to output file
		writeToBinary(xbtDatFile, datFile, xbtData, data);
	}
	else
		cout << "could not load file..." << endl;

	// printing binary back out to console
	cout << "\n\tReading data in from binary..." << endl;
	system("pause");
	system("cls");

	// read and print header from original
	if (openFileIn(xbtFile, fileName)) {
		getline(xbtFile, xbtHeader);
		xbtFile.close();
		cout << xbtHeader << endl;
	}

	delete data;
	printFromBinary(xbtBinFile, datFile, xbtBinData, data);

	system("pause");
	return 0;
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //
//	Function Definitions   //
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

bool openFileIn(fstream &file, string name) {
	file.open(name, ios::in);

	if (file.fail())
		return false;
	return true;
}

int findNumValidEntries(fstream &file) {
	int count = 0;
	double temp = 0;

	// clear first line (header)
	file.ignore(100, '\n');

	// temps over 30 are invalid (given from instructions)
	while (file && temp < 30.0) {
		// move read position to temp column
		file.ignore(51);
		file >> temp;

		// test before incrementing count to avoid miscounting
		if (temp < 30.0)
			count++;
	}

	return count;
}

Date parseDate(long raw) {
	Date date;

	date.day = short(raw % 100);				// get last 2 digits
	date.month = short((raw / 100) % 100);		// get 3rd and 4th digits from the right
	date.year = short(raw / 10000);				// get first 4 digits

	return date;
}

Time parseTime(int raw) {
	Time time;

	time.minutes = short(raw % 100);			// get last 2 digits
	time.hours = short(raw / 100);				// get first 2 digits

	return time;
}

void loadXBTdata(fstream &file, DataPoint* dataArray, int n) {
	// clear first line (header)
	file.ignore(100, '\n');

	for (int i = 0; i < n; i++) {
		// move read position from beginning of line to depth column
		file.ignore(40);

		file >> dataArray[i].depth;
		file >> dataArray[i].temp;

		// move to begining of next line
		file.ignore(10, '\n');
	}
}

void writeToBinary(fstream &file, string name, XBT xbt, DataPoint* data) {
	// open file
	file.open(name, ios::out | ios::binary);

	// write xbt struct (all the unchanging data from xbt records)
	file.write(reinterpret_cast<char *>(&xbt), sizeof(xbt));

	// write data array (depth and temp pairs)
	for (int i = 0; i < xbt.numRecords; i++)
		file.write(reinterpret_cast<char *>(&data[i]), sizeof(data[i]));

	// close file
	file.close();
}

void printFromBinary(fstream &file, string name, XBT xbt, DataPoint* data) {
	long date;
	int time;

	// open file
	file.open(name, ios::binary | ios::in);

	// read xbt struct (all the unchanging data from xbt records)
	file.read(reinterpret_cast<char *>(&xbt), sizeof(xbt));
	data = new DataPoint[xbt.numRecords];

	// write data array (depth and temp pairs)
	for (int i = 0; i < xbt.numRecords; i++)
		file.read(reinterpret_cast<char *>(&data[i]), sizeof(data[i]));

	date = xbt.date.year * 1000L + xbt.date.month * 100L + long(xbt.date.day);
	time = int(xbt.time.hours) * 100 + int(xbt.time.minutes);

	// printing
	for (int i = 0; i < xbt.numRecords; i++)
		cout
			<< right << xbt.seqNum << setw(11) << date << setw(7) 
			<< time << setw(8) << xbt.pos.lon << setw(10) << xbt.pos.lat 
			<< "  " << setw(11) << left << data[i].depth << data[i].temp << endl;
			
}