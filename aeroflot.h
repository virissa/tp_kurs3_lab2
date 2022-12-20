#pragma once
#include <iostream>
#include <string>

#define NAME 0
#define NUMBER 1
#define TYPE 2

using namespace std;



class aeroflot
{
	string prop[3];
	aeroflot* nextPtr;

public:

	aeroflot();

	string getName();
	string getNumber();
	string getType();
	aeroflot* getNextPtr();

	void setName(string str);
	void setNumber(string str);
	void setType(string str);
	void setNextPtr(aeroflot* p);

	friend std::ostream& operator<<(std::ostream& os, const aeroflot& p)
	{
		return os << "number: " << p.prop[NUMBER] << " place: " << p.prop[NAME] << " type: " << p.prop[TYPE] << endl;
	}

	friend std::istream& operator>>(std::istream& in, aeroflot& p)
	{
		std::cout << "number: ";
		in.clear();
		in.ignore();
		getline(in, p.prop[NUMBER]);

		std::cout << "place: ";
		in.clear();
		getline(in, p.prop[NAME]);

		std::cout << "type: ";
		in.clear();
		getline(in, p.prop[TYPE]);

		in.sync();

		return in;
	}

};