#include "Dog.h"
using namespace std;

Dog::Dog(double s, string n) {
	if (s < 0)
		throw NegativeSize();
	else if (s == 0)
		throw ZeroSize();
	else
		size = s;

	name = n;
}
