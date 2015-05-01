/*
	Person.h
		The class definition of the Person class.
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
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
