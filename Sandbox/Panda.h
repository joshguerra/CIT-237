#ifndef PANDA_H
#define PANDA_H

#include <string>
#include "date.h"
using namespace std;

class Panda {
private:
	enum Food {BAMBOO = 1, SHOOTS, LEAVES, FRUIT = 5};
	static int numPandas;

	string name;
	Date birthday;
	double weight;

	// setters
	void setName(string n);
	void setBirthday(Date bday);
	void setWeight(double w);
	
public:
	// constructors and destructors
	Panda(string n = "Po");
	~Panda() {
		numPandas--;
		cout << "RIP" << name << endl;
	};

	// getters
	string getName() { return name; }
	Date getBirthday() { return birthday; }
	double getWeight() { return weight; }

	// other methods
	void print();
	void eat(double weightOfFood, int foodChoice = 1);
	void play();
	void showFoodChoices();
};

#endif