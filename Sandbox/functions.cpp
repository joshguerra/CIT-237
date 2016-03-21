#include "functions.h"
#include <iostream>
using namespace std;

double getNumInRange(double start, double end) {    //    DONE
	double x = getNum();

	while (x < start || x > end) {
		cout
			<< "\tYour number must be "
			<< (x < start ? "greater" : "less")
			<< " than or equal to "
			<< (x < start ? start : end)
			<< ". \n\tTry again: ";
		x = getNum();
	}

	return x;
}