#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
	int month; // Month of year (1-12)
	int day;   // Day of month (28, 30, 31, depending)
	int year;  // Year (> 0)

	// Days per month of year (0 == January, etc.) 
	// leap year handling will be separate
	static int daysPerMonth[]; 
	
	//String array to hold names of months (0 == January, etc)
	static string monthNames[];

public:
	//// Constructors////

	// No arg constructor defaults to 1/1/1970
	Date();
	// Month = m, Day = d, Year = y
	Date(int m, int d, int y);

	//// Setters ////
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	//// Getters ////
	int getMonth();
	int getDay();
	int getYear();

	//// Overloaded Operators ////

	// ++ operator will add one day to date
	Date operator++();
	Date operator++(int);

	// -- operator will subtract one day from date
	Date operator--();
	Date operator--(int);

	// - operator returns difference between two dates (e.g. January 4 - January 1 = 3)
	int operator-(const Date&);

	// << operator will print date to specified stream
	string operator<<(ostream&);

	// >> operator will instatiate date from specified ostream
	Date operator>>(istream);

	//// Generic Validation Functions ////
	//returns a valid double
	double getNum();
	//returns valid int
	int getInt();
	//returns int in range [s, e]
	int getIntInRange(int s, int e);

	////  Specific Validation Functions ////

	// Gets valid date depending upon month
	int getValidDay();
	// Gets valid month (1-12)
	int getValidMonth();
	// Get valid year (> 0)
	int getValidYear();
	// Returns true if given year is a leap year
	bool isLeapYear(int year);
	// Normalizes date (e.g. 12/32/2016 -> 1/1/2017)
	void normalizeDate();
};

#endif