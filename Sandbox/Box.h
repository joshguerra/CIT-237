#ifndef BOX_H
#define BOX_H
#include <iostream>
using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
	double checkValue(double v);
	static int numBoxes;

public:
	//Box();
	Box(double l = 1., double w = 1., double h = 1.);

	~Box() {
		numBoxes--;
		cout << "destructor called\n";
	}
	
	int getNumBoxes() const { return numBoxes; }
	void setLength(double l);
	void setWidth(double w);
	void setHeight(double h);

	double getLength() const { return length; }
	double getHeight() const { return height; }
	double getWidth() const { return width; }

	double getSurfaceArea();
	double getVolume();
	void printBox();
};
#endif