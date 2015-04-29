/*
	Class definition for the Person class
*/

#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std; 

class Person {
	protected:
	// Super class to Faculty and Student. Consolidate personal information
	long id;
	string name;
	string email;
	string address;
	string dateOfBirth;
	string gender;

	public:
	// Constructor / Destructor
	Person();
	Person(long, string, string, string, string, string);
	~Person();
	
	// Accessors
	long getID();
	string getName();
};

#endif

