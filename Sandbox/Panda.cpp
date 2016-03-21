#include "Panda.h"
using namespace std;

Panda::Panda(string n) {
	Date date;
	// set a birthday at random


	
	switch (date.getMonth()) {
		// range of dates is 1 - 28
		// 1 - 29 if leap year
		case 2:
		// range of dates is 1 - 30
		case 4:
		case 6:
		case 9:
		case 11:
		// range of dates is 1 - 31
		default:

	}


	setName(n);
	setBirthday(date);
	// setWeight();
	numPandas++;
}

void Panda::setName(string n) {
	name = n;
}
void Panda::setBirthday(Date bday) {
	birthday = bday;

}
void Panda::setWeight(double w) {

}