#ifndef PERSON_CPP
#define PERSON_CPP

#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

	void Person::setAPerson(long SSNum, string first, string last, int ag, char gen)
	{
		SSN = SSNum;
		firstName = first;
		lastName = last;
		age = ag;
		gender = gen;
	}
	
	void Person::printAPerson()
	{
		cout << "Social Security Number: " << SSN << endl
			<< "Name: " << firstName << " " << lastName << endl
			<< "Age: " << age << endl
			<< "Gender: ";
			
		if (gender == 'M')
			cout << "Male" << endl;
		else if (gender == 'F')
			cout << "Female" << endl;
	}
	
#endif

