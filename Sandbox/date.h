#ifndef DATE_H
#define DATE_H

class Date {
private:
	short year;
	short month;
	short day;

public:
	void setYear(int y) { year = y; }
	void setMonth(int m) { month = m; }
	void setDay(int d) { day = d; }

	int getYear() { return int(year); }
	int getMonth() { return int(month); }
	int getDay() { return int(day); }

	Date();		// sets date to 01.01.1900
	Date(short m, short d, short y);
	void print();
};
#endif