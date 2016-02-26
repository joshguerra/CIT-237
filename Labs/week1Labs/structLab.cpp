/*
Car Lab - Demonstrating use of structures
FILE: carLab-JGuerra
BY: JGuerra
CREATED:	02.10.16
MODIFIED:	02.10.16
*/

#include <iostream>
using namespace std;

struct TempScale { 
	double fahrenheit;
	double centigrade;
};

struct Reading {
	int windSpeed;
	double humidity;
	TempScale temperature;
};

int getInt();
double getNum();

void showReading(Reading r);
void findReading(Reading &r);
Reading getReading();

void main() {
	Reading reading1;
	Reading reading2;
	Reading reading3;
	Reading reading4;

	reading1.windSpeed = 37;
	reading1.humidity = 32;
	reading1.temperature.fahrenheit = 32;
	reading1.temperature.centigrade = 0;

	cout << "Reading 1: \n";
	showReading(reading1);
	cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";

	findReading(reading2);
	cout << "\nReading 2: \n";
	showReading(reading2);
	cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";

	reading3 = getReading();
	cout << "\nReading 3: \n";
	showReading(reading3);
	cout << "\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";




	//showReading(reading4);

	system("pause");
}

int getInt() {
	double x = getNum();

	while (int(x) != x) {
		cout << "\tYour number is not an integer! \n\tTry Again: ";
		x = getNum();
	}

	return int(x);
}

double getNum() {
	double x;

	while (!(cin >> x)) {
		cin.clear();	cin.ignore(30, '\n');
		cout << "\tPlease no inapropriate characters! \n\tTry again: ";
	}
	cin.ignore(80, '\n');

	return x;
}

void showReading(Reading r) {
	cout
		<< "Wind Speed: " << r.windSpeed << " mph" << endl
		<< "Humidity: " << r.humidity << "%" << endl
		<< "Fahrenheit Temperature: " << r.temperature.fahrenheit << " degrees" << endl
		<< "Centigrade Temperature: " << r.temperature.centigrade << " degrees" << endl;
}

void findReading(Reading &r) {
	cout << "Please enter the wind speed: ";
	r.windSpeed = getInt();

	cout << "Please enter the humidity: ";
	r.humidity = getNum();

	cout << "Please enter the fahrenheit temperature: ";
	r.temperature.fahrenheit = getNum();

	cout << "Please enter the centigrade temperature: ";
	r.temperature.centigrade = getNum();
}

Reading getReading() {
	Reading r;

	cout << "Please enter the wind speed: ";
	r.windSpeed = getInt();

	cout << "Please enter the humidity: ";
	r.humidity = getNum();

	cout << "Please enter the fahrenheit temperature: ";
	r.temperature.fahrenheit = getNum();

	cout << "Please enter the centigrade temperature: ";
	r.temperature.centigrade = getNum();

	return r;
}

