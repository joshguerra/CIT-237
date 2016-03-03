#include <iostream>
#include "Box.h"
using namespace std;

int Box::numBoxes = 0;

Box::Box(double l, double w, double h) {
	setLength(l);
	setWidth(w);
	setHeight(h);
	numBoxes++;
}

double Box::getSurfaceArea() {
	double a1 = length * width;
	double a2 = length * height;
	double a3 = width * height;
	return 2 * (a1 + a2 + a3);
}

void Box::printBox() {
	cout
		<< "Box is " << width << " by " << length << " by " << height << endl
		<< "Box has Surface Area of " << getSurfaceArea()
		<< " and Volume of " << getVolume() << endl;
}