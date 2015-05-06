/*
	Person.cpp
		Implementation of the generic Person class which holds the social
		security number, first name, and last name of an individual. 
		
		Person is the parent class for Child, Wife, and Husband.
*/

#ifndef PERSON_CPP
#define PERSON_CPP

#include "Person.h"
using namespace std;

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes values to "unknown" type values.                            *
 ***************************************************************************/
	Person::Person()
	{
		SSN = 0;
		firstName = "None";
		lastName = "None";
	}
	
/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Is passed a social security number, first name, and last name and then  *
 * initializes the corresponding attributes with the passed values.        *
 ***************************************************************************/
	Person::Person(long social, string first, string last)
	{
		SSN = social;
		firstName = first;
		lastName = last;
	}
	
/***************************************************************************
 * ~Person                                                                 *
 *                                                                         *
 * The destructor                                                          *
 ***************************************************************************/
	Person::~Person()
	{
	}
	
/***************************************************************************
 * operator<<                                                              *
 *                                                                         *
 * Sets the output of an output stream call.                               *
 ***************************************************************************/
	ostream& operator<<(ostream& os, const Person& p)
	{
		os << "Name: " << p.firstName << " " << p.lastName << endl
			<< "Social Security: " << p.SSN << endl;
		return os;
	}
	
#endif

