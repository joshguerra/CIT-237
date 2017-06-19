#include <iostream>
#include "Dog.h"

void main() {

	// one //

	try {
		Dog one = Dog(60, "chucho");
	}
	catch (Dog::NegativeSize){
		cout << "Dogs can't have negative size!" << endl;
	}
	catch (Dog::ZeroSize){
		cout << "Dogs can't have a size of zero!" << endl;
	}

	// two //

	try {
		Dog two = Dog(0, "zero");
	}
	catch (Dog::NegativeSize){
		cout << "Dogs can't have negative size!" << endl;
	}
	catch (Dog::ZeroSize){
		cout << "Dogs can't have a size of zero!" << endl;
	}

	// three //

	try {
		Dog three = Dog(-12, "tiny");
	}
	catch (Dog::NegativeSize){
		cout << "Dogs can't have negative size!" << endl;
	}
	catch (Dog::ZeroSize){
		cout << "Dogs can't have a size of zero!" << endl;
	}

	system("pause");
}