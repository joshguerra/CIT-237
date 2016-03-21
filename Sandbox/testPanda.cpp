/*
	Create array of objects
	pandaLab
	Josh Guerra
	created: 03.02.16
	modified: 03.07.16

	Class UML:
	Panda
	-----------------
	- name : string
	- weight : double
	- birthday : Date
	- numPandas : int
	- enum (BAMBOO = 1, SHOOTS, LEAVES, FRUIT = 5)
	-----------------
	+ constructor(s)
	+ getters
	+ setters
	+ destructor
	+ print(): void
	+ eat(weight_of_food : double) : void
	+ eat(weight_of_food : double, foodChoice : int) : void
	+ play() : void
	+ showFoodChoices() : void

	1) Create Panda.h and Panda.cpp
	2) Create testPanda.cpp with 1 panda using default constructor, 1 panda using 
		“arg-constructor”, 1 array of 5 pandas.
	3) Demonstrate!!
*/

#include "Panda.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

double myRand();

void main() {
	system("color 2f");					// change console color: 2 = green background, f = white text
	srand((unsigned int)time(NULL));	// given random generator new seed

	cout << rand() << endl << endl;
	system("pause");
}

double myRand() { return ((double)rand() / (RAND_MAX)); }