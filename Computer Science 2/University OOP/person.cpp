/*
	Implementation of the Person Class.
	Purpose: To be the super class of the Faculty and Student classes.
		Consolidates the personal information that both share.
*/

#ifndef PERSON_CPP
#define PERSON_CPP
#include <iostream>
#include "person.h"
using namespace std;

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes all values to "unknown" values.		                       *
 ***************************************************************************/
Person::Person()
{
	id = 0;
	name = "None";
	email = "None";
	address = "None";
	dateOfBirth = "None";
	gender = "None";
}
	
/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Takes in various personal information and initializes the corresponding *
 * attributes. Primarily used as part of the Faculty/Student constructor.  *
 ***************************************************************************/
Person::Person(long idNum, string nm, string eml, string add, 
				string dob, string gend)
{
	id = idNum;
	name = nm;
	email = eml;
	address = add;
	dateOfBirth = dob;
	gender = gend;
}
	
/***************************************************************************
 * ~Person                                                                 *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
Person::~Person()
{
}
	
/***************************************************************************
 * getID                                                                   *
 *                                                                         *
 * Returns the ID of the individual.                                       *
 ***************************************************************************/ 
long Person::getID()
{
	return id;
}
	
/***************************************************************************
 * getName                                                                 *
 *                                                                         *
 * Returns the name of the individual.                                     *
 ***************************************************************************/
string Person::getName()
{
	return name;
}

#endif

