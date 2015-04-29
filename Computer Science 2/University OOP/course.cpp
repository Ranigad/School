/*
	Implementation of the Course Class
	Purpose: To represent a course at a university. Is part of a department,
		has a course registration number, and tracks seating and seating limits
*/

#ifndef COURSE_CPP
#define COURSE_CPP

#include <iostream>
#include "course.h"

long Course::nextCRN = 200;	// CRN of courses begin at 200

/***************************************************************************
 * Default Constructor                                                     *
 *                                                                         *
 * Initializes all the data to "unknown" type data.                        *
 ***************************************************************************/
Course::Course()
{
	CRN = nextCRN++;
	maxAvailableSeats = 0;
	name = "None";
	departID = -1;
	assignedSeats = 0;
	isTaughtBy = 0;
}

/***************************************************************************
 * Constructor                                                             *
 *                                                                         *
 * Assigns the CRN and increments the "nextCRN. Takes the name of the class*
 * the department it belongs to, and who it's taught by and assigns the    *
 * appropriate values. Also initializes the assigned seats to 0.		   *
 ***************************************************************************/
Course::Course(string nm, int maxSeats, long DepID, long taughtBy)
{
	CRN = nextCRN++;
	maxAvailableSeats = maxSeats;
	name = nm;
	departID = DepID;
	isTaughtBy = taughtBy;
	assignedSeats = 0;
}

/***************************************************************************
 * ~Course                                                                 *
 *                                                                         *
 * The destructor                                                          *
 ***************************************************************************/
Course::~Course()
{
}

/***************************************************************************
 * setProfessor                                                            *
 *                                                                         *
 * Takes an ID and assigns it as the new teacher of the course.            *
 ***************************************************************************/
void Course::setProfessor(long teacherId)
{
	isTaughtBy = teacherId;
}

/***************************************************************************
 * getProfessor()                                                          *
 *                                                                         *
 * Returns the teacher of the course (isTaughtBy).                         *
 ***************************************************************************/
long Course::getProfessor()
{
	return isTaughtBy;
}

/***************************************************************************
 * getCRN                                                                  *
 *                                                                         *
 * Returns the Course Registration Number (the id of the course).          *
 ***************************************************************************/
long Course::getCRN()
{
	return CRN;
}

/***************************************************************************
 * getAssignedSeats                                                        *
 *                                                                         *
 * Returns the number of students taking the course.					   *
 ***************************************************************************/
long Course::getAssignedSeats()
{
	return assignedSeats;
}
/***************************************************************************
 * getName                                                                 *
 *                                                                         *
 * Returns the name of the course.                                         *
 ***************************************************************************/
string Course::getName()
{
	return name;
}

/***************************************************************************
 * getDepartID                                                             *
 *                                                                         *
 * Returns the id of the department that this course is a part of.         *
 ***************************************************************************/
long Course::getDepartID()
{
	return departID;
}

/***************************************************************************
 * Operator++                                                              *
 *                                                                         *
 * Overloading the post ++ operator as part of the class. The purpose is to*
 * increment the value of assignedSeats, which holds the number of people  *
 * registered for the course. If assignedSeats >= maximum, it displays an  *
 * error message.														   *
 ***************************************************************************/
Course Course::operator++(int dummy)
{
	if(assignedSeats < maxAvailableSeats)
		assignedSeats++;
	else
		cout << "[Error] This class is full!" << endl;
	
	return *this;
}

/***************************************************************************
 * Operator--                                                              *
 *                                                                         *
 * Overloading the post -- operator as part of the class. The purpose is to*
 * decrement the value of assignedSeats. If assignedSeats = 0, it displays *
 * an error message.													   *
 ***************************************************************************/
Course Course::operator--(int dummy)
{
	if(assignedSeats > 0)
		assignedSeats--;
	else
		cout << "[Error] This class is empty!" << endl;
	
	return *this;
}

/***************************************************************************
 * isFull                                                                  *
 *                                                                         *
 * Returns true if the course is full (assignedSeats is equal or over max).*
 * Otherwise it returns false.                                             *
 ***************************************************************************/
bool Course::isFull()
{
	return assignedSeats >= maxAvailableSeats;
}

/***************************************************************************
 * operator<<                                                              *
 *                                                                         *
 * Defines the output of cout << Course. Displays the name of the Course   *
 * and then the CRN in parentheses. 					                   *
 ***************************************************************************/
ostream& operator<< (ostream& os, const Course& C)
{
	os << C.name << " (" << C.CRN << ")";
	return os;
}
#endif

