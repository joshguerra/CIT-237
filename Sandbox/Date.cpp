#include "date.h"
#include <iostream>
using namespace std;

Date::Date() {
	year = 1900;
	month = 1;
	day = 1;
}

Date::Date(short m, short d, short y) {
	day = d;
	month = m;
	year = y;
}

void Date::print() {
	cout << month << '.' << day << '.' << year;
}