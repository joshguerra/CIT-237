#ifndef LINE_H
#define LINE_H
#include <iostream>
using namespace std;

struct Point{
	double x; 
	double y;
};

class Line {
public:
	Point *pointArr = nullptr;
	int numPoints = 0;

	Line();
	Line(const Line &obj);

	double calcDist(Point a, Point b);
	double calcSlope(Point a, Point b);

	void printLine();
};

#endif