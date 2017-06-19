#include "Line.h" 

Line::Line() {
	numPoints = 2;
	pointArr = new Point[numPoints];

	pointArr[0] = { 0, 0 };
	pointArr[1] = { 3, 4 };

}

Line::Line(const Line &obj) {
	numPoints = obj.numPoints;
	pointArr = new Point[numPoints];

	for (int i = 0; i < numPoints; i++)
		pointArr[i] = obj.pointArr[i];
}

double Line::calcDist(Point a, Point b) {
	double changeX = a.x - b.x;
	double changeY = a.y - b.y;

	return sqrt(pow(changeX, 2.) + pow(changeY, 2.));
}

double Line::calcSlope(Point a, Point b) {
	double changeX = a.x - b.x;
	double changeY = a.y - b.y;

	return changeY / changeX;
}

void Line::printLine() {
	cout << "The line has points at:";
	for (int i = 0; i < numPoints; i++)
		cout << "\n(" << pointArr[i].x << ", " << pointArr[i].y << ")";
	cout
		<< "\nThe distance is " << calcDist(pointArr[0], pointArr[1])
		<< "\nThe slope is " << calcSlope(pointArr[0], pointArr[1]);
}