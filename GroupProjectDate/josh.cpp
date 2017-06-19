// Group Project 1 - Date Class
// josh.cpp
// Validation and stream extraction operator overload

/*
getNum():double			+
getInt():int			+
getIntInRange():int		+

getValidDate():int		+
getValidMonth():int		+
getValidYear():int		+
isLeapYear(date:Date):bool
normalizeDate(date:Date):void

operator>>():void
*/

#include <iostream>
#include "Date.h"
#include "Date.cpp"
using namespace std;

double Date::getNum() {
	double x;

	while (!(cin >> x)) {
		cin.clear();	cin.ignore(30, '\n');
		cout << "\tPlease no inapropriate characters! \n\tTry again: ";
	}
	cin.ignore(80, '\n');

	return x;
}

int Date::getInt() {
	double x = getNum();

	while (int(x) != x) {
		cout << x << " is not an integer! \n\tTry Again: ";
		x = getNum();
	}

	return int(x);
}

int Date::getIntInRange(int s, int e) {
	int x = getInt();

	while (x < s || x > e) {
		cout
			<< "\tYour number must be "
			<< (x < s ? "greater" : "less")
			<< " than or equal to "
			<< (x < s ? s : e)
			<< ". \n\tTry again: ";
		x = getInt();
	}

	return x;
}

int Date::getValidDay() {
	int d = getIntInRange(1, daysPerMonth[month]);
	return d;
}

int Date::getValidMonth() {
	int m = getIntInRange(1, 12);
	return m;
}

int Date::getValidYear() {
	int y = getInt();

	while (y <= 0) {
		cout
			<< "\tPlease enter a year greater than 0."
			<< "\n\tTry again: ";
		y = getInt();
	}
	return y;
}

bool Date::isLeapYear(int year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void Date::normalizeDate() {
	while (month > 12 || day > daysPerMonth[month] + isLeapYear(year)) {
		while (month > 12) {
			year++;
			month -= 12;
		}
		while (day > daysPerMonth[month]) {
			month++;
			day -= daysPerMonth[month] + isLeapYear(year);
		}
	}
}

istream &operator >> (istream &is, Date &obj) {
	cout << "Year: ";
	obj.setYear(obj.getValidYear());

	cout << "Month: ";
	obj.setMonth(obj.getValidMonth());

	cout << "Day: ";
	obj.setDay(obj.getValidDay());

	return is;
}

void main() {
	

	system("pause");
}