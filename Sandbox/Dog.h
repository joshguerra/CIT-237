#ifndef DOG_H
#define DOG_H
#include <string>
using namespace std;

class Dog {
private:
	double size;
	string name;

public:
	class NegativeSize {};
	class ZeroSize {};

	Dog(double s = 1.0, string n = "spot");

};

#endif