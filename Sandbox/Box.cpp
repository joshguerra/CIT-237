#include "Box.h"
#include <iostream>
using namespace std;

int Box::numBoxes = 0;

Box::Box(double l, double w, double h) {
	setLength(l);
	setWidth(w);
	setHeight(h);
	numBoxes++;
}
/*
	Box::Box() {
		setLength(1);
		setWidth(1);
		setHeight(1);
	} 
*/
double Box::checkValue(double v) {
	if (v <= 0){
		v = 1;
	//	cout << "Invalid value; must be > 0.";
	//	exit(EXIT_FAILURE);
	}
		return v;
	}
void Box::setLength(double l) {
		l = checkValue(l);
		length = l;
	}
void Box::setWidth(double w) {
		w = checkValue(w);
		width = w;
	}
void Box::setHeight(double h) {
		h = checkValue(h);
		height = h;
	}
double Box::getSurfaceArea() {
		double t1 = length * width;
		double t2 = width * height;
		double t3 = length * height;
		return (2 * (t1 + t2 + t3));
	}
double Box::getVolume() {
		return (length * width * height);
	}
void Box::printBox() {
		cout << "This box has length " << length << ", width " <<
			width << ", height " << height << endl;
		cout << "The volume of this box is " << getVolume() << " and the "
			<< "surface area is " << getSurfaceArea() << endl;
	}
