#include <iostream>
using namespace std;

class Box {
private : 
	int static numBoxes;
	double length;
	double width;
	double height;

public:
	Box(double l = 1, double w = 1, double h = 1);
	~Box() { cout << "Destructing..." << endl; numBoxes--; }

	// set to 1 if given a zero or negative value
	void setLength(double l) { length = (l <= 0 ? 1 : l); }
	void setWidth(double w) { width = (w <= 0 ? 1 : w); }
	void setHeight(double h) { height = (h <= 0 ? 1 : h); }

	double getLength() { return length; }
	double getWidth() { return width; }
	double getHeight() { return height; }
	int getNumBoxes() { return numBoxes; }

	double getVolume() { return length * width * height; }
	double getSurfaceArea();
	void printBox();
};