/*
	Implementation for the class Department
	Purpose: To represent a department within the university.
*/

#ifndef DEPARTMENT_CPP
#define DEPARTMENT_CPP
#include <iostream>
#include "department.h"
using namespace std;

long Department::nextDepartID = 100;	// The first department id is 100

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Assigns the next open department id to id and increments it. Fills the  *
 * name, location, and chair with default values that represent no info.   *
 ***************************************************************************/
Department::Department()
{
	id = nextDepartID++;
	name = "None";
	location = "None";
	chairID = -1;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Assigns the next open department id to id and increments it. Takes in a *
 * name, department location, and chair id and assigns it properly.        *
 ***************************************************************************/
Department::Department(string nm, string loc, long chID)
{
	id = nextDepartID++;
	name = nm;
	location = loc;
	chairID = chID;
}

/***************************************************************************
 * ~Department                                                             *
 *                                                                         *
 * The destructor                                                          *
 ***************************************************************************/
 
Department::~Department()
{
}

/***************************************************************************
 * getDepartmentID                                                         *
 *                                                                         *
 * Returns the id of the department.                                       *
 ***************************************************************************/
long Department::getDepartmentID()
{
	return id;
}

/***************************************************************************
 * getName                                                                 *
 *                                                                         *
 * Returns the name of the department.                                     *
 ***************************************************************************/
string Department::getName()
{
	return name;
}

/***************************************************************************
 * getChairID 	                                                           *
 *                                                                         *
 * Returns the id of the department chair.                                 *
 ***************************************************************************/
long Department::getChairID()
{
	return chairID;
}

/***************************************************************************
 * setChair                                                                *
 *                                                                         *
 * Takes a passed in value and makes it the new chair ID				   *
 ***************************************************************************/
void Department::setChair(long chID)
{
	chairID = chID;
}

/***************************************************************************
 * operator<<                                                              *
 *                                                                         *
 * Defines the output of cout << Department. Displays the name of the      *
 * department and then the id in parentheses. 		                       *
 ***************************************************************************/
ostream& operator<< (ostream& os, const Department& D)
{
	os << D.name << " (" << D.id << ")";
	return os;
}

#endif

