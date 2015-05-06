/*
	Person.h
		The class definition of the Person class.
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person{
	friend ostream& operator<<(ostream&, const Person&);
	protected:
	long SSN;
	std::string firstName;
	std::string lastName;
	
	public:
	Person();
	Person(long, std::string, std::string);
	~Person();

};

#endif
