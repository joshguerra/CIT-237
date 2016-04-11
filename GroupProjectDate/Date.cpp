#include "Date.h"
#include <iostream>
using namespace std;

int Date::daysPerMonth[] = {
	31, 28, 31, 30, 31, 30, 31,
	31, 30, 31, 30, 31 };

string Date::monthNames[] = {
	"January", "February", "March",
	"April", "May", "June", "July",
	"August", "September", "October",
	"November", "December" };

//// Constructors////

// No arg constructor defaults to 1/1/1970
// Month = m, Day = d, Year = y
Date::Date(int m = 1, int d = 1, int y = 1970) {
	if (m > 12 || m < 1) m = 1;
	month = m;
	if (d > 31 || d < 1) d = 1;
	day = d;
	if (y <= 0) y = 1970;
	year = y;
}

//// Setters ////

void Date::setMonth(int m){
	if (m > 12 || m < 1) m = 1;
	month = m;
}
void Date::setDay(int d){
	if (d > 31 || d < 1) d = 1;
	day = d;
}
void Date::setYear(int y){
	if (y <= 0) y = 1970;
	year = y;
}

//// Getters ////
int Date::getMonth(){
	return month;
}
int Date::getDay(){
	return day;
}
int Date::getYear(){
	return year;
}

//// Overloaded Operators ////

//// - operator returns difference between two dates (e.g. January 4 - January 1 = 3)
//int Date::operator-(const Date& d){
//	// startYear variable used to determine leap years between years
//	int startYear = this->year;
//	// endYear variable used to determine leap years between years
//	int endYear = d.year;
//	// numLeapYears handles adding leap days to difference, d1Dist and d2Dist are "disttance from January), difference is value to return
//	int numLeapYears, d1Dist, d2Dist, difference = 0;
//
//	// If dates are in same month of same year, simply return difference in days
//	if (d.year == this->year && d.month == this->month)
//		return this->day - d.day;
//
//	else {
//		// Otherwise begin calculating number of leap days (conditional to handle negative outcome)
//		if (startYear < endYear) {
//			for (startYear; startYear < endYear; startYear++)
//				if (isLeapYear(startYear)) numLeapYears++;
//		}
//		else {
//			for (startYear; startYear > endYear; startYear--)
//				if (isLeapYear(startYear)) numLeapYears++;
//		}
//
//		// difference based on years is years * 365 days + number of leap days
//		difference += (this->year - d.year) * 365 + numLeapYears;
//
//		// Calculate distance from January based upon daysPerMonth values
//		for (int i = 0; i < this->month - 1; i++) {
//			d1Dist += this->daysPerMonth[i];
//		}
//		d1Dist += this->day;
//
//		// Do the same for second date
//		for (int i = 0; i < d.month - 1; i++) {
//			d2Dist += d.daysPerMonth[i];
//		}
//		d2Dist += d.day;
//
//		// Difference in distance from January
//		difference += d1Dist - d2Dist;
//
//		return difference;
//	}
//}
//
//
//// << operator will print date to specified stream
//string Date::operator<<(ostream &output){
//	output << this->monthNames[this->month] << " " << this->day << ", " << this->year;
//}