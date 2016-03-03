#include <iostream>
#include <string>
using namespace std;

class Panda {
private:
	string name;
	double weight;
	Date birthday;
	static int numPandas;

public:
	Panda(string n = "Po", double w = 300, Date bday = { 2012, 11, 05 });
	~Panda();

	void setName(string n) { name = n; }
	void setBirthday(Date bday);

	// lower bound is 0.2 lbs (cub). upper bound 400 lbs
	void setWeight(double w) { weight = (w < 0.2 ? 0.2 : w > 400 ? 400 : w); }


};

struct Date {
	short year;
	short month;
	short day;
};