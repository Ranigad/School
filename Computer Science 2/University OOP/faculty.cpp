/*
	Implementation of the Faculty class
	Purpose: To model a faculty member in a university. 
*/

#ifndef FACULTY_CPP
#define FACULTY_CPP
#include <iostream>
#include "faculty.h"
using namespace std;

long Faculty::nextFacultyID = 600;	// Faculty IDs begin at 600
	
/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes all the data to the "default" data. Also utilizes the Person*
 * constructor.                                                            *
 ***************************************************************************/
Faculty::Faculty() : Person::Person()
{
	salary = 0;
	yearOfExp = 0;
	departID = 0;
	nextFacultyID++;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Takes in information including salary, years of experience, department  *
 * id, and personal information. Utilizes the Person constructor to        *
 * initialize the personal data.
 ***************************************************************************/
Faculty::Faculty(string nm, string eml, string addr, string dob, string gend, float sal, int years, long depID) : Person::Person(nextFacultyID, nm, eml, addr, dob, gend)
{
	salary = sal;
	yearOfExp = years;
	departID = depID;
	nextFacultyID++;
}

/***************************************************************************
 * ~Faculty                                                                *
 *                                                                         *
 * The destructor.                                                         *
 ***************************************************************************/
Faculty::~Faculty()
{
}

/***************************************************************************
 * getFacultyID                                                            *
 *                                                                         *
 * Returns the id of the faculty.                                          *
 ***************************************************************************/
long Faculty::getFacultyID()
{
	return id;
}

/***************************************************************************
 * getDepID                                                                *
 *                                                                         *
 * Returns the department ID of the faculty member.                        *
 ***************************************************************************/
long Faculty::getDepID()
{
	return departID;
}

/***************************************************************************
 * operator<<                                                              *
 *                                                                         *
 * Defines the output of cout << Faculty. Displays the name of the Faculty *
 * and then the ID in parentheses.                                         *
 ***************************************************************************/
ostream& operator<< (ostream& os, const Faculty& F)
{
	os << F.name << " (" << F.id << ")";
	return os;
}

#endif

